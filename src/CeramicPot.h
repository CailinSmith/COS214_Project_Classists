#ifndef CERAMICPOT_H
#define CERAMICPOT_H

#include "Decorator.h"

class CeramicPot : public Decorator
{
public:
    CeramicPot(Product* plant);
    ~CeramicPot();
    float calculateCost(string currentSeason);
    string summary();
    string getName();
};

#endif // CERAMICPOT_H
