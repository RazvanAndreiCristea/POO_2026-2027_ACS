#include "StringHelper.h"

char* copiazaSir(const char* const original)
{
    if (original == nullptr)
    {
        return nullptr;
    }

    char* copie = new char[strlen(original) + 1];
    strcpy(copie, original);

    return copie;
}