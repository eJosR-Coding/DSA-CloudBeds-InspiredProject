#pragma once
#ifndef FACTURA_H
#define FACTURA_H


#include "Dependencies.h"

class Factura {
private:
    int id;
    int clienteId;
    double total;


public:
    Factura(int id, int clienteId)
        : id(id), clienteId(clienteId), total(0.0) {}
    void agregarDetalle(string detalle);
    void calcularTotal(double monto);
    void imprimirFactura() const;
};

#endif

