#pragma once

#ifndef ARTICULO_H
#define ARTICULO_H

#include <string>

#include "Dependencies.h"
#include <vector>
class Articulo {
private:
    string nombre;
    double precio;
    int cantidad;

public:
    Articulo(string nombre, double precio, int cantidad)
        : nombre(nombre), precio(precio), cantidad(cantidad) {}

    string getNombre() const { return nombre; }
    void setNombre(string nombre) { this->nombre = nombre; }

    double getPrecio() const { return precio; }
    void setPrecio(double precio) { this->precio = precio; }

    int getCantidad() const { return cantidad; }
    void setCantidad(int cantidad) { this->cantidad = cantidad; }
};


#endif
#ifndef INVENTARIO_H
#define INVENTARIO_H


class Inventario {
private:
    std::vector<Articulo> articulos;

public:
    void agregarArticulo(const Articulo& articulo) {
        articulos.push_back(articulo);
    }

    std::vector<Articulo> getArticulos() const {
        return articulos;
    }
};

#endif

