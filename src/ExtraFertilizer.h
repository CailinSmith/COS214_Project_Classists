#ifndef EXTRAFERTILIZER_H
#define EXTRAFERTILIZER_H

#include "Decorator.h"

class ExtraFertilizer : public Decorator
{
public:
    ExtraFertilizer(Product* plant);
    ~ExtraFertilizer();
    float calculateCost(string currentSeason);
    string getSummary();
    string getName();
};

#endif // EXTRAFERTILIZER_H
