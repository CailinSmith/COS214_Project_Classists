#ifndef STAFFCHECKOUTCOMMAND_H
#define STAFFCHECKOUTCOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"
#include "Product.h"
#include "Receipt.h"
#include <vector>

/**
 * @class StaffCheckoutCommand
 * @author Cailin Smith
 * @brief Command for processing customer checkout.
 * Design Pattern: Command
 * Participant: ConcreteCommand
 * 
 * This class encapsulates a checkout request as a command object.
 * It allows staff to process a customer's purchase by creating a
 * receipt for the selected products.
 * 
 * @see StaffCommand
 * @see Product
 * @see Receipt
 */
class StaffCheckoutCommand : public StaffCommand {
private:
	/**
	 * @brief Vector of products being purchased.
	 */
    std::vector<Product*> plants;
    
	/**
	 * @brief Pointer to the generated receipt.
	 */
    Receipt* receipt;

public:
	/**
	 * @brief Constructs a StaffCheckoutCommand.
	 * @param p Vector of products to checkout.
	 */
    StaffCheckoutCommand(const std::vector<Product*>& p);
    
    /**
     * @brief Destructor for the StaffCheckoutCommand.
     */
    virtual ~StaffCheckoutCommand();
    
    /**
     * @brief Executes the checkout command.
     * 
     * Creates a receipt for the products being purchased.
     */
    void execute() override;
    
    /**
     * @brief Gets the generated receipt.
     * @return Receipt* Pointer to the receipt created during checkout.
     */
    Receipt* getReceipt();
};

#endif