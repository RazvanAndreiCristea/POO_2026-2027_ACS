#include "Lista.h"
#include "SortingHelper.h"

template<typename T>
void testareLista(const T& a, const T& b, const T& c, const T& d)
{
    Lista<T> lista;

    std::cout << "Lista este goala: " << lista.isEmpty() << '\n';

    lista.pushBack(a);
    lista.pushFront(b);

    lista.pushBack(c);
    lista.pushFront(d);

    std::cout << "Dimensiune: " << lista.getSize() << '\n';

    std::cout << "\nAfisare directa\n\n";
    lista.afisare(std::cout);

    std::cout << "\nAfisare inversa\n\n";
    lista.afisareInvers(std::cout);

    int dimensiune = lista.getSize();
    T* vector = lista.toVector();

    sortareVector(vector, dimensiune);

    std::cout << "\nVector sortat descrescator\n\n";
    const T* vectorConst = vector;
    afisareVector(vectorConst, dimensiune);

    delete[] vector;

    lista.popFront();
    lista.popBack();

    std::cout << "\nLista dupa eliminari\n\n";
    lista.afisare(std::cout);

    lista.popBack();

    std::cout << "\nLista este goala: " << lista.isEmpty() << '\n';
}

int main()
{
    std::cout << "========== INT ==========\n\n";

    testareLista<int>(10, 30, 20, 88);

    std::cout << "\n========== FLOAT ==========\n\n";

    testareLista<float>(10.5f, 30.75f, 20.25f, 32.5f);

    std::cout << "\n========== NRCOMPLEX ==========\n\n";

    testareLista<NrComplex>(NrComplex(3.0, 4.0), NrComplex(5.0, 12.0), NrComplex(8.0, 15.0), NrComplex(-4.0, 1.0));

    return 0;
}