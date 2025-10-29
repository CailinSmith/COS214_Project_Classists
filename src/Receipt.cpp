#include "Receipt.h"
#include "Nursery.h"
#include <chrono>
#include <iomanip>
#include <sstream>

Receipt::Receipt(const std::vector<Product*>& plants) : cost(0.0f) {
    // Own a copy of the products list to avoid dangling pointers when the
    // caller modifies or destroys their container.
    this->orderPlants = plants;
    std::stringstream receipt;

    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time_t), "%Y-%m-%d %H:%M:%S");
    date = ss.str();

    const int WIDTH = 60;
    const int NAME_COL = 40;
    auto sep = string(WIDTH, '=');
    receipt << "\n" << sep << "\n";
    // center the store name roughly
    int pad = (WIDTH - (int)string("GreensOnly").length())/2;
    receipt << string(max(0, pad), ' ') << "GreensOnly" << string(max(0, WIDTH - pad - (int)string("GreensOnly").length()), ' ') << "\n";
    receipt << sep << "\n";
    receipt << "Date: " << date << "\n";
    receipt << string(WIDTH, '-') << "\n";

    Nursery* nursery = Nursery::getInstance();
    InventoryManager* im = nullptr;
    std::string season = "";
    if (nursery) {
        im = nursery->getInventoryManager();
        season = nursery->getSeason();
    }

    for (Product* plant : this->orderPlants) {
        if (plant != nullptr) {
            // plant->calculateCost(season); //recalculate if necessary
            cost += plant->getCost();
            std::string name = plant->getName();
    // Use setw to ensure the name column has a fixed width so prices align
    std::ostringstream priceStr;
    priceStr << "$" << std::fixed << std::setprecision(2) << plant->getCost();
    receipt << std::left << std::setw(NAME_COL) << name
        << std::right << std::setw(WIDTH - NAME_COL) << priceStr.str() << "\n";

            Plant* plantPtr = plant->getBasePlant();
            if (plantPtr != nullptr && im != nullptr) {
                im->removeFromSale(plantPtr);
            }
        }
    }

    receipt << string(WIDTH, '-') << "\n";
    std::ostringstream totalLine;
    totalLine << "TOTAL: " << std::fixed << std::setprecision(2) << cost;
    string totalStr = totalLine.str();
    receipt << std::right << std::setw(WIDTH) << totalStr << "\n";
    receipt << sep << "\n";
    // thank you centered
    int thankPad = (WIDTH - (int)string("Thank you for shopping!").length())/2;
    receipt << string(max(0, thankPad), ' ') << "Thank you for shopping!" << "\n";
    receipt << sep << "\n";

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
    return &orderPlants;
}