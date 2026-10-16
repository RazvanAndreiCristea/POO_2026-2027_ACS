
#include "Farmacie.h"

Farmacie::Farmacie()
{
    numarAngajati = 0;
    profitAnual = 0.0f;
    anInfiintare = 2000;
}

Farmacie::Farmacie(const int numarAngajati)
{
    anInfiintare = 2000;
    profitAnual = 0.0f;
    this->numarAngajati = (numarAngajati >= 0) ? numarAngajati : 0;
}

Farmacie::Farmacie(const int anInfiintare, const int numarAngajati, const float profitAnual)
{
    this->anInfiintare = (anInfiintare > 0) ? anInfiintare : 2000;
    this->numarAngajati = (numarAngajati >= 0) ? numarAngajati : 0;
    this->profitAnual = (profitAnual >= 0.0f) ? profitAnual : 0.0f;
}

int Farmacie::getAnInfiintare() const
{
    return anInfiintare;
}

int Farmacie::getNumarAngajati() const
{
    return numarAngajati;
}

float Farmacie::getProfitAnual() const
{
    return profitAnual;
}

void Farmacie::setAnInfiintare(const int anInfiintare)
{
    if (anInfiintare <= 0)
    {
        return;
    }

    this->anInfiintare = anInfiintare;
}

void Farmacie::setNumarAngajati(const int numarAngajati)
{
    if (numarAngajati < 0)
    {
        return;
    }

    this->numarAngajati = numarAngajati;
}

void Farmacie::setProfitAnual(const float profitAnual)
{
    if (profitAnual < 0.0f)
    {
        return;
    }

    this->profitAnual = profitAnual;
}