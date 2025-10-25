#ifndef SEASONITERATOR_H
#define SEASONITERATOR_H

#include "Iterator.h"
#include "Plant.h"
#include <vector>
#include <string>

class SeasonIterator : public Iterator<Plant> {
private:
    std::vector<Plant*> plants;
    std::string targetSeason;
    size_t currentIndex;
    
    void findNextSeasonMatch();

public:
    SeasonIterator(const std::vector<Plant*>& plantList, const std::string& season);
    virtual Plant* first() override;
    virtual Plant* next() override;
    virtual bool isDone() const override;
    virtual Plant* currentItem() const override;
};

#endif
