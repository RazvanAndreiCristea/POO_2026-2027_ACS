#include "Roomba.h"

Roomba::Roomba() : Aspirator(), RobotMobil()
{
    model = nullptr;
    suprafataCuratata = 0.0f;
}

Roomba::Roomba(const float putereAspirare, const char* producator, const float capacitateRecipient,
    const int numarSenzori, const char* sistemNavigatie, const float vitezaDeplasare,
    const char* model, const float suprafataCuratata, const Baterie& baterie)
    : Aspirator(putereAspirare, producator, capacitateRecipient), RobotMobil(numarSenzori, sistemNavigatie, vitezaDeplasare)
{
    this->baterie = baterie;
    this->model = copiazaSir(model);
    this->suprafataCuratata = suprafataCuratata;
}

Roomba::Roomba(const Roomba& original) : Aspirator(original), RobotMobil(original)
{
    baterie = original.baterie;
    model = copiazaSir(original.model);
    suprafataCuratata = original.suprafataCuratata;
}

Roomba& Roomba::operator=(const Roomba& original)
{
    if (this == &original)
    {
        return *this;
    }

    Aspirator::operator=(original);
    RobotMobil::operator=(original);

    baterie = original.baterie;
    suprafataCuratata = original.suprafataCuratata;

    char* copie = copiazaSir(original.model);

    delete[] model;
    model = copie;

    return *this;
}

Roomba::~Roomba()
{
    delete[] model;
    model = nullptr;
}

bool Roomba::operator>(const Roomba& roomba) const
{
    return baterie > roomba.baterie;
}

std::ostream& operator<<(std::ostream& out, const Roomba& roomba)
{
    out << (const Aspirator&)roomba << '\n'
        << (const RobotMobil&)roomba << '\n'
        << "Model: " << (roomba.model != nullptr ? roomba.model : "N/A") << '\n'
        << "Suprafata curatata: " << roomba.suprafataCuratata << " m2\n"
        << roomba.baterie << '\n';

    return out;
}