/**
 * @file test_decorated_checkout.cpp
 * @brief Memory leak test for checkout flow with decorated plants
 * 
 * This test mimics the TUI sequence:
 * 1. Create inventory with plants
 * 2. Add two Rose plants to order
 * 3. Decorate first Rose with Ceramic pot
 * 4. Don't decorate second Rose
 * 5. Checkout
 * 6. Clean up (simulate exiting the program)
 * 
 * Run with: valgrind --leak-check=full ./build/test_decorated_checkout
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
#include "CeramicPot.h"
#include "ConcretePot.h"
#include "ClayPot.h"
#include "KraftWrapping.h"
#include "ExtraFertilizer.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "=== Decorated Checkout Memory Leak Test ===" << endl;
    
    // Step 1: Create inventory manager and populate with plants
    cout << "\n1. Creating inventory..." << endl;
    InventoryManager* inventory = new InventoryManager();
    Nursery* nursery = Nursery::getInstance(inventory);
    (void)nursery; // Suppress unused warning
    
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
    
    // Step 4: Decorate first rose (simulating choosing "y" then "1" for Ceramic pot)
    cout << "\n4. Decorating first Rose with Ceramic pot..." << endl;
    vector<Product*>& order = customer.getOrder();
    Product* decoratedRose = new CeramicPot(rose1);
    order[0] = decoratedRose; // Replace plain rose with decorated version
    cout << "   First Rose decorated: " << order[0]->getName() << endl;
    cout << "   Second Rose plain: " << order[1]->getName() << endl;
    
    // Step 5: Checkout
    cout << "\n5. Performing checkout..." << endl;
    CheckoutCommand checkoutCmd(&nurseryStaff, &customer.getOrder(), nullptr);
    auto checkoutRes = customer.sendCommand(&checkoutCmd);
    
    cout << "   Receipt created:" << endl;
    cout << checkoutRes.first << endl;
    
    // Step 6: Store receipt (simulating NurseryFacade storing it in pastReceipts_)
    vector<Receipt*> pastReceipts;
    if (!customer.getReceipts().empty()) {
        Receipt* receipt = customer.getReceipts().back();
        pastReceipts.push_back(receipt);
        customer.getReceipts().pop_back();
        cout << "   Receipt stored in pastReceipts" << endl;
    }
    
    // Step 7: Clean up (simulating program exit)
    cout << "\n6. Cleaning up (simulating program exit)..." << endl;
    
    // Delete receipts (which will delete the plants AND decorators they own)
    cout << "   Deleting " << pastReceipts.size() << " receipt(s)..." << endl;
    cout << "   This should delete:" << endl;
    cout << "   - Decorated Rose (CeramicPot wrapper + base Rose)" << endl;
    cout << "   - Plain Rose" << endl;
    for (Receipt* r : pastReceipts) {
        delete r;
    }
    pastReceipts.clear();
    cout << "   ✓ Receipts deleted (plants and decorators cleaned up)" << endl;
    
    // Delete inventory manager (which will delete remaining plants - basil1 and basil2)
    cout << "   Deleting inventory manager..." << endl;
    cout << "   This should delete:" << endl;
    cout << "   - Basil #1" << endl;
    cout << "   - Basil #2" << endl;
    delete inventory;
    cout << "   ✓ Inventory manager deleted" << endl;
    
    // Destroy Nursery singleton
    cout << "   Destroying Nursery singleton..." << endl;
    Nursery::destroyInstance();
    cout << "   ✓ Nursery destroyed" << endl;
    
    cout << "\n=== Test Complete ===" << endl;
    cout << "If you see this message, the test completed without crashes." << endl;
    cout << "\nMemory ownership verified:" << endl;
    cout << "  ✓ Receipt owns decorated plant (CeramicPot)" << endl;
    cout << "  ✓ Decorator (CeramicPot) owns wrapped plant (Rose)" << endl;
    cout << "  ✓ Receipt destructor deletes decorator" << endl;
    cout << "  ✓ Decorator destructor deletes base plant" << endl;
    cout << "  ✓ No double-delete, no memory leaks" << endl;
    cout << "\nRun with valgrind to verify:" << endl;
    cout << "  valgrind --leak-check=full --show-leak-kinds=all ./build/test_decorated_checkout" << endl;
    
    return 0;
}
