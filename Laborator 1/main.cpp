#include "functions.h"

int main()
{
    int dim = 10;
    int vSortat[10] = { 0 };
    int v[10] = { 5, 3, 8, 1, 9, 2, 7, 4, 6, 0 };

    std::cout << "Vector: ";
    afisareVector(v, dim);

    std::cout << "Sortat: ";
    sortareVector(v, dim, vSortat);
    afisareVector(vSortat, dim);

    std::cout << "Vector: ";
    afisareVector(v, dim);

    std::cout << "Maxim: " << maximVector(v, dim) << '\n';
    std::cout << "Minim: " << minimVector(v, dim) << '\n';

    return 0;
}