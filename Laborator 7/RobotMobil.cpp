#include "RobotMobil.h"

RobotMobil::RobotMobil()
{
    numarSenzori = 0;
    vitezaDeplasare = 0.0f;
    sistemNavigatie = nullptr;
}

RobotMobil::RobotMobil(const int numarSenzori, const char* sistemNavigatie, const float vitezaDeplasare)
{
    this->numarSenzori = numarSenzori;
    this->vitezaDeplasare = vitezaDeplasare;
    this->sistemNavigatie = copiazaSir(sistemNavigatie);
}

RobotMobil::RobotMobil(const RobotMobil& original)
{
    numarSenzori = original.numarSenzori;
    vitezaDeplasare = original.vitezaDeplasare;
    sistemNavigatie = copiazaSir(original.sistemNavigatie);
}

RobotMobil& RobotMobil::operator=(const RobotMobil& original)
{
    if (this == &original)
    {
        return *this;
    }

    numarSenzori = original.numarSenzori;
    vitezaDeplasare = original.vitezaDeplasare;

    char* copie = copiazaSir(original.sistemNavigatie);

    delete[] sistemNavigatie;
    sistemNavigatie = copie;

    return *this;
}

RobotMobil::~RobotMobil()
{
    delete[] sistemNavigatie;
    sistemNavigatie = nullptr;
}

std::ostream& operator<<(std::ostream& out, const RobotMobil& robotMobil)
{
    out << "Sistem navigatie: " << (robotMobil.sistemNavigatie != nullptr ? robotMobil.sistemNavigatie : "N/A") << '\n'
        << "Viteza deplasare: " << robotMobil.vitezaDeplasare << " m/s\n"
        << "Numar senzori: " << robotMobil.numarSenzori << '\n';

    return out;
}