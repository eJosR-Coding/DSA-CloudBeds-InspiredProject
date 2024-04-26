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

    virtual void mostrarInformacion() const;
    virtual ~Usuario() {}
};

#endif
