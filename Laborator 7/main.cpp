#include "SortingHelper.h"

int main()
{
    const int dimensiune = 5;
    Roomba* roombas = new Roomba[dimensiune];

    roombas[0] = Roomba(2600.0f, "iRobot", 0.6f, 12, "LiDAR", 0.8f, "Roomba i7", 75.0f, Baterie(4000.0f, 70.0f, 110));
    roombas[1] = Roomba(2200.0f, "iRobot", 0.4f, 10, "Camera", 0.6f, "Roomba 694", 50.0f, Baterie(3000.0f, 25.0f, 180));
    roombas[2] = Roomba(4000.0f, "iRobot", 0.8f, 16, "LiDAR", 1.2f, "Roomba j9+", 120.0f, Baterie(5200.0f, 95.0f, 45));
    roombas[3] = Roomba(3200.0f, "iRobot", 0.5f, 14, "vSLAM", 1.0f, "Roomba s9+", 90.0f, Baterie(4500.0f, 55.0f, 90));
    roombas[4] = Roomba(2800.0f, "iRobot", 0.7f, 13, "LiDAR", 0.9f, "Roomba Combo j7+", 85.0f, Baterie(4200.0f, 40.0f, 130));

    std::cout << "========== INAINTE DE SORTARE ==========\n\n";
    
    SortingHelper::afisareRoombas(roombas, dimensiune);
    SortingHelper::sortareRoombas(roombas, dimensiune);

    std::cout << "========== DUPA SORTARE ==========\n\n";
    SortingHelper::afisareRoombas(roombas, dimensiune);

    delete[] roombas;
    return 0;
}