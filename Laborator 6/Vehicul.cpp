#include "Vehicul.h"

char* Vehicul::copiazaSir(const char* const original)
{
    if (original == nullptr)
    {
        return nullptr;
    }

    char* copie = new char[strlen(original) + 1];
    strcpy(copie, original);

    return copie;
}

Vehicul::Vehicul()
{
    pret = 0.0f;
    marca = nullptr;
    anFabricatie = 0;
}

Vehicul::Vehicul(const float pret, const char* marca, const int anFabricatie)
{
    this->pret = pret;
    this->marca = copiazaSir(marca);
    this->anFabricatie = anFabricatie;
}

Vehicul::Vehicul(const Vehicul& original)
{
    pret = original.pret;
    marca = copiazaSir(original.marca);
    anFabricatie = original.anFabricatie;
}

Vehicul& Vehicul::operator=(const Vehicul& original)
{
    if (this == &original)
    {
        return *this;
    }

    pret = original.pret;
    anFabricatie = original.anFabricatie;

    char* copie = copiazaSir(original.marca);

    delete[] marca;
    marca = copie;

    return *this;
}

Vehicul::~Vehicul()
{
    delete[] marca;
    marca = nullptr;
}

float Vehicul::getPret() const
{
    return pret;
}

int Vehicul::getAnFabricatie() const
{
    return anFabricatie;
}

const char* Vehicul::getMarca() const
{
    return marca;
}

void Vehicul::setPret(const float pret)
{
    if (pret <= 0.0f)
    {
        return;
    }

    this->pret = pret;
}

void Vehicul::setMarca(const char* marca)
{
    if (marca == nullptr)
    {
        return;
    }

    char* copie = copiazaSir(marca);
    delete[] this->marca;

    this->marca = copie;
}

void Vehicul::setAnFabricatie(const int anFabricatie)
{
    if (anFabricatie <= 0)
    {
        return;
    }

    this->anFabricatie = anFabricatie;
}

std::ostream& operator<<(std::ostream& out, const Vehicul& vehicul)
{
    out << "Pretul vehiculului este: " << vehicul.pret << '\n';
    out << "Anul de fabricatie al vehiculului este: " << vehicul.anFabricatie << '\n';
    out << "Marca vehiculului este: " << (vehicul.marca ? vehicul.marca : "N/A") << "\n\n";

    return out;
}