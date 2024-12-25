#include "terrain.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

terrain::terrain(const std::string& fichier):grille{},depart{},arrivee{},largeur{}, hauteur{}{
    FichierLabyrinthe(fichier);
    }

void terrain::FichierLabyrinthe(const std::string& fichier){

        std::ifstream fichierLab(fichier);

        if (!fichierLab) {
            std::cout << "Erreur : Impossible de lire le fichier. \n";
        }

        std::string ligne;
        while (std::getline(fichierLab, ligne)) {
            grille.push_back(ligne);
        }

        hauteur = grille.size();
        largeur = grille[0].size();

        for (int y = 0; y < hauteur; ++y) {
            for (int x = 0; x < largeur; ++x) {
                if (grille[y][x] == DEPART) depart = {x, y};
                if (grille[y][x] == ARRIVEE) arrivee = {x, y};
            }
        }
    }
void terrain::afficherTerrain() const {
        for (const auto& ligne : grille) {
            std::cout << ligne << '\n';
        }
    }

char terrain::getCaseTerrain(int x, int y) const {
        return grille[y][x];
    }

void terrain::setCaseTerrain(int x, int y, const char &c) {
        grille[y][x] = c;
    }

std::pair<int, int> terrain::getDepart() const { return depart; }

std::pair<int, int> terrain::getArrivee() const { return arrivee; }

int terrain::largeurGrille()const { return largeur;}
int terrain::hauteurGrille()const { return hauteur;}

