#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <vector>
#include <utility>

class terrain;

class observateurRobot
{
public:
    virtual ~observateurRobot() = default;
    virtual void notifier(int x, int y, char direction) = 0;
};

class robot
{
public:

    robot(terrain &t);
    void ajouterObservateur(observateurRobot *obs);
    void notifierObservateurs();
    void directionRobot();
    void MisAJourDroite(int& x, int& y);
    void MisAJourGauche(int& x, int& y);
    void MisAJourDevant(int& x, int& y);
    void tournerDroite();
    void tournerGauche();
    void avancer();
    bool obstacleDevant() const;
    bool obstacleAgauche() const;
    bool obstacleAdroite() const;
    bool arriveeAdroite() const;
    bool arriveeAgauche() const;
    bool arriveeDevant() const;

private:
    int x,y;
    char direction;
    terrain &d_terrain;
    std::vector<observateurRobot*> observateurs;

};
#endif
