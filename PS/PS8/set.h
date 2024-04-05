#ifndef SET_H
#define SET_H

#include <iostream>

template <class T>
class Set {
private:
    T* items;
    int size;
    int capacity;

public:
    Set();
    ~Set();
    void add(const T& item);
    int getSize() const;
    T* getArray() const;
};

#include "set.cpp"

#endif // SET_H

