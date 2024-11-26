#include "terrain.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

terrain::terrain(const std::string& fichier):grille{},depart{},arrivee{},largeur{}, hauteur{}{
    lireFichier(fichier);
    }

void terrain::lireFichier(const std::string& fichier){

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
                if (grille[y][x] == 'D') depart = {x, y};
                if (grille[y][x] == 'A') arrivee = {x, y};
            }
        }
    }
void terrain::afficher() const {
        for (const auto& ligne : grille) {
            std::cout << ligne << '\n';
        }
    }

char terrain::getCase(int x, int y) const {
        return grille[y][x];
    }

void terrain::setCase(int x, int y, const char &c) {
        grille[y][x] = c;
    }

std::pair<int, int> terrain::getDepart() const { return depart; }

std::pair<int, int> terrain::getArrivee() const { return arrivee; }
