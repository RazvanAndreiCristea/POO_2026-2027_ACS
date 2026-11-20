#include "SortingHelper.h"

template<typename T>
void interschimbare(T& a, T& b)
{
    T aux = a;
    a = b;
    b = aux;
}

template<typename T>
void sortareVector(T*& vector, const int& dimensiune)
{
    if (vector == nullptr || dimensiune <= 0)
    {
        return;
    }

    for (int i = 0; i < dimensiune - 1; i++)
    {
        for (int j = i + 1; j < dimensiune; j++)
        {
            if (vector[i] < vector[j])
            {
                interschimbare(vector[i], vector[j]);
            }
        }
    }
}

template<typename T>
void afisareVector(const T* const& vector, const int& dimensiune)
{
    if (vector == nullptr || dimensiune <= 0)
    {
        return;
    }

    for (int i = 0; i < dimensiune; i++)
    {
        std::cout << vector[i] << "    ";
    }

    std::cout << '\n';
}

template<typename T>
void testareSortingHelper(const T& valoare1, const T& valoare2, const T& valoare3)
{
    T a = valoare1;
    T b = valoare2;

    interschimbare(a, b);
    std::cout << "Dupa interschimbare: " << a << " " << b << '\n';

    int dimensiune = 3;
    T* vector = new T[dimensiune]{ valoare1, valoare2, valoare3 };

    sortareVector(vector, dimensiune);

    const T* vectorConst = vector;
    afisareVector(vectorConst, dimensiune);

    delete[] vector;
}

void testareTemplateSortingHelper()
{
    testareSortingHelper<int>(10, 30, 20);
    testareSortingHelper<float>(10.5f, 30.75f, 20.25f);
    testareSortingHelper<NrComplex>(NrComplex(3.0, 4.0), NrComplex(5.0, 12.0), NrComplex(8.0, 15.0));
}