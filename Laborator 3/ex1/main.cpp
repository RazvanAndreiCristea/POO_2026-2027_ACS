#include "Farmacie.h"

int main()
{
    Farmacie farmacie1;
    Farmacie farmacie2(15);
    Farmacie farmacie3(2010, 25, 150000.0f);

    farmacie1.setAnInfiintare(2005);
    farmacie1.setNumarAngajati(10);
    farmacie1.setProfitAnual(75000.0f);

    std::cout << "Farmacia 1:\n";
    std::cout << "An infiintare: " << farmacie1.getAnInfiintare() << '\n';
    std::cout << "Numar angajati: " << farmacie1.getNumarAngajati() << '\n';
    std::cout << "Profit anual: " << farmacie1.getProfitAnual() << '\n';

    std::cout << "\nFarmacia 2:\n";
    std::cout << "An infiintare: " << farmacie2.getAnInfiintare() << '\n';
    std::cout << "Numar angajati: " << farmacie2.getNumarAngajati() << '\n';
    std::cout << "Profit anual: " << farmacie2.getProfitAnual() << '\n';

    std::cout << "\nFarmacia 3:\n";
    std::cout << "An infiintare: " << farmacie3.getAnInfiintare() << '\n';
    std::cout << "Numar angajati: " << farmacie3.getNumarAngajati() << '\n';
    std::cout << "Profit anual: " << farmacie3.getProfitAnual() << '\n';

    return 0;
}