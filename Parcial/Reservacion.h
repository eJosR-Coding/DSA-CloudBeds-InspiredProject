#pragma once
#ifndef RESERVACION_H
#define RESERVACION_H

#include "Dependencies.h"
#include "Lista.h"
#include "Cliente.h"
#include <iostream>
#include <string>
using namespace std;

class Reservacion {
private:
    int id;
    int clienteId;
    int habitacionId;
    string fechaInicio;
    string fechaFin;

public:
    Reservacion(int id, int clienteId, int habitacionId, string fechaInicio, string fechaFin)
        : id(id), clienteId(clienteId), habitacionId(habitacionId), fechaInicio(fechaInicio), fechaFin(fechaFin) {}

    static void mostrarReservaciones(const Lista<Reservacion*>& listaReservaciones) {
        Nodo<Reservacion*>* actual = listaReservaciones.getInicio();
        while (actual != nullptr) {
            actual->valor->mostrarDetalles();
            actual = actual->siguiente;
        }
    }

    void mostrarDetalles() const {
        cout << "ID: " << id << endl;
        cout << "Cliente ID: " << clienteId << endl;
        cout << "Habitación ID: " << habitacionId << endl;
        cout << "Fecha de inicio: " << fechaInicio << endl;
        cout << "Fecha de fin: " << fechaFin << endl;
    }
};

#endif
