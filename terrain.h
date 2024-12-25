#ifndef TERRAIN_H
#define TERRAIN_H

#include <string>
#include <vector>
#include <memory>

constexpr char DEPART = 'D';
constexpr char ARRIVEE = 'A';


class terrain {
public :
    terrain(const std::string& fichier);
    void FichierLabyrinthe(const std::string& fichier);
    void afficherTerrain() const;
    char getCaseTerrain(int x, int y) const;
    void setCaseTerrain(int x, int y,const char &c);
    std::pair<int, int> getDepart() const;
    std::pair<int, int> getArrivee() const;
    int largeurGrille()const;
    int hauteurGrille()const;
private:
    std::vector<std::string> grille;
    std::pair<int, int> depart, arrivee;
    int largeur, hauteur;
};

#endif
