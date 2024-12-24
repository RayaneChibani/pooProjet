#include <iostream>
#include "terrain.h"
#include "robot.h"
#include <stdlib.h>

int main()
{
    std::string file="lab2.txt";
    terrain t{file};
    t.afficherTerrain();
    return 0;
}
