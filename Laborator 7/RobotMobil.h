#pragma once
#include <iostream>
#include "StringHelper.h"

class RobotMobil
{
    char* sistemNavigatie;
    float vitezaDeplasare;
    int numarSenzori;

public:

    RobotMobil();
    RobotMobil(const int numarSenzori, const char* sistemNavigatie, const float vitezaDeplasare);
    RobotMobil(const RobotMobil& original);
    RobotMobil& operator=(const RobotMobil& original);
    ~RobotMobil();

    friend std::ostream& operator<<(std::ostream& out, const RobotMobil& robotMobil);
};
