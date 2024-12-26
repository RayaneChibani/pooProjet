#include <iostream>
#include "terrain.h"
#include <stdlib.h>
#include "robot.h"
#include <windows.h> // Pour Sleep (en millisecondes)


void afficheSimulation(robot& robot){
        robot.getTerrain().afficherTerrain();
        Sleep(500);
        system("cls");
}
int casesParcourrues(int &nombres){return nombres;}

void algorithmeMainDroite(robot& robot) {
    int casesParcourues{0};
    while (true && !robot.estSurSortie()) {
        afficheSimulation(robot);
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
    }
     std::cout << "Le robot a trouve la sortie !" << std::endl;
     std::cout << "Nombre de cases parcourrues : " << casesParcourues << std::endl;
}



int main()
{
    std::string file="labyrinthe.txt";
    terrain terrain{file};
    robot robot{terrain};
    algorithmeMainDroite(robot);
    return 0;
}
