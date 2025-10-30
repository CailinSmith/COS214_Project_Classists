#ifndef CLAYPOT_H
#define CLAYPOT_H

#include "Decorator.h"

class ClayPot : public Decorator
{
public:
    ClayPot(Product* plant);
    ~ClayPot();
    float calculateCost(string currentSeason);
    string summary();
    string getName();
};

#endif // CLAYPOT_H