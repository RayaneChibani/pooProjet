#include <fstream>
#include "observateur.h"

void observateurRobot::notifier(int x, int y, const char& direction) const {
    std::cout << "Deplacement : (" << x << ", " << y << ") Direction : " << direction << std::endl;
    std::ofstream logFile("deplacements.log", std::ios::app);
    logFile << "Deplacement : (" << x << ", " << y << ") Direction : " << direction << std::endl;
    logFile.close();
}

