#include "Portofel.h"

int main()
{
    int nrPortofele = 10;
    Portofel* portofele = new Portofel[nrPortofele];

    portofele[0] = Portofel(250.0f, "Tommy", "Negru");
    portofele[1] = Portofel(150.0f, "Fossil", "Maro");
    portofele[2] = Portofel(300.0f, "Guess", "Rosu");
    portofele[3] = Portofel(120.0f, "Fossil", "Negru");
    portofele[4] = Portofel(200.0f, "Benvenuti", "Verde");
    portofele[5] = Portofel(180.0f, "Guess", "Negru");
    portofele[6] = Portofel(100.0f, "Fossil", "Negru");
    portofele[7] = Portofel(350.0f, "Benvenuti", "Maro");
    portofele[8] = Portofel(220.0f, "Benvenuti", "Negru");
    portofele[9] = Portofel(90.0f, "Armani", "Alb");

    std::cout << "Elementele vectorului de portofele inainte de sortare sunt afisate mai jos\n\n";

    for (int i = 0; i < nrPortofele; i++)
    {
        portofele[i].afisare();
        std::cout << '\n';
    }

    for (int i = 0; i < nrPortofele - 1; i++)
    {
        for (int j = i + 1; j < nrPortofele; j++)
        {
            int comparareBrand = std::strcmp(portofele[i].getBrand(), portofele[j].getBrand());
            int comparareCuloare = std::strcmp(portofele[i].getCuloare(), portofele[j].getCuloare());

            if (comparareBrand > 0 || (comparareBrand == 0 && comparareCuloare > 0) ||
                (comparareBrand == 0 && comparareCuloare == 0 && portofele[i].getPret() > portofele[j].getPret()))
            {
                Portofel auxiliar = portofele[i];
                portofele[i] = portofele[j];
                portofele[j] = auxiliar;
            }
        }
    }

    std::cout << "Elementele vectorului de portofele dupa sortare sunt afisate mai jos\n\n";

    for (int i = 0; i < nrPortofele; i++)
    {
        portofele[i].afisare();
        std::cout << '\n';
    }

    delete[] portofele;
    return 0;
}