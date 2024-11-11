// ListLinked.cpp
#ifndef LISTLINKED_CPP
#define LISTLINKED_CPP

#include "ListLinked.h"

template <typename T>
ListLinked<T>::ListLinked() : head(nullptr), count(0) {}

template <typename T>
ListLinked<T>::~ListLinked() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void ListLinked<T>::insert(int pos, T e) {
    if (pos < 0 || pos > count) throw std::out_of_range("Índice fuera de rango");
    Node<T>* newNode = new Node<T>(e);
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node<T>* current = head;
        for (int i = 0; i < pos - 1; ++i) current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }
    ++count;
}

template <typename T>
void ListLinked<T>::append(T e) {
    insert(count, e);
}

template <typename T>
void ListLinked<T>::prepend(T e) {
    insert(0, e);
}

template <typename T>
T ListLinked<T>::remove(int pos) {
    if (pos < 0 || pos >= count) throw std::out_of_range("Índice fuera de rango");
    Node<T>* toDelete;
    T removedElement;
    if (pos == 0) {
        toDelete = head;
        head = head->next;
    } else {
        Node<T>* current = head;
        for (int i = 0; i < pos - 1; ++i) current = current->next;
        toDelete = current->next;
        current->next = toDelete->next;
    }
    removedElement = toDelete->data;
    delete toDelete;
    --count;
    return removedElement;
}

template <typename T>
T ListLinked<T>::get(int pos) {
    if (pos < 0 || pos >= count) throw std::out_of_range("Índice fuera de rango");
    Node<T>* current = head;
    for (int i = 0; i < pos; ++i) current = current->next;
    return current->data;
}

template <typename T>
int ListLinked<T>::search(T e) {
    Node<T>* current = head;
    int index = 0;
    while (current != nullptr) {
        if (current->data == e) return index;
        current = current->next;
        ++index;
    }
    return -1;
}

template <typename T>
bool ListLinked<T>::empty() {
    return count == 0;
}

template <typename T>
int ListLinked<T>::size() {
    return count;
}

#endif // LISTLINKED_CPP

