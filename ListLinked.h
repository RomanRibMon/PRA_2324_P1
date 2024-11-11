// ListLinked.h
#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "List.h"
#include "Node.h"
#include <stdexcept>

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* head;
    int count;

public:
    ListLinked();    // Constructor
    ~ListLinked();   // Destructor

    void insert(int pos, T e);
    void append(T e);
    void prepend(T e);
    T remove(int pos);
    T get(int pos);
    int search(T e);
    bool empty();
    int size();
};

#include "ListLinked.cpp" // Incluimos la implementación del template

#endif // LISTLINKED_H

