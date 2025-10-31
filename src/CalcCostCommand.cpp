#include "CalcCostCommand.h"
#include <iostream>

CalcCostCommand::CalcCostCommand(Plant* p, Nursery* n) : StaffCommand(), cost(0.0f) {
    plant = p;
    nursery = n;
}

CalcCostCommand::~CalcCostCommand() {}

void CalcCostCommand::execute() {
    if (plant == nullptr || nursery == nullptr) {
        cost = 0;
        return;
    }
    std::string season = nursery->getSeason();
    cost = plant->calculateCost(season);
    
    
}

float CalcCostCommand::getCost() {
    return cost;
}