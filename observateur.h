#ifndef OBSERVATEUR_H_INCLUDED
#define OBSERVATEUR_H_INCLUDED

#include <string>
#include <iostream>


class observateurRobot {
public:
    virtual ~observateurRobot() = default;
    virtual void notifier(int x, int y, const char& direction) = 0;
};

class observateurRobotDirection : public observateurRobot {
public:
    observateurRobotDirection();
    void notifier(int x, int y, const char& direction) override;
};

class observateurRobotDeplacements : public observateurRobot {
private :
    int d_nbDeplacements=0;

public:
    observateurRobotDeplacements();
    void notifier(int x, int y, const char& direction) override;
    int nbDeplacements() const;
};

#endif // OBSERVATEUR_H_INCLUDED
