#ifndef OBSERVATEUR_H_INCLUDED
#define OBSERVATEUR_H_INCLUDED

#include <string>
#include <iostream>


class observateurRobot
{
public:
    virtual ~observateurRobot() = default;
    virtual void notifier(int x, int y, const char& direction) const;
};

#endif // OBSERVATEUR_H_INCLUDED
