#ifndef RECEIPT_H
#define RECEIPT_H

#include "Plant.h"
#include "Product.h"
#include <vector>
#include <string>

/**
 * @class Receipt
 * @author Cailin Smith
 * @brief Represents a purchase receipt for plant products.
 * 
 * This class manages a receipt for customer purchases, tracking the products
 * ordered, total cost, and date of purchase. It provides functionality to
 * generate receipt content, remove products, and retrieve receipt information.
 * 
 * @see Product
 * @see Plant
 */
class Receipt {
private:
	/**
	 * @brief Total cost of all products on the receipt.
	 */
    float cost;
    
	/**
	 * @brief Date when the receipt was created.
	 */
    std::string date;
    
	/**
	 * @brief Formatted string representation of the receipt.
	 */
    std::string receiptContent; 
    
	/**
	 * @brief Vector of all products on this receipt.
	 */
    std::vector<Product*> orderPlants;
    
    /**
     * @brief Regenerates the receipt content string.
     * 
     * Updates the receiptContent based on current products and cost.
     */
    void regenerateReceiptContent();

public:
	/**
	 * @brief Constructs a Receipt with the given products.
	 * @param plants Vector of products to include on the receipt.
	 */
    Receipt(const std::vector<Product*>& plants);
    
    /**
     * @brief Destructor for the Receipt.
     */
    ~Receipt();
    
    /**
     * @brief Gets the total cost of the receipt.
     * @return float Total cost of all products.
     */
    float getCost() const;
    
    /**
     * @brief Gets the receipt date.
     * @return std::string Date of the receipt.
     */
    std::string getDate() const;
    
    /**
     * @brief Gets the formatted receipt content.
     * @return std::string String representation of the receipt.
     */
    std::string toString() const;
    
    /**
     * @brief Gets the list of products on the receipt.
     * @return const std::vector<Product*>* Pointer to the vector of products.
     */
    const std::vector<Product*>* getPlants() const;
    
    /**
     * @brief Removes a product from the receipt.
     * @param product Pointer to the product to remove.
     * @return Product* Pointer to the removed product, or nullptr if not found.
     */
    Product* removeProduct(Product* product);
};

#endif