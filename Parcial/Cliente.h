#pragma once
#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include "Dependencies.h"

class Cliente : public Usuario {
private:
    string email;

public:
    Cliente(int id, string nombreUsuario, string contrase�a, string email)
        : Usuario(id, nombreUsuario, contrase�a), email(email) {}

    string toString() const override {
        ostringstream ss;
        ss << Usuario::toString() << ", Email: " << email;
        return ss.str();
    }
};

#endif
