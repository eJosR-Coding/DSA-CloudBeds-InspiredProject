#pragma once
#ifndef USUARIO_H
#define USUARIO_H

#include "Dependencies.h"

class Usuario {
protected:
    int id;
    string nombreUsuario;
    string contraseņa;

public:
    Usuario(int id, string nombreUsuario, string contraseņa)
        : id(id), nombreUsuario(nombreUsuario), contraseņa(contraseņa) {}

    virtual string toString() const {
        ostringstream ss;
        ss << "Usuario(ID: " << id << ", Usuario: " << nombreUsuario << ")";
        return ss.str();
    }

    virtual ~Usuario() {}
};

#endif
