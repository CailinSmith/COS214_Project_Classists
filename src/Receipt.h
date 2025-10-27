/**
 * @file Receipt.h
 * @author Cailin Smith
 * @date 2025-10-22
 */

#ifndef RECEIPT_H
#define RECEIPT_H

#include "Plant.h"
#include "Product.h"
#include <vector>
#include <string>

class Receipt {
private:
    float cost;
    std::string date;
    std::string receiptContent; 
    const std::vector<Product*>* orderPlants;

public:
    Receipt(const std::vector<Product*>& plants);
    ~Receipt();
    float getCost() const;
    std::string getDate() const;
    std::string toString() const;
    const std::vector<Product*>* getPlants() const;
};

#endif