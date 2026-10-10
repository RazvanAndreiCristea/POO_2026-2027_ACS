#include "Fractie.h"

Fractie adunareFractii(const Fractie& f1, const Fractie& f2)
{
    Fractie rezultat;

    rezultat.numarator = f1.numarator * f2.numitor + f2.numarator * f1.numitor;
    rezultat.numitor = f1.numitor * f2.numitor;

    return rezultat;
}

Fractie scadereFractii(const Fractie& f1, const Fractie& f2)
{
    Fractie rezultat;

    rezultat.numarator = f1.numarator * f2.numitor - f2.numarator * f1.numitor;
    rezultat.numitor = f1.numitor * f2.numitor;

    return rezultat;
}

Fractie inmultireFractii(const Fractie& f1, const Fractie& f2)
{
    Fractie rezultat;

    rezultat.numarator = f1.numarator * f2.numarator;
    rezultat.numitor = f1.numitor * f2.numitor;

    return rezultat;
}

Fractie impartireFractii(const Fractie& f1, const Fractie& f2)
{
    Fractie rezultat;

    rezultat.numarator = f1.numarator * f2.numitor;
    rezultat.numitor = f1.numitor * f2.numarator;

    return rezultat;
}

void afisareFractie(const Fractie& f)
{
    std::cout << f.numarator << "/" << f.numitor;
}

void interschimbareFractii(Fractie& f1, Fractie& f2)
{
    Fractie aux = f1;
    f1 = f2;
    f2 = aux;
}

void sortareFractii(Fractie*& fractii, const int& dimensiune)
{
    for (int i = 0; i < dimensiune - 1; i++)
    {
        for (int j = i + 1; j < dimensiune; j++)
        {
            double valoare1 = fractii[i].numarator / fractii[i].numitor;
            double valoare2 = fractii[j].numarator / fractii[j].numitor;

            if (valoare1 > valoare2)
            {
                interschimbareFractii(fractii[i], fractii[j]);
            }
        }
    }
}

void afisareFractii(const Fractie* const& fractii, const int& dimensiune)
{
    for (int i = 0; i < dimensiune; i++)
    {
        afisareFractie(fractii[i]);

        if (i < dimensiune - 1)
        {
            std::cout << ", ";
        }
    }

    std::cout << '\n';
}