/**
 * @file test_checkout_memory.cpp
 * @brief Memory leak test for checkout flow with decorated plants
 * 
 * This test mimics the TUI sequence:
 * 1. Create inventory with plants
 * 2. Add two Rose plants to order
 * 3. Checkout without decoration
 * 4. Clean up (simulate exiting the program)
 * 
 * Run with: valgrind --leak-check=full ./build/test_checkout_memory
 */

#include "InventoryManager.h"
#include "Nursery.h"
#include "NurseryStaff.h"
#include "SalesStaff.h"
#include "Manager.h"
#include "Customer.h"
#include "CheckoutCommand.h"
#include "Receipt.h"
#include "Rose.h"
#include "Basil.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "=== Checkout Memory Leak Test ===" << endl;
    
    // Step 1: Create inventory manager and populate with plants
    cout << "\n1. Creating inventory..." << endl;
    InventoryManager* inventory = new InventoryManager();
    Nursery* nursery = Nursery::getInstance(inventory);
    
    // Add some plants to sale (like populateDemoInventory would do)
    Rose* rose1 = new Rose();
    Rose* rose2 = new Rose();
    Basil* basil1 = new Basil();
    Basil* basil2 = new Basil();
    
    inventory->addToSale(rose1);
    inventory->addToSale(rose2);
    inventory->addToSale(basil1);
    inventory->addToSale(basil2);
    
    cout << "   Added 4 plants to sale inventory" << endl;
    
    // Step 2: Create staff chain
    cout << "\n2. Creating staff chain..." << endl;
    NurseryStaff nurseryStaff("Alice");
    SalesStaff salesStaff("Bob");
    Manager manager("Charles");
    nurseryStaff.setNext(&salesStaff);
    salesStaff.setNext(&manager);
    
    // Step 3: Create customer and add plants to cart (simulating "a1" and "a2" commands)
    cout << "\n3. Customer adding plants to cart..." << endl;
    Customer customer("TestCustomer");
    customer.addToCart(rose1);
    customer.addToCart(rose2);
    cout << "   Customer cart: " << customer.getOrder().size() << " items" << endl;
    
    // Step 4: Checkout (simulating choosing "n" for decoration)
    cout << "\n4. Performing checkout..." << endl;
    CheckoutCommand checkoutCmd(&nurseryStaff, &customer.getOrder(), nullptr);
    auto checkoutRes = customer.sendCommand(&checkoutCmd);
    
    cout << "   Receipt created:" << endl;
    cout << checkoutRes.first << endl;
    
    // Step 5: Store receipt (simulating NurseryFacade storing it in pastReceipts_)
    vector<Receipt*> pastReceipts;
    if (!customer.getReceipts().empty()) {
        Receipt* receipt = customer.getReceipts().back();
        pastReceipts.push_back(receipt);
        customer.getReceipts().pop_back();
        cout << "   Receipt stored in pastReceipts" << endl;
    }
    
    // Step 6: Clean up (simulating program exit)
    cout << "\n5. Cleaning up (simulating program exit)..." << endl;
    
    // Delete receipts (which will delete the plants they own)
    cout << "   Deleting " << pastReceipts.size() << " receipt(s)..." << endl;
    for (Receipt* r : pastReceipts) {
        delete r;
    }
    pastReceipts.clear();
    cout << "   Receipts deleted" << endl;
    
    // Delete inventory manager (which will delete remaining plants)
    cout << "   Deleting inventory manager..." << endl;
    delete inventory;
    cout << "   Inventory manager deleted" << endl;
    
    // Destroy Nursery singleton
    cout << "   Destroying Nursery singleton..." << endl;
    Nursery::destroyInstance();
    cout << "   Nursery destroyed" << endl;
    
    cout << "\n=== Test Complete ===" << endl;
    cout << "If you see this message, the test completed without crashes." << endl;
    cout << "Run with valgrind to check for memory leaks:" << endl;
    cout << "  valgrind --leak-check=full --show-leak-kinds=all ./build/test_checkout_memory" << endl;
    
    return 0;
}
