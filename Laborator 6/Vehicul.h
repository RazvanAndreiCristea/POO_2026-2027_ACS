#pragma once
#include <cstring>
#include <iostream>

class Vehicul
{
    float pret;
    char* marca;
    int anFabricatie;

protected:

    static char* copiazaSir(const char* const original);

public:

    Vehicul();
    Vehicul(const float pret, const char* marca, const int anFabricatie);
    Vehicul(const Vehicul& original);
    Vehicul& operator=(const Vehicul& original);
    ~Vehicul();

    float getPret() const;
    int getAnFabricatie() const;
    const char* getMarca() const;

    void setPret(const float pret);
    void setMarca(const char* marca);
    void setAnFabricatie(const int anFabricatie);

    friend std::ostream& operator<<(std::ostream& out, const Vehicul& vehicul);
};