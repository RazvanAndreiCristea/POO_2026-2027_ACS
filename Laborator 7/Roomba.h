#pragma once
#include "Baterie.h"
#include "Aspirator.h"
#include "RobotMobil.h"

class Roomba : public Aspirator, public RobotMobil
{
    char* model;
    float suprafataCuratata;
    Baterie baterie;

public:

    Roomba();

    Roomba(const float putereAspirare, const char* producator, const float capacitateRecipient,
        const int numarSenzori, const char* sistemNavigatie, const float vitezaDeplasare,
        const char* model, const float suprafataCuratata, const Baterie& baterie);

    Roomba(const Roomba& original);
    Roomba& operator=(const Roomba& original);
    ~Roomba();

    bool operator>(const Roomba& roomba) const;
    friend std::ostream& operator<<(std::ostream& out, const Roomba& roomba);
};