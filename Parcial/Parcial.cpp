#include "pch.h"
#include "Lista.h"
#include "Cliente.h"
#include "Invetario.h"
#include "Empleado.h"
#include "Promocion.h"
#include "ServerStatus.h"
#include "Reservacion.h"
#include "Administrador.h"
#include "Pago.h"
#include "Resena.h"

using namespace System;
using namespace std;


void mostrarMenu() {
    cout << "\n========================================\n";
    cout << "===          Menu Cloudbeds          ===\n";
    cout << "========================================\n\n";
    cout << "1. Registrar Cliente\n";
    cout << "2. Registrar Empleado\n";
    cout << "3. Mostrar Usuarios\n";
    cout << "4. Mostrar Reservas hasta la fecha" << endl;
    cout << "5. Resenas" << endl;
    cout << "6. Mostrar ultimo cliente registrado" << endl;
    cout << "7. Salir\n";
    cout << "========================================\n";
    cout << "Seleccione una opcion: ";
}
void AnadirReviews(Nodo<Usuario*>* nodoCliente, Lista<Resena*>& listaReviews) {
    if (nodoCliente == nullptr) {
        return; 
    }

    Usuario* usuario = nodoCliente->valor;
    Cliente* cliente = dynamic_cast<Cliente*>(usuario);
    if (cliente != nullptr) {
        string nombre = cliente->getNombreCompleto();
        string habitacion = cliente->getHabitacion();
        int rating = rand() % 10 + 1;

        Resena* nuevaReview = new Resena(listaReviews.getTamano() + 1, nombre, "Reseña sobre la habitación: " + habitacion, rating);
        listaReviews.insertarFinal(nuevaReview);
    }

    AnadirReviews(nodoCliente->siguiente, listaReviews);
}

void generarFactura(const Cliente& cliente, const Inventario& inventario, int facturaId) {
    cout << "\n*Factura*\n";
    cout << "Cliente: " << cliente.getNombreCompleto() << endl;
    cout << "Habitación: " << cliente.getHabitacion() << endl;
    cout << "Tipo Alojamiento: " << cliente.getTipoAlojamiento() << endl;
    cout << "Lugar: " << cliente.getLugar() << endl;
    cout << "Promoción: " << cliente.getPromocion() << endl;

    double total = 0;

    // Calcular costo del alojamiento basado en el tipo
    if (cliente.getTipoAlojamiento() == "Departamento") {
        total = 25.0;
    }
    else if (cliente.getTipoAlojamiento() == "Casa de playa") {
        total = 50.0;
    }
    else if (cliente.getTipoAlojamiento() == "Cabaña") {
        total = 75.0;
    }
    else {
        cout << "Tipo de alojamiento no reconocido.\n";
        return; // Salir de la función
    }

    // Aplicar descuentos basados en la promoción
    double descuentoTotal = 0;
    string promocion = cliente.getPromocion();
    if (promocion == "Interbank") {
        descuentoTotal += total * 0.1; // 10% de descuento
    }
    else if (promocion == "BCP") {
        descuentoTotal += total * 0.15; // 15% de descuento
    }

    // Descuentos adicionales basados en el tipo de alojamiento
    if (cliente.getTipoAlojamiento() == "Departamento") {
        descuentoTotal += 2.5;
    }
    else if (cliente.getTipoAlojamiento() == "Casa de playa") {
        descuentoTotal += 5.0;
    }
    else if (cliente.getTipoAlojamiento() == "Cabaña") {
        descuentoTotal += 7.5;
    }

    total -= descuentoTotal;

    // Consulta por extras
    char deseaExtras;
    cout << "¿Desea añadir jabón, champú y toalla? (s/n): ";
    cin >> deseaExtras;
    if (deseaExtras == 's' || deseaExtras == 'S') {
        total += 15; 
    }

    cout << "Precio Alojamiento: $" << total << endl;
    cout << "Total: $" << total << endl;

    // Preguntar si se desea pagar ahora
    cout << "¿Desea realizar el pago ahora? (s/n): ";
    char deseaPagar;
    cin >> deseaPagar;

    if (deseaPagar == 's' || deseaPagar == 'S') {
        cout << "Seleccione método de pago: \n1. Efectivo\n2. Tarjeta\n3. Transferencia\n";
        int opcionMetodoPago;
        cin >> opcionMetodoPago;

        string metodoPago;
        switch (opcionMetodoPago) {
        case 1: metodoPago = "Efectivo"; break;
        case 2: metodoPago = "Tarjeta"; break;
        case 3: metodoPago = "Transferencia"; break;
        default: metodoPago = "Desconocido";
        }

        // Crear y confirmar el pago
        Pago nuevoPago(facturaId, facturaId, total, metodoPago);
        nuevoPago.confirmarPago();
    }
}



int main() {
    ServerStatus servidor;
    servidor.encender();

    Lista<Reservacion*> listaReservaciones; 
    Lista<Resena*> listaReviews;
    Lista<Usuario*> listaUsuarios;

    int opcion = 0;
    Administrador admin("admin123");

    // Solicitar inicio de sesión del administrador
    if (!admin.inicioSesion()) {
        std::cout << "Demasiados intentos fallidos. Saliendo del sistema.\n";
        return 1; // Salir del programa si hay demasiados intentos fallidos
    }
    system("cls");
    int id = 1;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1: {  // Registrar Cliente
            system("cls");
            cout << "\n*Registro de Cliente*\n";
            cout << "Ingrese nombre completo: ";
            cin.ignore(); 
            string nombreCompleto;
            getline(cin, nombreCompleto);

            cout << "Ingrese edad: ";
            int edadTemporal;
            cin >> edadTemporal;
            while (edadTemporal <= 0) {
                cout << "Edad inválida. Ingrese nuevamente: ";
                cin >> edadTemporal;
            }
            int edad = edadTemporal;

            // Mostrar lista de lugares disponibles
            Inventario inventario;

            cout << "Ingrese el número de habitación: ";
            string habitacion;
            cin >> habitacion;

            cout << "Seleccione el tipo de alojamiento: " << endl;
            cout << "1. Departamento\n";
            cout << "2. Casa de playa\n";
            cout << "3. Cabaña\n";
            int opcionTipoAlojamiento;
            cin >> opcionTipoAlojamiento;
            while (opcionTipoAlojamiento < 1 || opcionTipoAlojamiento > 3) {
                cout << "Opción inválida. Ingrese nuevamente: ";
                cin >> opcionTipoAlojamiento;
            }
            string tipoAlojamiento;
            switch (opcionTipoAlojamiento) {
            case 1:
                tipoAlojamiento = "Departamento";
                break;
            case 2:
                tipoAlojamiento = "Casa de playa";
                break;
            case 3:
                tipoAlojamiento = "Cabaña";
                break;
            default:
                tipoAlojamiento = "Indefinido";
            }

            cout << "Ingrese nombre del hospedaje: " << endl;
            string lugar;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            getline(cin, lugar);
            cout << "Seleccione la promoción: " << endl;
            cout << "1. Interbank\n";
            cout << "2. BCP\n";
            cout << "3. Sin promoción\n";
            int opcionPromocion;
            cin >> opcionPromocion;
            while (opcionPromocion < 1 || opcionPromocion > 3) {
                cout << "Opción inválida. Ingrese nuevamente: ";
                cin >> opcionPromocion;
            }
            string promocion;
            switch (opcionPromocion) {
            case 1:
                promocion = "Interbank";
                break;
            case 2:
                promocion = "BCP";
                break;
            case 3:
                promocion = "Sin promoción";
                break;
            default:
                promocion = "Indefinida";
            }
            
            Cliente* nuevoCliente =
                new Cliente(id++, nombreCompleto, edad, habitacion, tipoAlojamiento, lugar, promocion);
            listaUsuarios.insertarFinal(nuevoCliente);

            cout << "Cliente registrado con éxito.\n";
            generarFactura(*nuevoCliente, inventario, id);
            // Crear y registrar una reservación
            Reservacion* nuevaReservacion = new Reservacion(nombreCompleto, habitacion);
            listaReservaciones.insertarFinal(nuevaReservacion);

            AnadirReviews(listaUsuarios.getInicio(), listaReviews);

            cout << "Reservación creada con éxito para " << nuevoCliente->getNombreCompleto() << ".\n";
            break;
        }
        case 2: {  // Registrar Empleado
            system("cls");
            cout << "\n*Registro de Empleado*\n";
            cout << "Ingrese nombre completo: ";
            cin.ignore();
            string nombreCompleto;
            getline(cin, nombreCompleto);

            cout << "Ingrese edad: ";
            int edadTemporal;
            cin >> edadTemporal;
            while (edadTemporal <= 0) {
                cout << "Edad inválida. Ingrese nuevamente: ";
                cin >> edadTemporal;
            }
            int edad = edadTemporal;

            // Mostrar lista de lugares disponibles
            Inventario inventario;

            cout << "Seleccione el tipo de alojamiento: " << endl;
            cout << "1. Departamento\n";
            cout << "2. Casa de playa\n";
            cout << "3. Cabaña\n";
            int opcionTipoAlojamiento;
            cin >> opcionTipoAlojamiento;
            while (opcionTipoAlojamiento < 1 || opcionTipoAlojamiento > 3) {
                cout << "Opción inválida. Ingrese nuevamente: ";
                cin >> opcionTipoAlojamiento;
            }
            string tipoAlojamiento;
            switch (opcionTipoAlojamiento) {
            case 1:
                tipoAlojamiento = "Departamento";
                break;
            case 2:
                tipoAlojamiento = "Casa de playa";
                break;
            case 3:
                tipoAlojamiento = "Cabaña";
                break;
            default:
                tipoAlojamiento = "Indefinido";
            }
            cout << "Ingrese el departamento de trabajo: ";
            cout << "1. Limpieza\n";
            cout << "2. Recepcion\n";
            cout << "3. Servicios\n";
            int opciondepartamentotrabajo;
            cin >> opciondepartamentotrabajo;
            while (opciondepartamentotrabajo < 1 || opciondepartamentotrabajo > 3) {
                cout << "Opción inválida. Ingrese nuevamente: ";
                cin >> opciondepartamentotrabajo;
            }
            string departamentotrabajo;
            switch (opciondepartamentotrabajo) {
            case 1:
                departamentotrabajo = "limpieza";
                break;
            case 2:
                departamentotrabajo = "recepcion";
                break;
            case 3:
                departamentotrabajo = "servicios";
                break;
            default:
                departamentotrabajo = "Indefinido";
            }

            cout << "Ingrese nombre del lugar de trabajo: " << endl;
            string lugartrabajo;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            getline(cin, lugartrabajo);

            cout << "Ingrese la contrasena: ";
            string contrasena;
            cin >> contrasena;

            Empleado* nuevoEmpleado =
                new Empleado(id++, nombreCompleto, edad, tipoAlojamiento, lugartrabajo, departamentotrabajo, contrasena);
            listaUsuarios.insertarFinal(nuevoEmpleado);
            cout << "Empleado registrado con éxito.\n";
            
            system("cls");
            listaUsuarios.mostrar();
            break;
        }
        case 3: {  // Mostrar Usuarios
            system("cls");
            cout << "Usuarios registrados:\n";
            listaUsuarios.mostrar();
            cout << "\nOrdenado por intercambio:\n";
            listaUsuarios.ordenarByIntercambio(); 
            listaUsuarios.mostrar(); 
            break;
        }
        case 4: { // Mostrar Reservaciones
            system("cls");
            cout << "Reservaciones hasta la fecha: \n";
            Reservacion::mostrarReservaciones(listaReservaciones);
            break;
        }
        case 5: {
            system("cls");
            cout << "Resenas hasta la fecha: " << endl;
         
            if (listaReviews.getTamano() > 0) {
                Nodo<Resena*>* nodoActual = listaReviews.getInicio();

                while (nodoActual != nullptr) {
                    nodoActual->valor->show(); // Mostrar detalles de la reseña
                    nodoActual = nodoActual->siguiente;
                }
            }
            else {
                cout << "No hay reseñas disponibles.\n";
            }
            break;

        }
        case 6: { 
            system("cls");
            try {
                
                Usuario* ultimoCliente = listaUsuarios.obtenerUltimoSinEliminar();
                cout << "Último cliente registrado: " << ultimoCliente->toString() << endl;
            }
            catch (const std::runtime_error& e) {
                cout << e.what() << endl;
            }
            break;
        }


        case 7: {  // Salir
            cout << "Saliendo del sistema.\n";
            servidor.apagar();
            break;
        }
        default:
            cout << "Opción no válida. Por favor intente nuevamente.\n";
        }
    } while (opcion != 7);

    return 0;
}