#pragma once
#include <cstring>
#include <iostream>

class Portofel
{
    float pret;
    char* brand;
    char* culoare;

    const int id;
    static int contor;

    static char* copiazaString(const char* original);

public:

    Portofel();
    Portofel(const float pret, const char* brand, const char* culoare);
    Portofel(const Portofel& portofel);
    Portofel& operator=(const Portofel& portofel);
    ~Portofel();

    float getPret() const;
    const char* getBrand() const;
    const char* getCuloare() const;

    void afisare() const;
};