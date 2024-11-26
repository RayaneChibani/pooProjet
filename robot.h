#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <vector>
#include <utility>

class terrain;

class observateurRobot
{
public:
    virtual void notifier(int x, int y, char direction) = 0;
};

class robot
{

private:
    int x, y;
    char direction; // 'N', 'E', 'S', 'W'
    terrain &d_terrain;
    std::vector<observateurRobot *> observateurs;

public:
    robot(terrain &t, int startX, int startY);
    void ajouterObservateur(observateurRobot *obs);
    void notifierObservateurs();
    void tournerDroite();
    void tournerGauche();
    void avancer();
    bool obstacleDevant() const;
    bool obstacleAgauche() const;
    bool obstacleAdroite() const;
    bool arriveeAdroite() const;
    bool arriveeAgauche() const;
    bool arriveeDevant() const;
};
#endif
