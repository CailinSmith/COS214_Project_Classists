#include "CalcCostCommand.h"
#include <iostream>

CalcCostCommand::CalcCostCommand(Plant* p, Nursery* n) : StaffCommand(p, nullptr, n), cost(0.0f) {
}

CalcCostCommand::~CalcCostCommand() {}

void CalcCostCommand::execute() {
    if (plant == nullptr || nursery == nullptr) {
        cost = 0;
    }
    std::string season = nursery->getSeason();
    cost = plant->calculateCost(season);
}

float CalcCostCommand::getCost() {
    return cost;
}