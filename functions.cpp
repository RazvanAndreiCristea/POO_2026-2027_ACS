#include "functions.h"

int sumaVector(const int v[], int dim)
{
    if (dim <= 0)
    {
        return 0;
    }

    int suma = 0;

    for (int i = 0; i < dim; i++)
    {
        suma += v[i];
    }

    return suma;
}

int minimVector(const int v[], int dim)
{
    if (dim <= 0)
    {
        return 0;
    }

    int minim = v[0];

    for (int i = 1; i < dim; i++)
    {
        if (v[i] < minim)
        {
            minim = v[i];
        }
    }

    return minim;
}

int maximVector(const int v[], int dim)
{
    if (dim <= 0)
    {
        return 0;
    }

    int maxim = v[0];

    for (int i = 1; i < dim; i++)
    {
        if (v[i] > maxim)
        {
            maxim = v[i];
        }
    }

    return maxim;
}

void interschimbare(int* x, int* y)
{
    if (x == NULL || y == NULL)
    {
        return;
    }

    int aux = *x;
    *x = *y;
    *y = aux;
}

void afisareVector(const int v[], int dim)
{
    if (dim <= 0)
    {
        return;
    }

    for (int i = 0; i < dim; i++)
    {
        if (i == dim - 1)
        {
            std::cout << v[i] << '\n';
            break;
        }

        std::cout << v[i] << ' ';
    }
}

void sortareVector(const int v[], int dim, int vSortat[])
{
    if (dim <= 0)
    {
        return;
    }

    for (int i = 0; i < dim; i++)
    {
        vSortat[i] = v[i];
    }

    for (int i = 0; i < dim - 1; i++)
    {
        for (int j = i + 1; j < dim; j++)
        {
            if (vSortat[i] > vSortat[j])
            {
                interschimbare(&vSortat[i], &vSortat[j]);
            }
        }
    }
}