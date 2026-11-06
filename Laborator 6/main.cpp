#include "MasinaElectrica.h"

int main()
{
    MasinaElectrica masinaImplicita;

    std::cout << masinaImplicita << '\n';

    MasinaElectrica masina(210000.0f, "Tesla", 2024, 530, "CCS2", true, 75.0f);

    std::cout << "Masina initiala:\n";
    std::cout << masina << '\n';

    std::cout << "Marca: " << masina.getMarca() << '\n';
    std::cout << "Pret: " << masina.getPret() << '\n';
    std::cout << "An fabricatie: " << masina.getAnFabricatie() << '\n';

    std::cout << "Autonomie: " << masina.getAutonomie() << '\n';
    std::cout << "Tip conector: " << masina.getTipConector() << '\n';
    std::cout << "Incarcare rapida: " << masina.getIncarcareRapida() << '\n';
    std::cout << "Capacitate baterie: " << masina.getCapacitateBaterie() << '\n';

    masina.setPret(195000.0f);
    masina.setMarca("Tesla Model 3");
    masina.setAnFabricatie(2025);
    masina.setAutonomie(600);
    masina.setTipConector("Type 2");
    masina.setIncarcareRapida(false);
    masina.setCapacitateBaterie(82.0f);

    std::cout << "\nMasina modificata:\n";
    std::cout << masina << '\n';

    MasinaElectrica masinaCopiata(masina);

    std::cout << "Masina copiata:\n";
    std::cout << masinaCopiata << '\n';

    MasinaElectrica masinaAsignata;
    masinaAsignata = masina;

    std::cout << "Masina asignata:\n";
    std::cout << masinaAsignata << '\n';

    masina.setMarca("BMW");
    masina.setTipConector("CCS2");

    std::cout << "Original dupa modificare:\n";
    std::cout << masina << '\n';

    std::cout << "Copie dupa modificarea originalului:\n";
    std::cout << masinaCopiata << '\n';

    std::cout << "Obiect asignat dupa modificarea originalului:\n";
    std::cout << masinaAsignata << '\n';

    const int dimensiune = 5;
    MasinaElectrica* masini = new MasinaElectrica[dimensiune];

    masini[0] = MasinaElectrica(210000.0f, "Tesla", 2024, 530, "CCS2", true, 75.0f);
    masini[1] = MasinaElectrica(99000.0f, "Renault", 2022, 395, "Type 2", true, 52.0f);
    masini[2] = MasinaElectrica(85000.0f, "Nissan", 2021, 270, "CHAdeMO", true, 40.0f);
    masini[3] = MasinaElectrica(240000.0f, "BMW", 2023, 490, "CCS2", true, 80.0f);
    masini[4] = MasinaElectrica(90000.0f, "Dacia", 2024, 230, "CCS2", false, 27.0f);

    for (int i = 0; i < dimensiune - 1; i++)
    {
        for (int j = i + 1; j < dimensiune; j++)
        {
            if (masini[i] > masini[j])
            {
                MasinaElectrica temp = masini[i];
                masini[i] = masini[j];
                masini[j] = temp;
            }
        }
    }

    std::cout << "\nMasini sortate crescator dupa autonomie:\n";

    for (int i = 0; i < dimensiune; i++)
    {
        std::cout << masini[i] << '\n';
    }

    delete[] masini;
    return 0;
}