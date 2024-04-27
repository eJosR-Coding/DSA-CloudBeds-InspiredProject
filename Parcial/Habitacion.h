#pragma once
#ifndef HABITACION_H
#define HABITACION_H

#include "Dependencies.h"

class Habitacion {
private:
    int numero;
    string tipo;
    double precioPorNoche;
    bool disponible;

public:
    Habitacion(int numero, string tipo, double precioPorNoche, bool disponible)
        : numero(numero), tipo(tipo), precioPorNoche(precioPorNoche), disponible(disponible) {}

    void actualizarDisponibilidad(bool disponibilidad);
    void mostrarInformacion() const;
};

#endif

