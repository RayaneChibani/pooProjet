#include <fstream>
#include "observateur.h"

observateurRobotDirection::observateurRobotDirection() {
    // Constructeur vide
}

void observateurRobotDirection::notifier(int x, int y, const char& direction) {
    std::ofstream logFile("deplacements.log", std::ios::app);
    logFile << "Le robot a chang� de direction : " << direction << std::endl;
    logFile.close();
}

observateurRobotDeplacements::observateurRobotDeplacements() : d_nbDeplacements(0) {
    // Constructeur vide ou initialisation si n�cessaire
}

void observateurRobotDeplacements::notifier(int x, int y, const char& direction) {
    std::ofstream logFile("deplacements.log", std::ios::app);
    logFile << "Le robot s'est d�plac� � la position (" << x << ", " << y << ")" << std::endl;
    d_nbDeplacements=d_nbDeplacements+1;
    logFile.close();
}

int observateurRobotDeplacements::nbDeplacements() const {
    return d_nbDeplacements;
}
