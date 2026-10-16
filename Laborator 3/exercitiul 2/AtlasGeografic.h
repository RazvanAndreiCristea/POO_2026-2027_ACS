#pragma once
#include <cstring>
#include <iostream>

class AtlasGeografic
{
    float pret;
    int anLansare;
    int numarPagini;
    char culoare[50];

public:

    AtlasGeografic();
    AtlasGeografic(const int anLansare, const int numarPagini);
    AtlasGeografic(const int anLansare, const int numarPagini, const char* culoare);
    AtlasGeografic(const float pret, const int anLansare, const int numarPagini, const char* culoare);

    float getPret() const;
    int getAnLansare() const;
    int getNumarPagini() const;
    const char* getCuloare() const;

    void setPret(const float pret);
    void setAnLansare(const int anLansare);
    void setNumarPagini(const int numarPagini);
    void setCuloare(const char* culoare);

    void afisare() const;
};