#pragma once
#include <iostream>

class Farmacie
{
    int anInfiintare;
    int numarAngajati;
    float profitAnual;

public:

    Farmacie();
    Farmacie(const int numarAngajati);
    Farmacie(const int anInfiintare, const int numarAngajati, const float profitAnual);

    int getAnInfiintare() const;
    int getNumarAngajati() const;
    float getProfitAnual() const;

    void setAnInfiintare(const int anInfiintare);
    void setNumarAngajati(const int numarAngajati);
    void setProfitAnual(const float profitAnual);
};