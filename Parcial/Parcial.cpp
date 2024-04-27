#include "pch.h"
#include "Lista.h"
#include "Cliente.h"
#include "Empleado.h"

using namespace System;
using namespace std;

void mostrarMenu() {
    cout << "\n=== Men� Cloudbeds ===\n";
    cout << "1. Registrar Cliente\n";
    cout << "2. Registrar Empleado\n";
    cout << "3. Mostrar Usuarios\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opci�n: ";
}

int main()
{
    Lista<Usuario*> listaUsuarios;
    int opcion = 0;
    int id = 1; // ID autom�tico para simplificar la creaci�n de usuarios
    do {
        mostrarMenu();
        std::cin >> opcion;
        std::string nombreUsuario, contrase�a, departamento, email;

        switch (opcion) {
        case 1: {  // Registrar Cliente
            std::cout << "Ingrese nombre de usuario: ";
            std::cin >> nombreUsuario;
            std::cout << "Ingrese contrase�a: ";
            std::cin >> contrase�a;
            std::cout << "Ingrese email: ";
            std::cin >> email;
            Cliente* nuevoCliente = new Cliente(id++, nombreUsuario, contrase�a, email);
            listaUsuarios.insertarFinal(nuevoCliente);
            std::cout << "Cliente registrado con �xito.\n";
            break;
        }
        case 2: {  // Registrar Empleado
            std::cout << "Ingrese nombre de usuario: ";
            std::cin >> nombreUsuario;
            std::cout << "Ingrese contrase�a: ";
            std::cin >> contrase�a;
            std::cout << "Ingrese departamento: ";
            std::cin >> departamento;
            Empleado* nuevoEmpleado = new Empleado(id++, nombreUsuario, contrase�a, departamento);
            listaUsuarios.insertarFinal(nuevoEmpleado);
            std::cout << "Empleado registrado con �xito.\n";
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
            std::cout << "Opci�n no v�lida. Por favor intente nuevamente.\n";
        }
    } while (opcion != 4);

    return 0;
}
