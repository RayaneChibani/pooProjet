#include "robot.h"
#include "terrain.h"


robot::robot(terrain& t, int startX, int startY)
        : d_terrain{t}, x{startX}, y{startY}, direction{'E'} {}

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
        if (d_terrain.getCase(nx, ny) != 'x') {
            d_terrain.setCase(x, y, '.');
            x = nx; y = ny;
            d_terrain.setCase(x, y, '>');
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
        return d_terrain.getCase(nx, ny) == 'x';
    }

    bool robot::obstacleAgauche() const {
        int nx = x, ny = y;
        switch (direction) {
        case 'N': nx--; break;
        case 'E': ny--; break;
        case 'S': nx++; break;
        case 'W': ny++; break;
        }
        return d_terrain.getCase(nx, ny) == 'x';
    }

    bool robot::obstacleAdroite() const {
        int nx = x, ny = y;
        switch (direction) {
        case 'N': nx++; break;
        case 'E': ny++; break;
        case 'S': nx--; break;
        case 'W': ny--; break;
        }
        return d_terrain.getCase(nx, ny) == 'x';
    }

    bool robot::arriveeDevant() const {
        int nx = x, ny = y;
        switch (direction) {
        case 'N': ny--; break;
        case 'E': nx++; break;
        case 'S': ny++; break;
        case 'W': nx--; break;
        }
        return d_terrain.getCase(nx, ny) == 'A';
    }

    bool robot::arriveeAgauche() const {
        int nx = x, ny = y;
        switch (direction) {
        case 'N': nx--; break;
        case 'E': ny--; break;
        case 'S': nx++; break;
        case 'W': ny++; break;
        }
        return d_terrain.getCase(nx, ny) == 'A';
    }

    bool robot::arriveeAdroite() const {
        int nx = x, ny = y;
        switch (direction) {
        case 'N': nx++; break;
        case 'E': ny++; break;
        case 'S': nx--; break;
        case 'W': ny--; break;
        }
        return d_terrain.getCase(nx, ny) == 'A';
    }
