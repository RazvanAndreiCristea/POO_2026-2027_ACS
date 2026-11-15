#include "Baterie.h"

Baterie::Baterie()
{
    capacitate = 0.0f;
    nivelIncarcare = 0.0f;
    numarCicluriIncarcare = 0;
}

Baterie::Baterie(const float capacitate, const float nivelIncarcare, const int numarCicluriIncarcare)
{
    this->capacitate = capacitate;
    this->nivelIncarcare = nivelIncarcare;
    this->numarCicluriIncarcare = numarCicluriIncarcare;
}

bool Baterie::operator>(const Baterie& baterie) const
{
    return nivelIncarcare > baterie.nivelIncarcare;
}

std::ostream& operator<<(std::ostream& out, const Baterie& baterie)
{
    out << "Capacitate baterie: " << baterie.capacitate << " mAh\n"
        << "Nivel incarcare: " << baterie.nivelIncarcare << " %\n"
        << "Numar cicluri incarcare: " << baterie.numarCicluriIncarcare << '\n';

    return out;
}