#include <iostream>
#include <stdlib.h>
#include "terrain.h"
#include "robot.h"
#include "observateur.h"
#include <windows.h> // Pour Sleep (en millisecondes)
#include <memory>
#include <fstream>

constexpr int tempsDattente = 500;

void effacerFichier(const std::string& nomFichier) {
    std::ofstream logFile(nomFichier, std::ios::trunc);  // Efface tout le contenu du fichier
    logFile.close();
}

void afficheSimulation(robot& robot){
        robot.getTerrain().afficherTerrain();
        Sleep(tempsDattente);
        system("cls");
}

void sortieTrouvee(robot& robot){
    robot.getTerrain().afficherTerrain();
    std::cout << "Le robot a trouve la sortie !" << std::endl;

    for (const auto& observateur : robot.getObservateurs()) {
        auto* collecteur = dynamic_cast<observateurRobotDeplacements*>(observateur.get());
            if (collecteur) {
                   std::cout << "Nombre de cases parcourues : " << collecteur->nbDeplacements() << std::endl;
            }
    }
}


void algorithmeMainDroite(robot& robot) {
    while (true && !robot.estSurSortie()) {
        afficheSimulation(robot);
        robot.tournerDroite();
        if (!robot.obstacleDevant()) {
            robot.avancer();
        } else {
            robot.tournerGauche();
            if (!robot.obstacleDevant()) {
                robot.avancer();
            } else {
                robot.tournerGauche();
            }
        }
    }
    sortieTrouvee(robot);

}



int main()
{
    effacerFichier("deplacements.log");

    std::string file="lab2.txt";
    terrain terrain{file};
    robot test_robot{terrain};
    test_robot.ajouterObservateur(std::make_unique<observateurRobotDirection>());
    test_robot.ajouterObservateur(std::make_unique<observateurRobotDeplacements>());

    algorithmeMainDroite(test_robot);
    return 0;
}
