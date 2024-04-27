#pragma once
#ifndef PAGO_H
#define PAGO_H

#include "Dependencies.h"

class Pago {
private:
    int id;
    int facturaId;
    double monto;
    string metodoPago; // Ejemplo: efectivo, tarjeta, transferencia

public:
    Pago(int id, int facturaId, double monto, string metodoPago)
        : id(id), facturaId(facturaId), monto(monto), metodoPago(metodoPago) {}

    void confirmarPago();
    void mostrarDetallesPago() const;
};

#endif

