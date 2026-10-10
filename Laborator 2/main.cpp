#include "Fractie.h"

int main()
{
    Fractie f1{ 2, 1 }; // 1/2
    Fractie f2{ 3, 2 }; // 2/3

    std::cout << "f1 = ";
    afisareFractie(f1);
    std::cout << '\n';

    std::cout << "f2 = ";
    afisareFractie(f2);
    std::cout << "\n\n";

    std::cout << "Adunare: ";
    afisareFractie(adunareFractii(f1, f2));
    std::cout << '\n';

    std::cout << "Scadere: ";
    afisareFractie(scadereFractii(f1, f2));
    std::cout << '\n';

    std::cout << "Inmultire: ";
    afisareFractie(inmultireFractii(f1, f2));
    std::cout << '\n';

    std::cout << "Impartire: ";
    afisareFractie(impartireFractii(f1, f2));
    std::cout << '\n';

    std::cout << "\nInainte de interschimbare: ";

    afisareFractie(f1);
    std::cout << ", ";

    afisareFractie(f2);
    std::cout << '\n';

    interschimbareFractii(f1, f2);

    std::cout << "Dupa interschimbare: ";

    afisareFractie(f1);
    std::cout << ", ";

    afisareFractie(f2);
    std::cout << '\n';

    const int dimensiune = 5;
    Fractie* fractii = new Fractie[dimensiune]
    {
        {2, 1},   // 1/2
        {4, 3},   // 3/4
        {5, -2},  // -2/5
        {3, 5},   // 5/3
        {7, 1}    // 1/7
    };

    std::cout << "\nVector initial: ";

    afisareFractii(fractii, dimensiune);
    sortareFractii(fractii, dimensiune);

    std::cout << "Vector sortat: ";
    afisareFractii(fractii, dimensiune);

    delete[] fractii;
    return 0;
}