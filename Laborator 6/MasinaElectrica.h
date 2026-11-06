#pragma once
#include "Vehicul.h"

class MasinaElectrica : public Vehicul
{
    int autonomie;
    char* tipConector;

    bool incarcareRapida;
    float capacitateBaterie;

public:

    MasinaElectrica();
    MasinaElectrica(const float pret, const char* marca, const int anFabricatie, const int autonomie,
        const char* tipConector, const bool incarcareRapida, const float capacitateBaterie);

    MasinaElectrica(const MasinaElectrica& original);
    MasinaElectrica& operator=(const MasinaElectrica& original);
    ~MasinaElectrica();

    int getAutonomie() const;
    bool getIncarcareRapida() const;
    float getCapacitateBaterie() const;
    const char* getTipConector() const;

    void setAutonomie(const int autonomie);
    void setTipConector(const char* tipConector);
    void setIncarcareRapida(const bool incarcareRapida);
    void setCapacitateBaterie(const float capacitateBaterie);

    bool operator>(const MasinaElectrica& masinaElectrica) const;
    friend std::ostream& operator<<(std::ostream& out, const MasinaElectrica& masinaElectrica);
};