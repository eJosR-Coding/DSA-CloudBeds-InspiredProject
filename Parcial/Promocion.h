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

    void aplicarDescuento(double& precio);
    void mostrarInformacion() const;
};

#endif

