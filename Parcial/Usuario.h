#ifndef USUARIO_H
#define USUARIO_H

#include "Dependencies.h"

class Usuario {
protected:
    int id;
    string nombreUsuario;
    string contrase�a;

public:
    Usuario(int id, string nombreUsuario, string contrase�a)
        : id(id), nombreUsuario(nombreUsuario), contrase�a(contrase�a) {}

    virtual void mostrarInformacion() const;
    virtual ~Usuario() {}
};

#endif
