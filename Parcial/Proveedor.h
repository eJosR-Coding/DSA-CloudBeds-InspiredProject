#pragma once
#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include "Dependencies.h"

class Proveedor {
private:
    int id;
    string nombre;
    string contacto;

public:
    Proveedor(int id, string nombre, string contacto)
        : id(id), nombre(nombre), contacto(contacto) {}

    void mostrarInformacion() const;
};

#endif

