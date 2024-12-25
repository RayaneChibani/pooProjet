#include <iostream>
#include "terrain.h"
#include <stdlib.h>
#include "robot.h"
#include <windows.h> // Pour Sleep (en millisecondes)

class EnregistreurRobot;

void algorithmeMainDroite(robot& robot) {
    int casesParcourues{0};
    while (true) {
        robot.getTerrain().afficherTerrain();
        Sleep(1000);
        system("cls");
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
        if (robot.estSurSortie()) {
            std::cout << "Le robot a trouve la sortie !" << std::endl;
            break;
        }
    }
    std::cout << "Nombre de cases parcourrues : " << casesParcourues << std::endl;
}



int main()
{
    std::string file="lab1.txt";
    terrain t{file};
    robot r{t};
    algorithmeMainDroite(r);
    return 0;
}
