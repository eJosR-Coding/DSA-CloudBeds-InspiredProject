#pragma once
#ifndef USUARIO_H
#define USUARIO_H

#include "Dependencies.h"

class Usuario {
protected:
    int id;
    string nombreUsuario;
    string contraseña;

public:
    Usuario(int id, string nombreUsuario, string contraseña)
        : id(id), nombreUsuario(nombreUsuario), contraseña(contraseña) {}

    virtual string toString() const {
        ostringstream ss;
        ss << "Usuario(ID: " << id << ", Usuario: " << nombreUsuario << ")";
        return ss.str();
    }

    virtual ~Usuario() {}
};

#endif
