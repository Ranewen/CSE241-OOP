#include "set.h"

template <class T>
Set<T>::Set() {
    size = 0;
    capacity = 10;
    items = new T[capacity];
}

template <class T>
Set<T>::~Set() {
    delete[] items;
}

template <class T>
void Set<T>::add(const T& item) {
    for (int i = 0; i < size; i++) {
        if (items[i] == item) {
            return; // item already exists in the set, do not add it
        }
    }
    if (size == capacity) {
        capacity *= 2;
        T* newItems = new T[capacity];
        for (int i = 0; i < size; i++) {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
    }
    items[size++] = item;
}

template <class T>
int Set<T>::getSize() const {
    return size;
}

template <class T>
T* Set<T>::getArray() const {
    T* newArray = new T[size];
    for (int i = 0; i < size; i++) {
        newArray[i] = items[i];
    }
    return newArray;
}

