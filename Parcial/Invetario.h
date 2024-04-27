#pragma once
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Dependencies.h"

class Inventario {
private:
    int id;
    string item;
    int cantidad;

public:
    Inventario(int id, string item, int cantidad)
        : id(id), item(item), cantidad(cantidad) {}

    void actualizarCantidad(int cambio);
    void mostrarInventario() const;
};

#endif

