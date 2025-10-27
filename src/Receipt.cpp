#include "Receipt.h"
#include "Nursery.h"
#include <chrono>
#include <iomanip>
#include <sstream>

Receipt::Receipt(const std::vector<Product*>& plants) : cost(0.0f) {
    this->orderPlants = &plants;
    std::stringstream receipt;
    
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time_t), "%Y-%m-%d %H:%M:%S");
    date = ss.str();
    
    receipt << "===============================\n";
    receipt << "           GreensOnly          \n";
    receipt << "===============================\n";
    receipt << "Date: " << date << "\n";
    receipt << "-------------------------------\n";

    Nursery* nursery = Nursery::getInstance();
    InventoryManager* im = nursery->getInventoryManager();
    std::string season = nursery->getSeason();
    
    for (Product* plant : plants) {
        if (plant != nullptr) {
            plant->calculateCost(season); //recalculate if necessary
            cost += plant->getCost();
            receipt << plant->getName() << std::string(20 - plant->getName().length(), ' ') 
                    << "$" << std::fixed << std::setprecision(2) << plant->getCost() << "\n";
            
            Plant* plantPtr = plant->getBasePlant();
            if (plantPtr != nullptr) {
                im->removeFromSale(plantPtr);
            }
        }
    }
    
    receipt << "-------------------------------\n";
    receipt << "TOTAL:" << std::string(15, ' ') << "$" << std::fixed << std::setprecision(2) << cost << "\n";
    receipt << "===============================\n";
    receipt << "     Thank you for shopping!   \n";
    receipt << "===============================\n";
    
    receiptContent = receipt.str();
}

Receipt::~Receipt() {}

float Receipt::getCost() const {
    return cost;
}

std::string Receipt::getDate() const {
    return date;
}

std::string Receipt::toString() const {
    return receiptContent;
}

const std::vector<Product*>* Receipt::getPlants() const{
    return orderPlants;
}