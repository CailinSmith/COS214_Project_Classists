#ifndef AGGREGATE_H
#define AGGREGATE_H

#include "Iterator.h"
#include <string>

class Plant;

/**
 * @class Aggregate
 * @author Alex Lange
 * @brief
 * Design Pattern: Iterator
 * Participant: Aggregate
 * 
 * This abstract class defines the interface for creating iterators. Classes that implement
 * this interface can provide different types of iterators to traverse their collections
 * in various ways (e.g., by season, type, etc.).
 * 
 * @see Iterator
 */
class Aggregate {
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~Aggregate() = default;
    
    /**
     * @brief Creates an iterator for traversing plants by season
     * @param season The season string to filter plants by
     * @return Pointer to a new Iterator object
     */
    virtual Iterator<Plant>* createIterator(const std::string& season) = 0;
};

#endif
