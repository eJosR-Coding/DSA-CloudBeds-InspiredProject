#pragma once
#ifndef PROMOCION_H
#define PROMOCION_H

#include "Dependencies.h"

class Promocion {
private:
    int id;
    string descripcion;
    double descuento;  // Porcentaje de descuento

public:
    Promocion(int id, string descripcion, double descuento)
        : id(id), descripcion(descripcion), descuento(descuento) {}
    static float aplicarDescuento(float total) {
        return total * 0.8; // Se aplica un descuento del 20%
    }
    void mostrarInformacion() const;
};

#endif