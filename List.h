// List.h
#ifndef LIST_H
#define LIST_H

#include <ostream>

template <typename T>
class List {
public:
    void insert(int pos, T e) { /* Método no implementado */ }
    void append(T e) { /* Método no implementado */ }
    void prepend(T e) { /* Método no implementado */ }
    T remove(int pos) { /* Método no implementado */ return T(); }
    T get(int pos) { /* Método no implementado */ return T(); }
    int search(T e) { /* Método no implementado */ return -1; }
    bool empty() { return true; }
    int size() { return 0; }
};

#endif // LIST_H

