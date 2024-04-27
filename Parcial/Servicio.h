#pragma once
#ifndef SERVICIO_H
#define SERVICIO_H

#include "Dependencies.h"

class Servicio {
private:
    int id;
    string descripcion;
    double costo;

public:
    Servicio(int id, string descripcion, double costo)
        : id(id), descripcion(descripcion), costo(costo) {}

    void mostrarInformacion() const;
};

#endif
