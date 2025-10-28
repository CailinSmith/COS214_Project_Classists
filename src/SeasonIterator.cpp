#include "SeasonIterator.h"
#include <iostream>

SeasonIterator::SeasonIterator(const std::vector<Plant*>& plantList, const std::string& season) 
    : plants(plantList), targetSeason(season), currentIndex(0) {
    findNextSeasonMatch();
}

Plant* SeasonIterator::first() {
    currentIndex = 0;
    findNextSeasonMatch();
    return currentItem();
}

Plant* SeasonIterator::next() {
    if(!isDone())
    {
        currentIndex++;
        findNextSeasonMatch();
    }
    return currentItem();
}

bool SeasonIterator::isDone() const {
    return currentIndex >= plants.size();
}

Plant* SeasonIterator::currentItem() const {
    if(isDone())
    {
        return nullptr;
    }
    return plants[currentIndex];
}

void SeasonIterator::findNextSeasonMatch() {
    while(currentIndex < plants.size())
    {
        Plant* plant = plants[currentIndex];
        if (plant != nullptr && plant->getSellSeason() == targetSeason) {
            break;
        }
        currentIndex++;
    }
}