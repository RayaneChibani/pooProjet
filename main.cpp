#include <iostream>
#include "terrain.h"
#include <stdlib.h>

int main()
{
    /*int x,y;
    cout << "Donner la largeur : \n";
    cin >>x;
    cout << "Donner la longueur : \n";
    cin >>y;
    **/
    std::string file="C:/Users/Lenovo/Desktop/Projet_QP/pooProjet/lab2.txt";
    terrain t{file};
    t.afficher();
    return 0;
}
