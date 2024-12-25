#include "doctest.h"
#include "terrain.h"
#include <fstream>

TEST_CASE("La classe terrain marche") {

    const std::string test = "test.txt";

    // Create a temporary maze file for testing
    std::ofstream outFile(test);
    outFile << "#####\n"
            << "#D  #\n"
            << "#   #\n"
            << "#  A#\n"
            << "#####\n";
    outFile.close();

    terrain t(test);

    SUBCASE("La methode getCaseTerrain fonctionne") {
        char caseTerrain = t.getCaseTerrain(0, 0);
        REQUIRE_EQ('#', caseTerrain);
    }

    SUBCASE("La methode setCaseTerrain fonctionne") {
        t.setCaseTerrain(2, 1, 'X');
        char caseTerrainModifiee = t.getCaseTerrain(2, 1);
        REQUIRE_EQ('X', caseTerrainModifiee);
    }

    SUBCASE("La methode getDepart fonctionne") {
        std::pair<int, int> depart(1, 1);
        std::pair<int, int> departAttendu = t.getDepart();
        REQUIRE_EQ(depart, departAttendu);
    }

    SUBCASE("La methode getArrivee fonctionne") {
        std::pair<int, int> arrivee(3, 3);
        std::pair<int, int> arriveeAttendu = t.getArrivee();
        REQUIRE_EQ(arrivee, arriveeAttendu);
    }
    std::remove(test.c_str());
}
