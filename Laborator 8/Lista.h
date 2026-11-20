#pragma once
#include "NrComplex.h"

template<typename T>
class Lista;

template<typename T>
class Nod
{
    T info;
    Nod* next;
    Nod* prev;

public:

    friend class Lista<T>;
    Nod(const T& info, Nod* next = nullptr, Nod* prev = nullptr);
};

template<typename T>
class Lista
{
    int size;
    Nod<T>* first;
    Nod<T>* last;

public:

    Lista();
    ~Lista();

    void popBack();
    void popFront();

    void pushBack(const T& info);
    void pushFront(const T& info);

    int getSize() const;
    T* toVector() const;
    bool isEmpty() const;

    void afisare(std::ostream& out) const;
    void afisareInvers(std::ostream& out) const;
};