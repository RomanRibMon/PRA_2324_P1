// ListArray.cpp
#ifndef LISTARRAY_CPP
#define LISTARRAY_CPP

#include "ListArray.h"
#include <algorithm>

template <typename T>
ListArray<T>::ListArray() : capacity(10), count(0) {
    data = new T[capacity];
}

template <typename T>
ListArray<T>::~ListArray() {
    delete[] data;
}

template <typename T>
void ListArray<T>::resize() {
    capacity *= 2;
    T* newData = new T[capacity];
    std::copy(data, data + count, newData);
    delete[] data;
    data = newData;
}

template <typename T>
void ListArray<T>::insert(int pos, T e) {
    if (pos < 0 || pos > count) throw std::out_of_range("Índice fuera de rango");
    if (count == capacity) resize();
    for (int i = count; i > pos; --i) data[i] = data[i - 1];
    data[pos] = e;
    ++count;
}

template <typename T>
void ListArray<T>::append(T e) {
    insert(count, e);
}

template <typename T>
void ListArray<T>::prepend(T e) {
    insert(0, e);
}

template <typename T>
T ListArray<T>::remove(int pos) {
    if (pos < 0 || pos >= count) throw std::out_of_range("Índice fuera de rango");
    T removedElement = data[pos];
    for (int i = pos; i < count - 1; ++i) data[i] = data[i + 1];
    --count;
    return removedElement;
}

template <typename T>
T ListArray<T>::get(int pos) {
    if (pos < 0 || pos >= count) throw std::out_of_range("Índice fuera de rango");
    return data[pos];
}

template <typename T>
int ListArray<T>::search(T e) {
    for (int i = 0; i < count; ++i) if (data[i] == e) return i;
    return -1;
}

template <typename T>
bool ListArray<T>::empty() {
    return count == 0;
}

template <typename T>
int ListArray<T>::size() {
    return count;
}

#endif // LISTARRAY_CPP

