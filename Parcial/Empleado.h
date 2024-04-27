#pragma once
#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Usuario.h"
#include "Dependencies.h"

class Empleado : public Usuario {
private:
    string departamento;

public:
    Empleado(int id, string nombreUsuario, string contrase�a, string departamento)
        : Usuario(id, nombreUsuario, contrase�a), departamento(departamento) {}

    string toString() const override {
        ostringstream ss;
        ss << Usuario::toString() << ", Departamento: " << departamento;
        return ss.str();
    }
};

#endif
