#ifndef LISTA_H
#define LISTA_H
#include <cstddef>
#include <cassert>
#include <iostream>
#include <fstream>
#include <clocale>
using namespace std;
template <typename T>
class Lista
{
    public:
        Lista();
        void agregar(const T & elemento);
        bool vacia()const;
        bool pertenece(const T & elemento)const;
        void P();
        bool eliminar(int pos);
        virtual ~Lista();



    private:
        struct Nodo
        {
            T elemento;
            Nodo * sig;

        };
        Nodo * l;
        Nodo * Primero();

        void vaciar();
};

#endif // LISTA_H
