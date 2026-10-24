#include "Portofel.h"

int Portofel::contor = 1;

char* Portofel::copiazaString(const char* original)
{
    if (original == nullptr)
    {
        return nullptr;
    }

    char* copie = new char[strlen(original) + 1];
    strcpy(copie, original);

    return copie;
}

Portofel::Portofel() : id(contor++)
{
    pret = 0.0f;
    brand = nullptr;
    culoare = nullptr;
}

Portofel::Portofel(const float pret, const char* brand, const char* culoare) : id(contor++)
{
    this->pret = pret;
    this->brand = copiazaString(brand);
    this->culoare = copiazaString(culoare);
}

Portofel::Portofel(const Portofel& portofel) : id(contor++)
{
    pret = portofel.pret;
    brand = copiazaString(portofel.brand);
    culoare = copiazaString(portofel.culoare);
}

Portofel& Portofel::operator=(const Portofel& portofel)
{
    if (this == &portofel)
    {
        return *this;
    }

    pret = portofel.pret;

    delete[] brand;
    brand = copiazaString(portofel.brand);

    delete[] culoare;
    culoare = copiazaString(portofel.culoare);

    return *this;
}

Portofel::~Portofel()
{
    delete[] brand;
    brand = nullptr;

    delete[] culoare;
    culoare = nullptr;
}

float Portofel::getPret() const
{
    return pret;
}

const char* Portofel::getBrand() const
{
    return brand;
}

const char* Portofel::getCuloare() const
{
    return culoare;
}

void Portofel::afisare() const
{
    std::cout << "ID-ul portofelului este: " << id << '\n';
    std::cout << "Pretul portofelului este: " << pret << " lei\n";
    std::cout << "Brand-ul portofelului este: " << (brand != nullptr ? brand : "N/A") << '\n';
    std::cout << "Culoarea portofelului este: " << (culoare != nullptr ? culoare : "N/A") << '\n';
}