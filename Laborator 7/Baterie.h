#pragma once
#include <iostream>

class Baterie
{
    float capacitate;
    float nivelIncarcare;
    int numarCicluriIncarcare;

public:

    Baterie();
    Baterie(const float capacitate, const float nivelIncarcare, const int numarCicluriIncarcare);

    bool operator>(const Baterie& baterie) const;
    friend std::ostream& operator<<(std::ostream& out, const Baterie& baterie);
};