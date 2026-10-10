#pragma once
#include <iostream>

struct Fractie
{
    double numitor;
    double numarator;
};

Fractie adunareFractii(const Fractie& f1, const Fractie& f2);

Fractie scadereFractii(const Fractie& f1, const Fractie& f2);

Fractie inmultireFractii(const Fractie& f1, const Fractie& f2);

Fractie impartireFractii(const Fractie& f1, const Fractie& f2);

void afisareFractie(const Fractie& f);

void interschimbareFractii(Fractie& f1, Fractie& f2);

void sortareFractii(Fractie*& fractii, const int& dimensiune);

void afisareFractii(const Fractie* const& fractii, const int& dimensiune);