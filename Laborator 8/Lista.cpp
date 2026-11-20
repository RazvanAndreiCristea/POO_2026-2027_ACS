#include "Lista.h"

template<typename T>
Nod<T>::Nod(const T& info, Nod<T>* next, Nod<T>* prev)
{
    this->info = info;
    this->next = next;
    this->prev = prev;
}

template<typename T>
Lista<T>::Lista()
{
    size = 0;
    first = nullptr;
    last = nullptr;
}

template<typename T>
Lista<T>::~Lista()
{
    while (first != nullptr)
    {
        Nod<T>* aux = first;
        first = first->next;
        delete aux;
    }

    size = 0;
    last = nullptr;
}

template<typename T>
void Lista<T>::popBack()
{
    if (isEmpty())
    {
        return;
    }

    if (first == last)
    {
        delete first;
        first = last = nullptr;

        size = 0;
        return;
    }

    Nod<T>* nodDeSters = last;

    last = last->prev;
    last->next = nullptr;
    delete nodDeSters;
    size--;
}

template<typename T>
void Lista<T>::popFront()
{
    if (isEmpty())
    {
        return;
    }

    if (first == last)
    {
        delete first;
        first = last = nullptr;

        size = 0;
        return;
    }

    Nod<T>* nodDeSters = first;

    first = first->next;
    first->prev = nullptr;
    delete nodDeSters;
    size--;
}

template<typename T>
void Lista<T>::pushBack(const T& info)
{
    if (isEmpty())
    {
        first = last = new Nod<T>(info);
        size++;
        return;
    }

    Nod<T>* noulNod = new Nod<T>(info);

    noulNod->prev = last;
    last->next = noulNod;
    last = noulNod;

    size++;
}

template<typename T>
void Lista<T>::pushFront(const T& info)
{
    if (isEmpty())
    {
        first = last = new Nod<T>(info);
        size++;
        return;
    }

    Nod<T>* noulNod = new Nod<T>(info);

    noulNod->next = first;
    first->prev = noulNod;
    first = noulNod;

    size++;
}

template<typename T>
int Lista<T>::getSize() const
{
    return size;
}

template<typename T>
T* Lista<T>::toVector() const
{
    if (size <= 0 || isEmpty())
    {
        return nullptr;
    }

    int index = 0;
    Nod<T>* aux = first;
    T* rezultat = new T[size];

    while (aux != nullptr && index < size)
    {
        rezultat[index++] = aux->info;
        aux = aux->next;
    }

    return rezultat;
}

template<typename T>
bool Lista<T>::isEmpty() const
{
    return first == nullptr && last == nullptr;
}

template<typename T>
void Lista<T>::afisare(std::ostream& out) const
{
    if (isEmpty())
    {
        out << "Lista este goala\n\n";
        return;
    }

    const Nod<T>* aux = first;

    while (aux != nullptr)
    {
        out << aux->info << '\n';
        aux = aux->next;
    }
}

template<typename T>
void Lista<T>::afisareInvers(std::ostream& out) const
{
    if (isEmpty())
    {
        out << "Lista este goala\n\n";
        return;
    }

    const Nod<T>* aux = last;

    while (aux != nullptr)
    {
        out << aux->info << '\n';
        aux = aux->prev;
    }
}

template<typename T>
void testareLista(const T& valoare1, const T& valoare2)
{
    Lista<T> lista;

    std::cout << "Lista este goala: " << lista.isEmpty() << '\n';

    lista.pushBack(valoare1);
    lista.pushFront(valoare2);

    std::cout << "Dimensiune: " << lista.getSize() << '\n';

    lista.afisare(std::cout);
    lista.afisareInvers(std::cout);

    T* vector = lista.toVector();

    delete[] vector;

    lista.popBack();
    lista.popFront();

    std::cout << "Lista este goala: " << lista.isEmpty() << '\n';
}

void testareTemplate()
{
    testareLista<int>(10, 20);
    testareLista<float>(10.5f, 20.75f);
    testareLista<NrComplex>(NrComplex(3.0, 4.0), NrComplex(5.0, 12.0));
}