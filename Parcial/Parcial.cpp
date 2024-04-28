#include "pch.h"
#include "Lista.h"
#include "Cliente.h"
#include "Invetario.h"
#include "Empleado.h"
using namespace System;
using namespace std;

void mostrarMenu() {
    cout << "\n========================================\n";
    cout << "===          Menu Cloudbeds          ===\n";
    cout << "========================================\n\n";
    cout << "1. Registrar Cliente\n";
    cout << "2. Mostrar Usuarios\n";
    cout << "3. Salir\n";
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
    }

    if (cliente.getPromocion() == "Descuento del 10%") {
        total *= 0.9;
    }
    else if (cliente.getPromocion() == "Descuento del 20%") {
        total *= 0.8;
    }

    // Verificar si el cliente desea añadir jabón, champú y toalla
    char deseaExtras;
    cout << "¿Desea añadir jabón, champú y toalla? (s/n): ";
    cin >> deseaExtras;
    if (deseaExtras == 's' || deseaExtras == 'S') {
        total += 15; // Agregar $15 adicionales por los extras
    }

    cout << "Precio Alojamiento: $" << total << endl;
    cout << "Total: $" << total << endl;
}



int main() {

    Lista<Usuario*> listaUsuarios;
    int opcion = 0;
    int id = 1; // ID automático para simplificar la creación de usuarios

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

            cout << "Seleccione el tipo de alojamiento: ";
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
        case 2: {  // Mostrar Usuarios
            cout << "Usuarios registrados:\n";
            listaUsuarios.mostrar();
            break;
        }
        case 3:  // Salir
            cout << "Saliendo del sistema.\n";
            break;
        default:
            cout << "Opción no válida. Por favor intente nuevamente.\n";
        }
    } while (opcion != 3);

    return 0;
}