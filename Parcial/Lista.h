#pragma once
#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include "Dependencies.h"

template<class T>
class Lista {
private:
    Nodo<T>* inicio;
    int longitud;

public:
    Lista() : inicio(NULL), longitud(0) {}

    ~Lista() {
        vaciar();
    }

    void insertarInicio(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor, inicio);
        inicio = nuevo;
        longitud++;
    }

    void insertarFinal(T valor) {
        if (inicio == NULL) {
            insertarInicio(valor);
        }
        else {
            Nodo<T>* actual = inicio;
            while (actual->siguiente != NULL) {
                actual = actual->siguiente;
            }
            actual->siguiente = new Nodo<T>(valor);
            longitud++;
        }
    }

    void mostrar() const {
        Nodo<T>* actual = inicio;
        while (actual != NULL) {
            std::cout << actual->valor->toString() << " -> ";
            actual = actual->siguiente;
        }
        std::cout << "NULL\n";
    }

    void vaciar() {
        Nodo<T>* actual = inicio;
        while (actual != NULL) {
            Nodo<T>* temp = actual;
            actual = actual->siguiente;
            delete temp->valor;  // Asumiendo que T es un puntero a objeto
            delete temp;
        }
        inicio = NULL;
        longitud = 0;
    }
};

#endif
