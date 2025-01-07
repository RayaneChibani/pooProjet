#include <iostream>
#include <stdlib.h>
#include "terrain.h"
#include "robot.h"
#include "observateur.h"
#include <windows.h> // Pour Sleep (en millisecondes)
#include <memory>

void afficheSimulation(robot& robot){
        robot.getTerrain().afficherTerrain();
        Sleep(500);
        system("cls");
}
int casesParcourrues(int &nombres){return nombres;}

void algorithmeMainDroite(robot& robot, std::unique_ptr<observateurRobotDeplacements> obserRobotDeplacements) {
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
    robot.getTerrain().afficherTerrain();
     std::cout << "Le robot a trouve la sortie !" << std::endl;
     std::cout << "Nombre de cases parcourrues : " << casesParcourues << std::endl;
     std::cout << "Nombre de cases parcourrues de la part de l'observateur : " << obserRobotDeplacements->nbDeplacements() << std::endl;
}



int main()
{
    std::string file="lab2.txt";
    terrain terrain{file};
    robot test_robot{terrain};



    std::unique_ptr<observateurRobotDeplacements> obserRobotDeplacements = std::make_unique<observateurRobotDeplacements>();


    test_robot.ajouterObservateur(std::make_unique<observateurRobotDirection>());
    test_robot.ajouterObservateur(std::move(obserRobotDeplacements));

    algorithmeMainDroite(test_robot, std::move(obserRobotDeplacements));
    return 0;
}
