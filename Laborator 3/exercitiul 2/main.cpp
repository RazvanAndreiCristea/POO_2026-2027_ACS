#include "AtlasGeografic.h"

int main()
{
    AtlasGeografic atlas1;
    AtlasGeografic atlas2(2018, 120);
    AtlasGeografic atlas3(2020, 250, "Albastru");
    AtlasGeografic atlas4(79.99f, 2024, 350, "Verde");

    atlas1.setPret(49.99f);
    atlas1.setAnLansare(2015);
    atlas1.setNumarPagini(200);
    atlas1.setCuloare("Rosu");

    atlas2.setPret(59.99f);
    atlas2.setAnLansare(2019);
    atlas2.setNumarPagini(150);
    atlas2.setCuloare("Galben");

    atlas3.setPret(69.99f);
    atlas3.setAnLansare(2021);
    atlas3.setNumarPagini(275);
    atlas3.setCuloare("Albastru inchis");

    std::cout << "Valori verificate prin getteri (atlas1):\n";

    std::cout << "Pret: " << atlas1.getPret() << '\n';
    std::cout << "An lansare: " << atlas1.getAnLansare() << '\n';
    std::cout << "Numar pagini: " << atlas1.getNumarPagini() << '\n';
    std::cout << "Culoare: " << atlas1.getCuloare() << '\n';

    std::cout << "\nAtlas 1:\n";
    atlas1.afisare();

    std::cout << "\nAtlas 2:\n";
    atlas2.afisare();

    std::cout << "\nAtlas 3:\n";
    atlas3.afisare();

    std::cout << "\nAtlas 4:\n";
    atlas4.afisare();
    std::cout << '\n';

    return 0;
}