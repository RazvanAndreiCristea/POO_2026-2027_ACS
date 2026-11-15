#pragma once
#include <iostream>
#include "StringHelper.h"

class Aspirator
{
    char* producator;
    float putereAspirare;
    float capacitateRecipient;

public:

    Aspirator();
    Aspirator(const float putereAspirare, const char* producator, const float capacitateRecipient);
    Aspirator(const Aspirator& original);
    Aspirator& operator=(const Aspirator& original);
    ~Aspirator();

    friend std::ostream& operator<<(std::ostream& out, const Aspirator& aspirator);
};