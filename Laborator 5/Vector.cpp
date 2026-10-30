#include "Vector.h"

double* Vector::copiazaVector(const double* const original, const int& dimensiune)
{
    if (original == nullptr || dimensiune <= 0)
    {
        return nullptr;
    }

    double* copie = new double[dimensiune];

    for (int i = 0; i < dimensiune; i++)
    {
        copie[i] = original[i];
    }

    return copie;
}

Vector::Vector()
{
    dimensiune = 0;
    elemente = nullptr;
}

Vector::Vector(const double* elemente, const int dimensiune)
{
    this->dimensiune = dimensiune;
    this->elemente = copiazaVector(elemente, dimensiune);
}

Vector::Vector(const Vector& original)
{
    dimensiune = original.dimensiune;
    elemente = copiazaVector(original.elemente, original.dimensiune);
}

Vector& Vector::operator=(const Vector& original)
{
    if (this == &original)
    {
        return *this;
    }

    dimensiune = original.dimensiune;

    delete[] elemente;
    elemente = copiazaVector(original.elemente, original.dimensiune);

    return *this;
}

Vector::~Vector()
{
    delete[] elemente;
    elemente = nullptr;
}

const int Vector::getDimensiune() const
{
    return dimensiune;
}

const double* Vector::getElemente() const
{
    return elemente;
}

void Vector::setVector(const double* elemente, const int dimensiune)
{
    if (elemente == nullptr || dimensiune <= 0)
    {
        return;
    }

    double* copie = copiazaVector(elemente, dimensiune);
    delete[] this->elemente;

    this->elemente = copie;
    this->dimensiune = dimensiune;
}

bool Vector::operator==(const Vector& vector) const
{
    if (dimensiune != vector.dimensiune)
    {
        return false;
    }

    if (elemente == nullptr && vector.elemente == nullptr)
    {
        return true;
    }

    if (elemente == nullptr || vector.elemente == nullptr)
    {
        return false;
    }

    for (int i = 0; i < dimensiune; i++)
    {
        if (elemente[i] != vector.elemente[i])
        {
            return false;
        }
    }

    return true;
}

bool Vector::operator!=(const Vector& vector) const
{
    return !(*this == vector); // negam rezultatul intors de operatorul ==
}

Vector& Vector::operator++()
{
    if (elemente != nullptr)
    {
        for (int i = 0; i < dimensiune; i++)
        {
            elemente[i]++;
        }
    }

    return *this;
}

Vector& Vector::operator--()
{
    if (elemente != nullptr)
    {
        for (int i = 0; i < dimensiune; i++)
        {
            elemente[i]--;
        }
    }

    return *this;
}

Vector Vector::operator++(int)
{
    Vector copie(*this);

    ++(*this);

    return copie;
}

Vector Vector::operator--(int)
{
    Vector copie(*this);

    --(*this);

    return copie;
}

Vector* Vector::operator->()
{
    return this;
}

const Vector* Vector::operator->() const
{
    return this;
}

double& Vector::operator[](const int index)
{
    if (elemente == nullptr || index < 0 || index >= dimensiune)
    {
        std::exit(EXIT_FAILURE);
    }

    return elemente[index];
}

const double& Vector::operator[](const int index) const
{
    if (elemente == nullptr || index < 0 || index >= dimensiune)
    {
        std::exit(EXIT_FAILURE);
    }

    return elemente[index];
}

Vector operator+(const Vector& v1, const Vector& v2)
{
    if (v1.elemente == nullptr || v2.elemente == nullptr ||
        v1.dimensiune <= 0 || v1.dimensiune != v2.dimensiune)
    {
        return Vector();
    }

    Vector rezultat;

    rezultat.dimensiune = v1.dimensiune;
    rezultat.elemente = new double[rezultat.dimensiune];

    for (int i = 0; i < rezultat.dimensiune; i++)
    {
        rezultat.elemente[i] = v1.elemente[i] + v2.elemente[i];
    }

    return rezultat;
}

Vector operator+(const Vector& v, const double scalar)
{
    if (v.elemente == nullptr || v.dimensiune <= 0)
    {
        return Vector();
    }

    Vector rezultat;

    rezultat.dimensiune = v.dimensiune;
    rezultat.elemente = new double[rezultat.dimensiune];

    for (int i = 0; i < rezultat.dimensiune; i++)
    {
        rezultat.elemente[i] = v.elemente[i] + scalar;
    }

    return rezultat;
}

Vector operator+(const double scalar, const Vector& v)
{
    return v + scalar;
}

Vector operator*(const Vector& v1, const Vector& v2)
{
    if (v1.elemente == nullptr || v2.elemente == nullptr ||
        v1.dimensiune <= 0 || v1.dimensiune != v2.dimensiune)
    {
        return Vector();
    }

    Vector rezultat;

    rezultat.dimensiune = v1.dimensiune;
    rezultat.elemente = new double[rezultat.dimensiune];

    for (int i = 0; i < rezultat.dimensiune; i++)
    {
        rezultat.elemente[i] = v1.elemente[i] * v2.elemente[i];
    }

    return rezultat;
}

Vector operator*(const Vector& v, const double scalar)
{
    if (v.elemente == nullptr || v.dimensiune <= 0)
    {
        return Vector();
    }

    Vector rezultat;

    rezultat.dimensiune = v.dimensiune;
    rezultat.elemente = new double[rezultat.dimensiune];

    for (int i = 0; i < rezultat.dimensiune; i++)
    {
        rezultat.elemente[i] = v.elemente[i] * scalar;
    }

    return rezultat;
}

Vector operator*(const double scalar, const Vector& v)
{
    return v * scalar;
}

std::ostream& operator<<(std::ostream& out, const Vector& vector)
{
    out << "(";

    if (vector.elemente != nullptr && vector.dimensiune > 0)
    {
        for (int i = 0; i < vector.dimensiune; i++)
        {
            out << vector.elemente[i];

            if (i < vector.dimensiune - 1)
            {
                out << ", ";
            }
        }
    }

    out << ")";

    return out;
}