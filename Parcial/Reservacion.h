#pragma once
#ifndef RESERVACION_H
#define RESERVACION_H

#include "Dependencies.h"

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

    void mostrarDetalles() const;
};

#endif
