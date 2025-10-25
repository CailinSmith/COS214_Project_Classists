#ifndef AGGREGATE_H
#define AGGREGATE_H

#include "Iterator.h"

class Plant;

class Aggregate {
public:
    virtual ~Aggregate() = default;
    virtual Iterator<Plant>* createIterator(const std::string& season) = 0;
};

#endif
