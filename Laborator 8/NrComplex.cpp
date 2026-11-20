#include "NrComplex.h"

NrComplex::NrComplex(const double real, const double imaginar)
{
    this->real = real;
    this->imaginar = imaginar;
}

double NrComplex::getModul() const
{
    return sqrt(pow(real, 2) + pow(imaginar, 2));
}

bool NrComplex::operator<(const NrComplex& z) const
{
    return getModul() < z.getModul();
}

std::ostream& operator<<(std::ostream& out, const NrComplex& z)
{
    out << "z = " << z.real << " + " << z.imaginar << "j";
    return out;
}