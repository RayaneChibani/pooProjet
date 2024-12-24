#include "robot.h"
#include "terrain.h"


robot::robot(terrain& t): d_terrain{t}, x{t.getDepart().first}, y{t.getDepart().second}, direction{'E'} {}

    void robot::ajouterObservateur(observateurRobot* obs) {
        observateurs.push_back(obs);
    }

    void robot::notifierObservateurs() {
        for (auto obs : observateurs) {
            obs->notifier(x, y, direction);
        }
    }
    void robot::tournerDroite() {
        switch (direction) {
        case 'N': direction = 'E'; break;
        case 'E': direction = 'S'; break;
        case 'S': direction = 'W'; break;
        case 'W': direction = 'N'; break;
        }
        notifierObservateurs();
    }

    void robot::tournerGauche() {
        switch (direction) {
        case 'N': direction = 'W'; break;
        case 'W': direction = 'S'; break;
        case 'S': direction = 'E'; break;
        case 'E': direction = 'N'; break;
        }
        notifierObservateurs();
    }

    void robot::avancer() {
        int nx = x, ny = y;
        switch (direction) {
        case 'N': ny--; break;
        case 'E': nx++; break;
        case 'S': ny++; break;
        case 'W': nx--; break;
        }
        if (d_terrain.getCaseTerrain(nx, ny) != '#') {
            d_terrain.setCaseTerrain(x, y, '.');
            x = nx; y = ny;
            d_terrain.setCaseTerrain(x, y, '>');
        }
        notifierObservateurs();
    }

    bool robot::obstacleDevant() const {
        int nx = x, ny = y;
        switch (direction) {
        case 'N': ny--; break;
        case 'E': nx++; break;
        case 'S': ny++; break;
        case 'W': nx--; break;
        }
        return d_terrain.getCaseTerrain(nx, ny) == '#';
    }

    bool robot::obstacleAgauche() const {
        int nx = x, ny = y;
        switch (direction) {
        case 'N': nx--; break;
        case 'E': ny--; break;
        case 'S': nx++; break;
        case 'W': ny++; break;
        }
        return d_terrain.getCaseTerrain(nx, ny) == '#';
    }

    bool robot::obstacleAdroite() const {
        int nx = x, ny = y;
        switch (direction) {
        case 'N': nx++; break;
        case 'E': ny++; break;
        case 'S': nx--; break;
        case 'W': ny--; break;
        }
        return d_terrain.getCaseTerrain(nx, ny) == '#';
    }

    bool robot::arriveeDevant() const {
        int nx = x, ny = y;
        switch (direction) {
        case 'N': ny--; break;
        case 'E': nx++; break;
        case 'S': ny++; break;
        case 'W': nx--; break;
        }
        return d_terrain.getCaseTerrain(nx, ny) == 'A';
    }

    bool robot::arriveeAgauche() const {
        int nx = x, ny = y;
        switch (direction) {
        case 'N': nx--; break;
        case 'E': ny--; break;
        case 'S': nx++; break;
        case 'W': ny++; break;
        }
        return d_terrain.getCaseTerrain(nx, ny) == 'A';
    }

    bool robot::arriveeAdroite() const {
        int nx = x, ny = y;
        switch (direction) {
        case 'N': nx++; break;
        case 'E': ny++; break;
        case 'S': nx--; break;
        case 'W': ny--; break;
        }
        return d_terrain.getCaseTerrain(nx, ny) == 'A';
    }
    bool robot::estSurSortie() const {
        // Vérifier si les coordonnées actuelles du robot correspondent à celles de la sortie
        auto sortie = d_terrain.getArrivee();
        return (x == sortie.first && y == sortie.second);
    }
    terrain robot::getTerrain() const{
        return d_terrain;
    }
