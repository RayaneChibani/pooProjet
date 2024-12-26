#include "robot.h"
#include "terrain.h"
//#include "observateur.h"

constexpr char Nord = 'N';
constexpr char EST = 'E';
constexpr char SUD = 'S';
constexpr char OUEST = 'O';
constexpr char OBSTACLE = '#';
constexpr char ItineraireRobot = '.';
constexpr char DirectionNordRobot = '^';
constexpr char DirectionEstRobot = '>';
constexpr char DirectionSudRobot = 'v';
constexpr char DirectionOuestRobot = '<';



robot::robot(terrain& terrain): d_terrain{terrain}, x{terrain.getDepart().first}, y{terrain.getDepart().second}, direction{EST} {}

   /*   void robot::ajouterObservateur(observateurRobot* obs) {
        observateurs.push_back(obs);
    }

    void robot::notifierObservateurs() {
        for (auto obs : observateurs) {
            obs->notifier(x, y, direction);
        }
    }
*/
    void robot::tournerDroite() {
        switch (direction) {
        case Nord : direction = EST; break;
        case EST  : direction = SUD; break;
        case SUD  : direction = OUEST; break;
        case OUEST: direction = Nord; break;
        }
       // notifierObservateurs();
    }

    void robot::tournerGauche() {
        switch (direction) {
        case Nord : direction = OUEST; break;
        case EST  : direction = Nord; break;
        case SUD  : direction = EST; break;
        case OUEST: direction = SUD; break;
        }
      //  notifierObservateurs();
    }

    void robot::MisAJourDirectionDevant(int &x, int &y) const{
        switch (direction) {
        case Nord : y--; break;
        case EST  : x++; break;
        case SUD  : y++; break;
        case OUEST: x--; break;
        }
    }

    void robot::avancer() {
        int nx{x}, ny{y};
        MisAJourDirectionDevant(nx,ny);
        if (d_terrain.getCaseTerrain(nx, ny) != OBSTACLE) {
            d_terrain.setCaseTerrain(x, y, ItineraireRobot);
            x = nx; y = ny;
            switch (direction) {
            case Nord : d_terrain.setCaseTerrain(x, y,DirectionNordRobot); break;
            case EST  : d_terrain.setCaseTerrain(x, y,DirectionEstRobot);break;
            case SUD  : d_terrain.setCaseTerrain(x, y,DirectionSudRobot); break;
            case OUEST: d_terrain.setCaseTerrain(x, y,DirectionOuestRobot); break;
        }
        }
      //  notifierObservateurs();
    }

    bool robot::obstacleDevant() const {
        int nx{x}, ny{y};
        MisAJourDirectionDevant(nx,ny);
        return d_terrain.getCaseTerrain(nx,ny) == OBSTACLE;
    }

    bool robot::arriveeDevant() const {
        int nx = x, ny = y;
        MisAJourDirectionDevant(nx,ny);
        return d_terrain.getCaseTerrain(nx, ny) == ARRIVEE;
    }

     void robot::MisAJourDirectionGauche(int &x, int &y) const{
        switch (direction) {
        case Nord : x--; break;
        case EST  : y--; break;
        case SUD  : x++; break;
        case OUEST: y++; break;
        }
    }

    bool robot::obstacleAgauche() const {
        int nx = x, ny = y;
        MisAJourDirectionGauche(nx,ny);
        return d_terrain.getCaseTerrain(nx, ny) == OBSTACLE;
    }

    bool robot::arriveeAgauche() const {
        int nx = x, ny = y;
        MisAJourDirectionGauche(nx,ny);
        return d_terrain.getCaseTerrain(nx, ny) == ARRIVEE;
    }

     void robot::MisAJourDirectionDroite(int &x, int &y) const{
        switch (direction) {
        case Nord : x++; break;
        case EST  : y++; break;
        case SUD  : x--; break;
        case OUEST: y--; break;
        }
    }

    bool robot::obstacleAdroite() const {
        int nx = x, ny = y;
        MisAJourDirectionDroite(nx,ny);
        return d_terrain.getCaseTerrain(nx, ny) == OBSTACLE;
    }

    bool robot::arriveeAdroite() const {
        int nx = x, ny = y;
        MisAJourDirectionDroite(nx,ny);
        return d_terrain.getCaseTerrain(nx, ny) == ARRIVEE;
    }
    bool robot::estSurSortie() const {
        auto sortie = d_terrain.getArrivee();
        return (x == sortie.first && y == sortie.second);
    }
    terrain robot::getTerrain() const{
        return d_terrain;
    }

