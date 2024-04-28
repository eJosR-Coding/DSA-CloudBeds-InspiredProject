#pragma once
#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include "Dependencies.h"

class Cliente : public Usuario {
private:
    string nombreCompleto;
    int edad;
    string habitacion;
    string tipoAlojamiento;
    string lugar;
    string promocion;

public:
    Cliente(int id, string nombreCompleto, int edad, string habitacion, string tipoAlojamiento, string lugar, string promocion)
        : Usuario(id, nombreCompleto, "N/A"), 
        nombreCompleto(nombreCompleto),
        edad(edad),
        habitacion(habitacion),
        tipoAlojamiento(tipoAlojamiento),
        lugar(lugar),
        promocion(promocion) {}

    string toString() const override {
        ostringstream ss;
        ss << "ID: " << id << endl;
        ss << "Nombre Completo: " << nombreCompleto << endl;
        ss << "Edad: " << edad << endl;
        ss << "Habitación: " << habitacion << endl;
        ss << "Tipo Alojamiento: " << tipoAlojamiento << endl;
        ss << "Lugar: " << lugar << endl;
        ss << "Promoción: " << promocion << endl;
        return ss.str();
    }

    string getNombreCompleto() const { return nombreCompleto; }
    void setNombreCompleto(const string& nombreCompleto) { this->nombreCompleto = nombreCompleto; }

    int getEdad() const { return edad; }
    void setEdad(int edad) { this->edad = edad; }

    string getHabitacion() const { return habitacion; }
    void setHabitacion(const string& habitacion) { this->habitacion = habitacion; }

    string getTipoAlojamiento() const { return tipoAlojamiento; }
    void setTipoAlojamiento(const string& tipoAlojamiento) { this->tipoAlojamiento = tipoAlojamiento; }

    string getLugar() const { return lugar; }
    void setLugar(const string& lugar) { this->lugar = lugar; }

    string getPromocion() const { return promocion; }
    void setPromocion(const string& promocion) { this->promocion = promocion; }
};

#endif
