#include "Vector.h"

int main()
{
    double elemente1[] = { 1.0, 2.0, 3.0 };
    double elemente2[] = { 4.0, 5.0, 6.0 };

    // Constructori
    Vector v1;
    Vector v2(elemente1, 3);
    Vector v3(elemente2, 3);
    Vector v4(v2);

    std::cout << "Vectorii initiali:\n";
    std::cout << "v1 = " << v1 << '\n';
    std::cout << "v2 = " << v2 << '\n';
    std::cout << "v3 = " << v3 << '\n';
    std::cout << "v4 = " << v4 << '\n';

    // Operatorul de asignare
    v1 = v3;
    std::cout << "\nDupa asignarea v1 = v3:\n";
    std::cout << "v1 = " << v1 << '\n';

    // Testarea autoasignarii
    v1 = v1;
    std::cout << "Dupa autoasignare: " << v1 << '\n';

    // Getteri
    std::cout << "\nDimensiunea lui v2: " << v2.getDimensiune() << '\n';

    const double* elemente = v2.getElemente();

    if (elemente != nullptr)
    {
        std::cout << "Primul element din v2: " << elemente[0] << '\n';
    }

    // Setter
    double elementeNoi[] = { 10.0, 20.0, 30.0 };

    v1.setVector(elementeNoi, 3);
    std::cout << "\nDupa setVector: " << v1 << '\n';

    // Setter: parametrii invalizi nu trebuie sa modifice vectorul
    v1.setVector(nullptr, 3);
    std::cout << "Dupa setVector(nullptr, 3): " << v1 << '\n';
    v1.setVector(elementeNoi, 0);
    std::cout << "Dupa setVector(elementeNoi, 0): " << v1 << '\n';
    v1.setVector(elementeNoi, -2);
    std::cout << "Dupa setVector(elementeNoi, -2): " << v1 << '\n';

    // Operatorii == si !=
    std::cout << "\nCompararea vectorilor:\n";
    std::cout << std::boolalpha;

    std::cout << "v2 == v4: " << (v2 == v4) << '\n';
    std::cout << "v2 != v3: " << (v2 != v3) << '\n';
    std::cout << "v2 == v3: " << (v2 == v3) << '\n';
    std::cout << "v2 != v4: " << (v2 != v4) << '\n';

    // Comparatii care implica pointeri nullptr
    Vector vectorGol1;
    Vector vectorGol2;

    std::cout << "\nComparatii cu pointeri nullptr:\n";
    std::cout << "gol1 == gol2: " << (vectorGol1 == vectorGol2) << '\n';
    std::cout << "gol1 != gol2: " << (vectorGol1 != vectorGol2) << '\n';
    std::cout << "gol1 == v2: " << (vectorGol1 == v2) << '\n';
    std::cout << "gol1 != v2: " << (vectorGol1 != v2) << '\n';
    std::cout << "v2 == gol1: " << (v2 == vectorGol1) << '\n';
    std::cout << "v2 != gol1: " << (v2 != vectorGol1) << '\n';

    // Incrementare prefixata
    Vector v5(v2);

    std::cout << "\nIncrementare prefixata:\n";
    std::cout << "Inainte: " << v5 << '\n';
    std::cout << "Rezultat ++v5: " << ++v5 << '\n';
    std::cout << "Dupa: " << v5 << '\n';

    // Decrementare prefixata
    std::cout << "\nDecrementare prefixata:\n";
    std::cout << "Inainte: " << v5 << '\n';
    std::cout << "Rezultat --v5: " << --v5 << '\n';
    std::cout << "Dupa: " << v5 << '\n';

    // Incrementare postfixata
    Vector v6(v2);

    std::cout << "\nIncrementare postfixata:\n";
    std::cout << "Inainte: " << v6 << '\n';

    Vector rezultatPostfixat1 = v6++;
    std::cout << "Valoare returnata: " << rezultatPostfixat1 << '\n';
    std::cout << "Dupa: " << v6 << '\n';

    // Decrementare postfixata
    std::cout << "\nDecrementare postfixata:\n";
    std::cout << "Inainte: " << v6 << '\n';

    Vector rezultatPostfixat2 = v6--;
    std::cout << "Valoare returnata: " << rezultatPostfixat2 << '\n';
    std::cout << "Dupa: " << v6 << '\n';

    // Operatorul -> (varianta non-const)
    Vector* pointerVector = v2.operator->();

    std::cout << "\nOperatorul -> (non-const):\n";
    std::cout << "Dimensiune: " << pointerVector->getDimensiune() << '\n';

    std::cout << "Acces direct prin v2->: " << v2->getDimensiune() << '\n';

    // Operatorul -> (varianta const)
    const Vector& vectorConst = v2;
    const Vector* pointerConst = vectorConst.operator->();

    std::cout << "\nOperatorul -> (const):\n";
    std::cout << "Dimensiune: " << pointerConst->getDimensiune() << '\n';

    std::cout << "Acces direct prin vectorConst->: " << vectorConst->getDimensiune() << '\n';

    // Operatorul [] (varianta non-const)
    std::cout << "\nOperatorul [] (non-const):\n";
    std::cout << "v2[0] = " << v2[0] << '\n';

    v2[0] = 100.0;
    std::cout << "Dupa modificare: " << v2 << '\n';

    // Operatorul [] (varianta const)
    std::cout << "\nOperatorul [] (const):\n";
    std::cout << "vectorConst[1] = " << vectorConst[1] << '\n';

    // Acces invalid (decomenteaza si ruleaza separat: programul se opreste)
    // std::cout << v2[-1] << '\n';
    // std::cout << v2[v2.getDimensiune()] << '\n';
    // std::cout << vectorConst[-1] << '\n';

    // Operatorul + intre doi vectori
    Vector sumaVectori = v2 + v3;
    std::cout << "\nv2 + v3 = " << sumaVectori << '\n';

    // Operatorul + intre vector si scalar
    Vector sumaScalar1 = v2 + 5.0;
    std::cout << "v2 + 5 = " << sumaScalar1 << '\n';

    // Operatorul + intre scalar si vector
    Vector sumaScalar2 = 5.0 + v2;
    std::cout << "5 + v2 = " << sumaScalar2 << '\n';

    // Operatorul * intre doi vectori
    Vector produsVectori = v2 * v3;
    std::cout << "\nv2 * v3 = " << produsVectori << '\n';

    // Operatorul * intre vector si scalar
    Vector produsScalar1 = v2 * 2.0;
    std::cout << "v2 * 2 = " << produsScalar1 << '\n';

    // Operatorul * intre scalar si vector
    Vector produsScalar2 = 2.0 * v2;
    std::cout << "2 * v2 = " << produsScalar2 << '\n';

    std::cout << "\nSfarsitul programului.\n";
    return 0;
}