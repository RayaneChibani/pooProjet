#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <vector>
#include <utility>

class terrain;

//class observateurRobot;

class robot
{
public:

    robot(terrain &terrain);
  //  void ajouterObservateur(observateurRobot *obs);
  //  void notifierObservateurs();
    void tournerDroite();
    void tournerGauche();
    void MisAJourDirectionDevant(int &x, int &y) const;
    void avancer();
    bool obstacleDevant() const;
    bool arriveeDevant() const;
    void MisAJourDirectionGauche(int &x, int &y) const;
    bool obstacleAgauche() const;
    bool arriveeAgauche() const;
    void MisAJourDirectionDroite(int &x, int &y) const;
    bool obstacleAdroite() const;
    bool arriveeAdroite() const;
    bool estSurSortie() const;
    terrain getTerrain() const;
private:
    int x,y;
    char direction;
    terrain &d_terrain;
  //  std::vector<observateurRobot*> observateurs;

};
#endif
