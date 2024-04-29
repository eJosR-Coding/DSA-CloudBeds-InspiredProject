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
    int getTamano() const {
        return longitud;
    }
    T obtener(int indice) const {
        if (indice < 0 || indice >= longitud) {
            throw out_of_range("Índice fuera de rango");
        }
        Nodo<T>* actual = inicio;
        for (int i = 0; i < indice; ++i) {
            actual = actual->siguiente;
        }
        return actual->valor;
    }

    void mostrar() const {
        Nodo<T>* actual = inicio;
        while (actual != NULL) {
            cout << actual->valor->toString() << " -> ";
            actual = actual->siguiente;
        }
        cout << "NULL\n";
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
    Nodo<T>* getInicio() const {
        return inicio;
    }
    void ordenarByIntercambio() {
        Nodo<T>* nodo_i = inicio;
        while (nodo_i != NULL) {
            Nodo<T>* nodo_k = nodo_i->siguiente;
            while (nodo_k != NULL) {
                // Verificar si los punteros son válidos antes de hacer la comparación
                if (nodo_i->valor != NULL && nodo_k->valor != NULL) {
                    // Comparar los nombres de los usuarios
                    Usuario* usuario_i = dynamic_cast<Usuario*>(nodo_i->valor);
                    Usuario* usuario_k = dynamic_cast<Usuario*>(nodo_k->valor);
                    if (usuario_i && usuario_k && usuario_i->getNombre() > usuario_k->getNombre()) {
                        // Intercambiar los valores de los nodos
                        T temp = nodo_i->valor;
                        nodo_i->valor = nodo_k->valor;
                        nodo_k->valor = temp;
                    }
                }
                nodo_k = nodo_k->siguiente;
            }
            nodo_i = nodo_i->siguiente;
        }
    }


};

#endif
