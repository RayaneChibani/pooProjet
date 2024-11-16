#include <iostream>
#include "../terrain.h"
#include <stdlib.h>

int main()
{
    /*int x,y;
    cout << "Donner la largeur : \n";
    cin >>x;
    cout << "Donner la longueur : \n";
    cin >>y;
    **/
    std::string file="../lab1.txt";
    terrain t{file};
    t.afficher();
    return 0;
}
