#include "Aspirator.h"

Aspirator::Aspirator()
{
    producator = nullptr;
    putereAspirare = 0.0f;
    capacitateRecipient = 0.0f;
}

Aspirator::Aspirator(const float putereAspirare, const char* producator, const float capacitateRecipient)
{
    this->putereAspirare = putereAspirare;
    this->producator = copiazaSir(producator);
    this->capacitateRecipient = capacitateRecipient;
}

Aspirator::Aspirator(const Aspirator& original)
{
    putereAspirare = original.putereAspirare;
    producator = copiazaSir(original.producator);
    capacitateRecipient = original.capacitateRecipient;
}

Aspirator& Aspirator::operator=(const Aspirator& original)
{
    if (this == &original)
    {
        return *this;
    }

    putereAspirare = original.putereAspirare;
    capacitateRecipient = original.capacitateRecipient;

    char* copie = copiazaSir(original.producator);

    delete[] producator;
    producator = copie;

    return *this;
}

Aspirator::~Aspirator()
{
    delete[] producator;
    producator = nullptr;
}

std::ostream& operator<<(std::ostream& out, const Aspirator& aspirator)
{
    out << "Producator: " << (aspirator.producator != nullptr ? aspirator.producator : "N/A") << '\n'
        << "Putere aspirare: " << aspirator.putereAspirare << " Pa\n"
        << "Capacitate recipient: " << aspirator.capacitateRecipient << " L\n";

    return out;
}