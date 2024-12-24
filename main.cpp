#include <iostream>
#include "terrain.h"
#include <stdlib.h>

int main()
{
    std::string file="C:/Users/Lenovo/Desktop/Projet_QP/pooProjet/lab2.txt";
    terrain t{file};
    t.afficherTerrain();
    return 0;
}
