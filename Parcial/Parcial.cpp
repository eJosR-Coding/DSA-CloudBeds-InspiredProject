#include "pch.h"
#include "Lista.h"
#include "Cliente.h"
#include "Empleado.h"

using namespace System;
using namespace std;

void mostrarMenu() {
    cout << "\n=== Menú Cloudbeds ===\n";
    cout << "1. Registrar Cliente\n";
    cout << "2. Registrar Empleado\n";
    cout << "3. Mostrar Usuarios\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opción: ";
}

int main()
{
    Lista<Usuario*> listaUsuarios;
    int opcion = 0;
    int id = 1; // ID automático para simplificar la creación de usuarios
    do {
        mostrarMenu();
        std::cin >> opcion;
        std::string nombreUsuario, contraseña, departamento, email;

        switch (opcion) {
        case 1: {  // Registrar Cliente
            std::cout << "Ingrese nombre de usuario: ";
            std::cin >> nombreUsuario;
            std::cout << "Ingrese contraseña: ";
            std::cin >> contraseña;
            std::cout << "Ingrese email: ";
            std::cin >> email;
            Cliente* nuevoCliente = new Cliente(id++, nombreUsuario, contraseña, email);
            listaUsuarios.insertarFinal(nuevoCliente);
            std::cout << "Cliente registrado con éxito.\n";
            break;
        }
        case 2: {  // Registrar Empleado
            std::cout << "Ingrese nombre de usuario: ";
            std::cin >> nombreUsuario;
            std::cout << "Ingrese contraseña: ";
            std::cin >> contraseña;
            std::cout << "Ingrese departamento: ";
            std::cin >> departamento;
            Empleado* nuevoEmpleado = new Empleado(id++, nombreUsuario, contraseña, departamento);
            listaUsuarios.insertarFinal(nuevoEmpleado);
            std::cout << "Empleado registrado con éxito.\n";
            break;
        }
        case 3: {  // Mostrar Usuarios
            std::cout << "Usuarios registrados:\n";
            listaUsuarios.mostrar();
            break;
        }
        case 4:  // Salir
            std::cout << "Saliendo del sistema.\n";
            break;
        default:
            std::cout << "Opción no válida. Por favor intente nuevamente.\n";
        }
    } while (opcion != 4);

    return 0;
}
