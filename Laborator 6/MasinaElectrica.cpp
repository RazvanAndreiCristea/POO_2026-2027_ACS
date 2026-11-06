#include "MasinaElectrica.h"

MasinaElectrica::MasinaElectrica() : Vehicul()
{
    autonomie = 0;
    tipConector = nullptr;
    incarcareRapida = false;
    capacitateBaterie = 0.0f;
}

MasinaElectrica::MasinaElectrica(const float pret, const char* marca, const int anFabricatie, const int autonomie,
    const char* tipConector, const bool incarcareRapida, const float capacitateBaterie) : Vehicul(pret, marca, anFabricatie)
{
    this->autonomie = autonomie;
    this->incarcareRapida = incarcareRapida;
    this->capacitateBaterie = capacitateBaterie;
    this->tipConector = copiazaSir(tipConector);
}

MasinaElectrica::MasinaElectrica(const MasinaElectrica& original) : Vehicul(original)
{
    autonomie = original.autonomie;
    incarcareRapida = original.incarcareRapida;
    capacitateBaterie = original.capacitateBaterie;
    tipConector = copiazaSir(original.tipConector);
}

MasinaElectrica& MasinaElectrica::operator=(const MasinaElectrica& original)
{
    if (this == &original)
    {
        return *this;
    }

    (Vehicul&)(*this) = original;

    autonomie = original.autonomie;
    incarcareRapida = original.incarcareRapida;
    capacitateBaterie = original.capacitateBaterie;

    char* copie = copiazaSir(original.tipConector);

    delete[] tipConector;
    tipConector = copie;

    return *this;
}

MasinaElectrica::~MasinaElectrica()
{
    delete[] tipConector;
    tipConector = nullptr;
}

int MasinaElectrica::getAutonomie() const
{
    return autonomie;
}

bool MasinaElectrica::getIncarcareRapida() const
{
    return incarcareRapida;
}

float MasinaElectrica::getCapacitateBaterie() const
{
    return capacitateBaterie;
}

const char* MasinaElectrica::getTipConector() const
{
    return tipConector;
}

void MasinaElectrica::setAutonomie(const int autonomie)
{
    if (autonomie <= 0)
    {
        return;
    }

    this->autonomie = autonomie;
}

void MasinaElectrica::setTipConector(const char* tipConector)
{
    if (tipConector == nullptr)
    {
        return;
    }

    char* copie = copiazaSir(tipConector);
    delete[] this->tipConector;

    this->tipConector = copie;
}

void MasinaElectrica::setIncarcareRapida(const bool incarcareRapida)
{
    this->incarcareRapida = incarcareRapida;
}

void MasinaElectrica::setCapacitateBaterie(const float capacitateBaterie)
{
    if (capacitateBaterie <= 0.0f)
    {
        return;
    }

    this->capacitateBaterie = capacitateBaterie;
}

bool MasinaElectrica::operator>(const MasinaElectrica& masinaElectrica) const
{
    return autonomie > masinaElectrica.autonomie;
}

std::ostream& operator<<(std::ostream& out, const MasinaElectrica& masinaElectrica)
{
    out << (const Vehicul&)masinaElectrica;

    out << "Autonomia masinii electrice este: " << masinaElectrica.autonomie << " km\n";
    out << "Tipul conectorului este: " << (masinaElectrica.tipConector ? masinaElectrica.tipConector : "N/A") << '\n';
    out << "Incarcarea rapida este: " << (masinaElectrica.incarcareRapida ? "Da" : "Nu") << '\n';
    out << "Capacitatea bateriei este: " << masinaElectrica.capacitateBaterie << " kWh\n\n";

    return out;
}