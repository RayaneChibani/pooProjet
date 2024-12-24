#include <iostream>
#include "terrain.h"
#include <stdlib.h>
#include "robot.h"
#include <thread> // Pour std::this_thread::sleep_for
#include <chrono> // Pour std::chrono::milliseconds
class EnregistreurRobot;

void algorithmeMainDroite(robot& robot) {
    int casesParcourues = 0; // Compteur des cases parcourues

    while (true) {
        // Afficher l'état actuel du terrain
        robot.getTerrain().afficherTerrain();
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Pause de 500 ms
        system("cls");
        // Tourner et avancer selon l'algorithme
        robot.tournerDroite();
        if (!robot.obstacleDevant()) {
            robot.avancer();
            casesParcourues++;
        } else {
            robot.tournerGauche();
            if (!robot.obstacleDevant()) {
                robot.avancer();
                casesParcourues++;
            } else {
                robot.tournerGauche();
            }
        }

        // Condition de sortie
        if (robot.estSurSortie()) {
            std::cout << "Le robot a trouvé la sortie !" << std::endl;
            break;
        }
    }

    // Afficher le nombre de cases parcourues
    std::cout << "Nombre de cases parcourues : " << casesParcourues << std::endl;
}



int main()
{
    std::string file="lab1.txt";
    terrain t{file};
    //t.afficherTerrain();

                      // Crée un robot lié au terrain

    // Ajouter un observateur pour suivre ses déplacements
    //EnregistreurRobot obs;


    // Appeler l'algorithme pour résoudre le labyrinthe

    robot r{t};
     //r.ajouterObservateur(&obs);
    algorithmeMainDroite(r);

    return 0;
}
