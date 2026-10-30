#pragma once
#include <cstdlib>
#include <iostream>

class Vector
{
    int dimensiune;
    double* elemente;

    static double* copiazaVector(const double* const original, const int& dimensiune);

public:

    Vector();
    Vector(const double* elemente, const int dimensiune);
    Vector(const Vector& original);
    Vector& operator=(const Vector& original);
    ~Vector();

    const int getDimensiune() const;
    const double* getElemente() const;

    void setVector(const double* elemente, const int dimensiune);

    bool operator==(const Vector& vector) const;
    bool operator!=(const Vector& vector) const;

    Vector& operator++();
    Vector& operator--();

    Vector operator++(int);
    Vector operator--(int);

    Vector* operator->();
    const Vector* operator->() const;

    double& operator[](const int index);
    const double& operator[](const int index) const;

    friend Vector operator+(const Vector& v1, const Vector& v2);
    friend Vector operator+(const Vector& v, const double scalar);
    friend Vector operator+(const double scalar, const Vector& v);

    friend Vector operator*(const Vector& v1, const Vector& v2);
    friend Vector operator*(const Vector& v, const double scalar);
    friend Vector operator*(const double scalar, const Vector& v);

    friend std::ostream& operator<<(std::ostream& out, const Vector& vector);
};