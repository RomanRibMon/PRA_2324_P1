// ListArray.h
#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"
#include <stdexcept>

template <typename T>
class ListArray : public List<T> {
private:
    T* data;         // Puntero al array dinámico
    int capacity;    // Capacidad actual del array
    int count;       // Número actual de elementos en la lista

    void resize();   // Método privado para redimensionar el array

public:
    ListArray();                // Constructor
    ~ListArray();               // Destructor

    void insert(int pos, T e);
    void append(T e);
    void prepend(T e);
    T remove(int pos);
    T get(int pos);
    int search(T e);
    bool empty();
    int size();
};

#include "ListArray.cpp" // Incluimos la implementación del template

#endif // LISTARRAY_H

