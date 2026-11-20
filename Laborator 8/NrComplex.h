#pragma once
#include <cmath>
#include <iostream>

class NrComplex
{
    double real;
    double imaginar;

public:

    NrComplex(const double real = 0.0, const double imaginar = 0.0);

    double getModul() const;

    bool operator<(const NrComplex& z) const;
    friend std::ostream& operator<<(std::ostream& out, const NrComplex& z);
};