#ifndef SEASONITERATOR_H
#define SEASONITERATOR_H

#include "Iterator.h"
#include "Plant.h"
#include <vector>
#include <string>

/**
 * @class SeasonIterator
 * @author Alex Lange
 * @brief
 * Design Pattern: Iterator
 * Participant: Concrete Iterator
 * 
 * This class implements the Iterator pattern to provide sequential access to Plant objects
 * that match a specific season. It filters plants from a collection and allows iteration
 * over only those plants that are associated with the target season.
 * 
 * @see Iterator
 */
class SeasonIterator : public Iterator<Plant> {
private:
    /**
     * @brief Vector of Plant pointers to iterate through
     */
    std::vector<Plant*> plants;
    /**
     * @brief The target season to filter plants by
     */
    std::string targetSeason;
    /**
     * @brief Current index in the plants vector
     */
    size_t currentIndex;
    
    /**
     * @brief Finds the next plant that matches the target season
     */
    void findNextSeasonMatch();

public:
    /**
     * @brief Constructs a SeasonIterator with a list of plants and target season
     * @param plantList Vector of Plant pointers to iterate through
     * @param season The season string to filter plants by
     */
    SeasonIterator(const std::vector<Plant*>& plantList, const std::string& season);
    
    /**
     * @brief Returns the first plant matching the target season
     * @return Pointer to the first matching Plant, or nullptr if none found
     */
    virtual Plant* first() override;
    
    /**
     * @brief Advances to and returns the next plant matching the target season
     * @return Pointer to the next matching Plant, or nullptr if iteration is complete
     */
    virtual Plant* next() override;
    
    /**
     * @brief Checks if the iteration has completed
     * @return true if iteration is complete, false otherwise
     */
    virtual bool isDone() const override;
    
    /**
     * @brief Returns the current plant in the iteration
     * @return Pointer to the current Plant, or nullptr if invalid position
     */
    virtual Plant* currentItem() const override;
};

#endif
