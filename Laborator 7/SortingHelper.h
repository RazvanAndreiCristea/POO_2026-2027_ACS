#pragma once
#include "Roomba.h"

namespace SortingHelper
{
    void interschimbare(Roomba& r1, Roomba& r2);
    void sortareRoombas(Roomba*& roombas, const int& dimensiune);
    void afisareRoombas(const Roomba* const& roombas, const int& dimensiune);
}