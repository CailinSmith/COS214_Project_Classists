#ifndef KRAFTWRAPPING_H
#define KRAFTWRAPPING_H

#include "Decorator.h"

class KraftWrapping : public Decorator
{
public:
    KraftWrapping(Product* plant);
    ~KraftWrapping();
    float calculateCost(string currentSeason);
    string getSummary();
    string getName();
};

#endif // KRAFTWRAPPING_H
