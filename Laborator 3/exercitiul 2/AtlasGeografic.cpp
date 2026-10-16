#include "AtlasGeografic.h"

AtlasGeografic::AtlasGeografic()
{
    pret = 0.0f;
    anLansare = 2000;
    numarPagini = 0;
    culoare[0] = '\0';
}

AtlasGeografic::AtlasGeografic(const int anLansare, const int numarPagini)
{
    pret = 0.0f;
    culoare[0] = '\0';
    this->anLansare = anLansare;
    this->numarPagini = numarPagini;
}

AtlasGeografic::AtlasGeografic(const int anLansare, const int numarPagini, const char* culoare)
{
    pret = 0.0f;
    this->anLansare = anLansare;
    this->numarPagini = numarPagini;

    if (culoare == nullptr || strlen(culoare) >= sizeof(this->culoare))
    {
        strcpy(this->culoare, "Necunoscuta");
    }
    else
    {
        strcpy(this->culoare, culoare);
    }
}

AtlasGeografic::AtlasGeografic(const float pret, const int anLansare, const int numarPagini, const char* culoare)
{
    this->pret = pret;
    this->anLansare = anLansare;
    this->numarPagini = numarPagini;

    if (culoare == nullptr || strlen(culoare) >= sizeof(this->culoare))
    {
        strcpy(this->culoare, "Necunoscuta");
    }
    else
    {
        strcpy(this->culoare, culoare);
    }
}

float AtlasGeografic::getPret() const
{
    return pret;
}

int AtlasGeografic::getAnLansare() const
{
    return anLansare;
}

int AtlasGeografic::getNumarPagini() const
{
    return numarPagini;
}

const char* AtlasGeografic::getCuloare() const
{
    return culoare;
}

void AtlasGeografic::setPret(const float pret)
{
    if (pret < 0.0f)
    {
        return;
    }

    this->pret = pret;
}

void AtlasGeografic::setAnLansare(const int anLansare)
{
    if (anLansare <= 0)
    {
        return;
    }

    this->anLansare = anLansare;
}

void AtlasGeografic::setNumarPagini(const int numarPagini)
{
    if (numarPagini < 0)
    {
        return;
    }

    this->numarPagini = numarPagini;
}

void AtlasGeografic::setCuloare(const char* culoare)
{
    if (culoare == nullptr || strlen(culoare) >= sizeof(this->culoare))
    {
        return;
    }

    strcpy(this->culoare, culoare);
}

void AtlasGeografic::afisare() const
{
    std::cout << "Pretul este: " << pret << " lei\n";
    std::cout << "Anul de lansare este: " << anLansare << '\n';
    std::cout << "Numarul de pagini este: " << numarPagini << '\n';
    std::cout << "Culoarea este: " << culoare << '\n';
}