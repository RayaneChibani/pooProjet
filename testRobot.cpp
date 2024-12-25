#include "doctest.h"
#include "robot.h"

#include "terrain.h"
#include <fstream>

TEST_CASE("Test robot avec sous-cas") {
    const std::string nomFichier = "test_robot_subcase.txt";
    std::ofstream fichier(nomFichier);
    fichier << "#####\n"
            << "#D  #\n"
            << "# # #\n"
            << "#  A#\n"
            << "#####\n";
            //===> ||
    fichier.close();

    terrain t(nomFichier);
    robot r(t);

    SUBCASE("Initialisation") {
        REQUIRE_EQ(r.obstacleDevant(), false);
        REQUIRE_EQ(r.obstacleAgauche(), true);
        REQUIRE_EQ(r.obstacleAdroite(), false);
        REQUIRE_EQ(r.arriveeDevant(), false);
        REQUIRE_EQ(r.arriveeAgauche(), false);
        REQUIRE_EQ(r.arriveeAdroite(), false);
    }

    SUBCASE("Avancer sans obstacle") {
        r.avancer();
        REQUIRE_EQ(t.getCaseTerrain(1, 1), '.');
        REQUIRE_EQ(t.getCaseTerrain(2, 1), '>');
    }

    SUBCASE("Tourner à droite et avancer") {
        r.tournerDroite();
        r.avancer();
        REQUIRE_EQ(t.getCaseTerrain(1, 1), '.');
        REQUIRE_EQ(t.getCaseTerrain(2, 2), '#');
    }

    SUBCASE("Tourner à gauche et avancer") {
        r.tournerGauche();
        r.avancer();
        REQUIRE_EQ(t.getCaseTerrain(1, 1), 'D');
    }

    SUBCASE("Detection des obstacles") {
        r.tournerDroite();
        r.tournerDroite();
        REQUIRE_EQ(r.obstacleDevant(), true);
    }

    SUBCASE("Detection de l'arrivee") {
        r.avancer();
        r.avancer();
        r.tournerDroite();
        r.avancer();
        REQUIRE_EQ(r.arriveeDevant(), true);
    }
    std::remove(nomFichier.c_str());
}
