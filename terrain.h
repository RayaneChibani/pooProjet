#ifndef TERRAIN_H
#define TERRAIN_H

#include <string>
#include <vector>
#include <memory>
class terrain {
public :
    terrain(const std::string& fichier);
    void lireFichier(const std::string& fichier);
    void afficher() const;
    char getCase(int x, int y) const;
    void setCase(int x, int y, char c);
    std::pair<int, int> getDepart() const;
    std::pair<int, int> getArrivee() const;
private:
    std::vector<std::string> grille;
    std::pair<int, int> depart, arrivee;
    int largeur, hauteur;
};

#endif
