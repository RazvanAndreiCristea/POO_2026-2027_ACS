#include "SortingHelper.h"

void SortingHelper::interschimbare(Roomba& r1, Roomba& r2)
{
    Roomba temporar = r1;
    r1 = r2;
    r2 = temporar;
}

void SortingHelper::sortareRoombas(Roomba*& roombas, const int& dimensiune)
{
    if (roombas == nullptr || dimensiune <= 0)
    {
        return;
    }

    for (int i = 0; i < dimensiune - 1; i++)
    {
        for (int j = i + 1; j < dimensiune; j++)
        {
            if (roombas[i] > roombas[j])
            {
                interschimbare(roombas[i], roombas[j]);
            }
        }
    }
}

void SortingHelper::afisareRoombas(const Roomba* const& roombas, const int& dimensiune)
{
    if (roombas == nullptr || dimensiune <= 0)
    {
        return;
    }

    for (int i = 0; i < dimensiune; i++)
    {
        std::cout << roombas[i];
    }
}