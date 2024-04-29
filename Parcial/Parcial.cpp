#include "pch.h"
#include "Lista.h"
#include "Cliente.h"
#include "Invetario.h"
#include "Empleado.h"
#include "Promocion.h"
#include "ServerStatus.h"
#include "Reservacion.h"
#include "Administrador.h"
using namespace System;
using namespace std;

void Reservacion::mostrarDetalles() const {
    cout << "ID: " << id << endl;
    cout << "Cliente ID: " << clienteId << endl;
    cout << "Habitación ID: " << habitacionId << endl;
    cout << "Fecha de inicio: " << fechaInicio << endl;
    cout << "Fecha de fin: " << fechaFin << endl;
}

void mostrarMenu() {
    cout << "\n========================================\n";
    cout << "===          Menu Cloudbeds          ===\n";
    cout << "========================================\n\n";
    cout << "1. Registrar Cliente\n";
    cout << "2. Registrar Empleado\n";
    cout << "3. Mostrar Usuarios\n";
    cout << "7. Salir\n";
    cout << "========================================\n";
    cout << "Seleccione una opcion: ";
}
void generarFactura(const Cliente& cliente, const Inventario& inventario) {
    cout << "\n*Factura*\n";
    cout << "Cliente: " << cliente.getNombreCompleto() << endl;
    cout << "Habitación: " << cliente.getHabitacion() << endl;
    cout << "Tipo Alojamiento: " << cliente.getTipoAlojamiento() << endl;
    cout << "Lugar: " << cliente.getLugar() << endl;
    cout << "Promoción: " << cliente.getPromocion() << endl;

    double total = 0;

    // Calculate accommodation cost based on type
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
        // Handle undefined type (optional)
        cout << "Tipo de alojamiento no reconocido.\n";
        return; // Exit function if type is invalid
    }

    // Apply discount based on promotion
    double descuentoTotal = 0; // Accumulator for total discount applied
    string promocion = cliente.getPromocion();
    if (promocion == "Interbank") {
        descuentoTotal += total * 0.1; // Apply 10% discount
    }
    else if (promocion == "BCP") {
        descuentoTotal += total * 0.15; // Apply 15% discount
    }

    // Apply type-based discount (if applicable)
    if (cliente.getTipoAlojamiento() == "Departamento") {
        descuentoTotal += 2.5; // Apply $2.5 discount for Departamento
    }
    else if (cliente.getTipoAlojamiento() == "Casa de playa") {
        descuentoTotal += 5.0; // Apply $5.0 discount for Casa de playa
    }
    else if (cliente.getTipoAlojamiento() == "Cabaña") {
        descuentoTotal += 7.5; // Apply $7.5 discount for Cabaña
    }

    // Apply accumulated discounts
    total -= descuentoTotal;

    // Verify if the customer wants to add soap, shampoo, and towel
    char deseaExtras;
    cout << "¿Desea añadir jabón, champú y toalla? (s/n): ";
    cin >> deseaExtras;
    if (deseaExtras == 's' || deseaExtras == 'S') {
        total += 15; // Add $15 for extras
    }

    cout << "Precio Alojamiento: $" << total << endl;
    cout << "Total: $" << total << endl;
}


int main() {
    ServerStatus servidor;
    servidor.encender();

    Lista<Reservacion*> listaReservaciones; 

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
            cin.ignore(); // Clear the input buffer
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
            Inventario inventario; // Assuming you have an Inventario object

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
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
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
            generarFactura(*nuevoCliente, inventario);
            break;
        }
        case 2: {  // Registrar Empleado
            system("cls");
            cout << "\n*Registro de Empleado*\n";
            cout << "Ingrese nombre completo: ";
            cin.ignore(); // Clear the input buffer
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
            Inventario inventario; // Assuming you have an Inventario object

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
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            getline(cin, lugartrabajo);

            cout << "Ingrese la contrasena: ";
            string contrasena;
            cin >> contrasena;

            Empleado* nuevoEmpleado =
                new Empleado(id++, nombreCompleto, edad, tipoAlojamiento, lugartrabajo, departamentotrabajo, contrasena);
            listaUsuarios.insertarFinal(nuevoEmpleado);
            cout << "Empleado registrado con éxito.\n";
            break;
            listaUsuarios.mostrar();
            break;
        }
        case 3: {  // Mostrar Usuarios
            cout << "Usuarios registrados:\n";
            listaUsuarios.mostrar();
            cout << "\nOrdenado por intercambio:\n";
            listaUsuarios.ordenarByIntercambio(); 
            listaUsuarios.mostrar(); 
            break;
        }
        case 4: { // Mostrar Reservaciones
            cout << "Reservaciones hasta la fecha: " << endl;
            // Llama a la función mostrarReservaciones() pasando la lista de reservaciones y la lista de clientes
            Reservacion::mostrarReservaciones(listaReservaciones, listaUsuarios);
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