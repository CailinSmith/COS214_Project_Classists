#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

// Include all necessary project headers
#include "Plant.h"
#include "Product.h"
#include "Customer.h"
#include "Staff.h"
#include "Manager.h"
#include "SalesStaff.h"
#include "InventoryManager.h"
#include "Nursery.h"
#include "CheckoutCommand.h"
#include "AskInfoCommand.h"
#include "CheckStockCommand.h"
#include "RefundCommand.h"
#include "Receipt.h"

// Include plant types for initialization
#include "Rose.h"
#include "Basil.h"
#include "Tomato.h"
#include "JadePlant.h"
#include "AloeVera.h"
#include "Chrysanthemum.h"
#include "Lavender.h"
#include "AppleTree.h"
#include "BarrelCactus.h"

using namespace ftxui;

class PlantShopGUI {
private:
    ScreenInteractive screen = ScreenInteractive::Fullscreen();
    
    // Core system objects
    InventoryManager* inventoryManager;
    Nursery* nursery;
    Customer* customer;
    Staff* salesStaff;
    
    // GUI state
    int mainMenuSelected = 0;
    int categoryMenuSelected = 0;
    int plantListSelected = 0;
    std::string inputBuffer;
    std::string messageBuffer;
    
    // Current view state
    enum View {
        MAIN_MENU,
        CATEGORY_SELECTION,
        PLANT_LIST,
        PLANT_DETAILS,
        STOCK_CHECK,
        PAST_ORDERS,
        REFUND_MENU
    };
    View currentView = MAIN_MENU;
    
    // Data for current view
    std::vector<std::string> categories = {
        "Flower", "Herb", "Fruit", "Vegetable", 
        "Succulent", "Aquatic", "Indoor", "Medicinal"
    };
    std::string selectedCategory;
    std::vector<Plant*> currentPlants;
    Plant* selectedPlant = nullptr;
    int selectedOrderIndex = -1;

public:
    PlantShopGUI() {
        // Initialize the nursery system
        inventoryManager = new InventoryManager();
        nursery = Nursery::getInstance(inventoryManager);
        customer = new Customer("John Doe");
        salesStaff = new SalesStaff("Alice");
        
        // Stock some plants for demonstration
        initializePlants();
    }
    
    ~PlantShopGUI() {
        delete customer;
        delete salesStaff;
        delete inventoryManager;
        Nursery::destroyInstance();
    }
    
    void initializePlants() {
        // Add various plants to the sale inventory
        Plant* rose = new Rose();
        Plant* basil = new Basil();
        Plant* tomato = new Tomato();
        Plant* jade = new JadePlant();
        Plant* aloe = new AloeVera();
        Plant* chrys = new Chrysanthemum();
        Plant* lavender = new Lavender();
        Plant* apple = new AppleTree();
        Plant* cactus = new BarrelCactus();
        
        inventoryManager->addToSale(rose);
        inventoryManager->addToSale(basil);
        inventoryManager->addToSale(tomato);
        inventoryManager->addToSale(jade);
        inventoryManager->addToSale(aloe);
        inventoryManager->addToSale(chrys);
        inventoryManager->addToSale(lavender);
        inventoryManager->addToSale(apple);
        inventoryManager->addToSale(cactus);
    }
    
    void run() {
        auto mainComponent = Renderer([&] {
            return renderCurrentView();
        });
        
        auto componentWithExit = CatchEvent(mainComponent, [&](Event event) {
            if (event == Event::Character('q') || event == Event::Escape) {
                screen.ExitLoopClosure()();
                return true;
            }
            return handleInput(event);
        });
        
        screen.Loop(componentWithExit);
    }

private:
    Element renderCurrentView() {
        switch (currentView) {
            case MAIN_MENU:
                return renderMainMenu();
            case CATEGORY_SELECTION:
                return renderCategorySelection();
            case PLANT_LIST:
                return renderPlantList();
            case PLANT_DETAILS:
                return renderPlantDetails();
            case STOCK_CHECK:
                return renderStockCheck();
            case PAST_ORDERS:
                return renderPastOrders();
            case REFUND_MENU:
                return renderRefundMenu();
            default:
                return renderMainMenu();
        }
    }
    
    Element renderMainMenu() {
        std::vector<std::string> options = {
            "1. View Sale Plants",
            "2. View Past Orders",
            "3. View Current Cart",
            "4. Checkout",
            "5. Exit (Press 'q' or ESC)"
        };
        
        Elements menuItems;
        for (size_t i = 0; i < options.size(); i++) {
            if (static_cast<int>(i) == mainMenuSelected) {
                menuItems.push_back(text("► " + options[i]) | color(Color::Green) | bold);
            } else {
                menuItems.push_back(text("  " + options[i]));
            }
        }
        
        auto cartInfo = text("Current cart: " + std::to_string(customer->getOrder().size()) + " items") | 
                        color(Color::Cyan);
        
        return vbox({
            text("🌿 GreensOnly Plant Shop 🌿") | bold | center,
            separator(),
            vbox(menuItems),
            separator(),
            cartInfo,
            text("") | size(HEIGHT, EQUAL, 1),
            text(messageBuffer) | color(Color::Yellow),
            text("Use ↑↓ arrows to navigate, Enter to select") | dim
        }) | border | center;
    }
    
    Element renderCategorySelection() {
        Elements categoryItems;
        for (size_t i = 0; i < categories.size(); i++) {
            if (static_cast<int>(i) == categoryMenuSelected) {
                categoryItems.push_back(text("► " + categories[i]) | color(Color::Green) | bold);
            } else {
                categoryItems.push_back(text("  " + categories[i]));
            }
        }
        
        return vbox({
            text("🌿 Select Plant Category 🌿") | bold | center,
            separator(),
            vbox(categoryItems),
            separator(),
            text("Use ↑↓ arrows to navigate, Enter to select, 'b' to go back") | dim
        }) | border | center;
    }
    
    Element renderPlantList() {
        Elements plantItems;
        
        if (currentPlants.empty()) {
            plantItems.push_back(text("No plants available in this category") | color(Color::Red));
        } else {
            for (size_t i = 0; i < currentPlants.size(); i++) {
                Plant* p = currentPlants[i];
                std::string plantInfo = std::to_string(i + 1) + ". " + p->getName() + 
                                      " - $" + std::to_string(static_cast<int>(p->getCost()));
                
                if (static_cast<int>(i) == plantListSelected) {
                    plantItems.push_back(text("► " + plantInfo) | color(Color::Green) | bold);
                } else {
                    plantItems.push_back(text("  " + plantInfo));
                }
            }
        }
        
        return vbox({
            text("🌿 " + selectedCategory + " Plants 🌿") | bold | center,
            separator(),
            vbox(plantItems),
            separator(),
            text("Options:") | bold,
            text("  [i] - View plant info"),
            text("  [s] - Check stock"),
            text("  [a] - Add to cart"),
            text("  [b] - Back to categories"),
            text("") | size(HEIGHT, EQUAL, 1),
            text(messageBuffer) | color(Color::Yellow),
            text("Use ↑↓ arrows to select plant, then press option key") | dim
        }) | border | center;
    }
    
    Element renderPlantDetails() {
        if (!selectedPlant) {
            return text("No plant selected") | center;
        }
        
        // Get detailed info using the command pattern
        AskInfoCommand* infoCmd = new AskInfoCommand(salesStaff, selectedPlant);
        auto result = customer->sendCommand(infoCmd);
        delete infoCmd;
        
        std::string info = result.first;
        
        return vbox({
            text("🌿 Plant Details 🌿") | bold | center,
            separator(),
            text(info),
            separator(),
            text("Press 'b' to go back") | dim
        }) | border | center;
    }
    
    Element renderStockCheck() {
        if (!selectedPlant) {
            return text("No plant selected") | center;
        }
        
        // Check stock using the command pattern
        CheckStockCommand* stockCmd = new CheckStockCommand(salesStaff, selectedPlant);
        auto result = customer->sendCommand(stockCmd);
        delete stockCmd;
        
        std::string stockInfo = result.first;
        
        return vbox({
            text("🌿 Stock Check 🌿") | bold | center,
            separator(),
            text("Plant: " + selectedPlant->getName()) | bold,
            text("") | size(HEIGHT, EQUAL, 1),
            text(stockInfo),
            separator(),
            text("Press 'b' to go back") | dim
        }) | border | center;
    }
    
    Element renderPastOrders() {
        Elements orderElements;
        auto& receipts = customer->getReceipts();
        
        if (receipts.empty()) {
            orderElements.push_back(text("No past orders") | color(Color::Yellow));
        } else {
            for (size_t i = 0; i < receipts.size(); i++) {
                Receipt* r = receipts[i];
                std::string orderInfo = "Order " + std::to_string(i + 1) + ": " + 
                                       r->getDate() + " - $" + 
                                       std::to_string(static_cast<int>(r->getCost()));
                
                if (static_cast<int>(i) == selectedOrderIndex) {
                    orderElements.push_back(text("► " + orderInfo) | color(Color::Green) | bold);
                } else {
                    orderElements.push_back(text("  " + orderInfo));
                }
            }
        }
        
        return vbox({
            text("🌿 Past Orders 🌿") | bold | center,
            separator(),
            vbox(orderElements),
            separator(),
            text("Options:") | bold,
            text("  [r] - Request refund for selected order"),
            text("  [b] - Back to main menu"),
            text("") | size(HEIGHT, EQUAL, 1),
            text(messageBuffer) | color(Color::Yellow),
            text("Use ↑↓ arrows to select order") | dim
        }) | border | center;
    }
    
    Element renderRefundMenu() {
        auto& receipts = customer->getReceipts();
        
        if (selectedOrderIndex < 0 || selectedOrderIndex >= static_cast<int>(receipts.size())) {
            return vbox({
                text("Invalid order selected") | color(Color::Red),
                text("Press 'b' to go back") | dim
            }) | border | center;
        }
        
        Receipt* selectedReceipt = receipts[selectedOrderIndex];
        const std::vector<Product*>* plants = selectedReceipt->getPlants();
        
        Elements plantElements;
        for (size_t i = 0; i < plants->size(); i++) {
            Product* p = (*plants)[i];
            std::string plantInfo = std::to_string(i + 1) + ". " + p->getName() + 
                                  " - $" + std::to_string(static_cast<int>(p->getCost()));
            plantElements.push_back(text(plantInfo));
        }
        
        return vbox({
            text("🌿 Select Plant to Refund 🌿") | bold | center,
            separator(),
            text("Order Date: " + selectedReceipt->getDate()) | bold,
            text("Total: $" + std::to_string(static_cast<int>(selectedReceipt->getCost()))) | bold,
            separator(),
            vbox(plantElements),
            separator(),
            text("Enter plant number (1-" + std::to_string(plants->size()) + "): " + inputBuffer) | color(Color::Cyan),
            text("Press Enter to submit, 'b' to cancel") | dim,
            text("") | size(HEIGHT, EQUAL, 1),
            text(messageBuffer) | color(Color::Yellow)
        }) | border | center;
    }
    
    bool handleInput(Event event) {
        messageBuffer = ""; // Clear previous messages
        
        switch (currentView) {
            case MAIN_MENU:
                return handleMainMenuInput(event);
            case CATEGORY_SELECTION:
                return handleCategoryInput(event);
            case PLANT_LIST:
                return handlePlantListInput(event);
            case PLANT_DETAILS:
            case STOCK_CHECK:
                return handleDetailsInput(event);
            case PAST_ORDERS:
                return handlePastOrdersInput(event);
            case REFUND_MENU:
                return handleRefundInput(event);
        }
        return false;
    }
    
    bool handleMainMenuInput(Event event) {
        if (event == Event::ArrowUp) {
            mainMenuSelected = std::max(0, mainMenuSelected - 1);
            return true;
        } else if (event == Event::ArrowDown) {
            mainMenuSelected = std::min(4, mainMenuSelected + 1);
            return true;
        } else if (event == Event::Return) {
            switch (mainMenuSelected) {
                case 0: // View Sale Plants
                    currentView = CATEGORY_SELECTION;
                    categoryMenuSelected = 0;
                    break;
                case 1: // View Past Orders
                    currentView = PAST_ORDERS;
                    selectedOrderIndex = 0;
                    break;
                case 2: // View Current Cart
                    showCart();
                    break;
                case 3: // Checkout
                    performCheckout();
                    break;
                case 4: // Exit
                    screen.ExitLoopClosure()();
                    break;
            }
            return true;
        }
        return false;
    }
    
    bool handleCategoryInput(Event event) {
        if (event == Event::ArrowUp) {
            categoryMenuSelected = std::max(0, categoryMenuSelected - 1);
            return true;
        } else if (event == Event::ArrowDown) {
            categoryMenuSelected = std::min(static_cast<int>(categories.size()) - 1, categoryMenuSelected + 1);
            return true;
        } else if (event == Event::Return) {
            selectedCategory = categories[categoryMenuSelected];
            loadPlantsForCategory(selectedCategory);
            currentView = PLANT_LIST;
            plantListSelected = 0;
            return true;
        } else if (event == Event::Character('b') || event == Event::Character('B')) {
            currentView = MAIN_MENU;
            return true;
        }
        return false;
    }
    
    bool handlePlantListInput(Event event) {
        if (currentPlants.empty()) {
            if (event == Event::Character('b') || event == Event::Character('B')) {
                currentView = CATEGORY_SELECTION;
                return true;
            }
            return false;
        }
        
        if (event == Event::ArrowUp) {
            plantListSelected = std::max(0, plantListSelected - 1);
            return true;
        } else if (event == Event::ArrowDown) {
            plantListSelected = std::min(static_cast<int>(currentPlants.size()) - 1, plantListSelected + 1);
            return true;
        } else if (event == Event::Character('i') || event == Event::Character('I')) {
            // View info
            selectedPlant = currentPlants[plantListSelected];
            currentView = PLANT_DETAILS;
            return true;
        } else if (event == Event::Character('s') || event == Event::Character('S')) {
            // Check stock
            selectedPlant = currentPlants[plantListSelected];
            currentView = STOCK_CHECK;
            return true;
        } else if (event == Event::Character('a') || event == Event::Character('A')) {
            // Add to cart
            selectedPlant = currentPlants[plantListSelected];
            customer->addToCart(selectedPlant);
            messageBuffer = "Added " + selectedPlant->getName() + " to cart!";
            return true;
        } else if (event == Event::Character('b') || event == Event::Character('B')) {
            currentView = CATEGORY_SELECTION;
            return true;
        }
        return false;
    }
    
    bool handleDetailsInput(Event event) {
        if (event == Event::Character('b') || event == Event::Character('B')) {
            currentView = PLANT_LIST;
            return true;
        }
        return false;
    }
    
    bool handlePastOrdersInput(Event event) {
        auto& receipts = customer->getReceipts();
        
        if (event == Event::ArrowUp && !receipts.empty()) {
            selectedOrderIndex = std::max(0, selectedOrderIndex - 1);
            return true;
        } else if (event == Event::ArrowDown && !receipts.empty()) {
            selectedOrderIndex = std::min(static_cast<int>(receipts.size()) - 1, selectedOrderIndex + 1);
            return true;
        } else if (event == Event::Character('r') || event == Event::Character('R')) {
            if (!receipts.empty() && selectedOrderIndex >= 0 && selectedOrderIndex < static_cast<int>(receipts.size())) {
                currentView = REFUND_MENU;
                inputBuffer = "";
                return true;
            }
        } else if (event == Event::Character('b') || event == Event::Character('B')) {
            currentView = MAIN_MENU;
            return true;
        }
        return false;
    }
    
    bool handleRefundInput(Event event) {
        if (event == Event::Character('b') || event == Event::Character('B')) {
            currentView = PAST_ORDERS;
            inputBuffer = "";
            return true;
        } else if (event == Event::Return) {
            processRefund();
            return true;
        } else if (event == Event::Backspace) {
            if (!inputBuffer.empty()) {
                inputBuffer.pop_back();
            }
            return true;
        } else if (event.is_character() && std::isdigit(event.character()[0])) {
            inputBuffer += event.character();
            return true;
        }
        return false;
    }
    
    void loadPlantsForCategory(const std::string& category) {
        currentPlants.clear();
        const auto& allPlants = inventoryManager->getForSalePlants();
        
        for (Plant* p : allPlants) {
            if (p->getCategory() == category) {
                currentPlants.push_back(p);
            }
        }
    }
    
    void showCart() {
        auto& order = customer->getOrder();
        if (order.empty()) {
            messageBuffer = "Cart is empty!";
        } else {
            messageBuffer = "Cart has " + std::to_string(order.size()) + " items. Total: $" + 
                          std::to_string(static_cast<int>(customer->totalCost()));
        }
    }
    
    void performCheckout() {
        auto& order = customer->getOrder();
        if (order.empty()) {
            messageBuffer = "Cannot checkout - cart is empty!";
            return;
        }
        
        // Create flags vector (all true for successful checkout)
        std::vector<bool> flags(order.size(), true);
        
        CheckoutCommand* checkoutCmd = new CheckoutCommand(salesStaff, &order, &flags);
        auto result = customer->sendCommand(checkoutCmd);
        delete checkoutCmd;
        
        if (result.second != nullptr) {
            messageBuffer = "Checkout successful! Total: $" + std::to_string(static_cast<int>(result.second->getCost()));
        } else {
            messageBuffer = "Checkout completed: " + result.first;
        }
    }
    
    void processRefund() {
        if (inputBuffer.empty()) {
            messageBuffer = "Please enter a plant number";
            return;
        }
        
        try {
            int plantNum = std::stoi(inputBuffer);
            auto& receipts = customer->getReceipts();
            
            if (selectedOrderIndex < 0 || selectedOrderIndex >= static_cast<int>(receipts.size())) {
                messageBuffer = "Invalid order selected";
                return;
            }
            
            Receipt* selectedReceipt = receipts[selectedOrderIndex];
            const std::vector<Product*>* plants = selectedReceipt->getPlants();
            
            if (plantNum < 1 || plantNum > static_cast<int>(plants->size())) {
                messageBuffer = "Invalid plant number";
                return;
            }
            
            // Create a vector with the selected receipt's plants and flags
            std::vector<Product*> refundOrder = *plants;
            std::vector<bool> flags(refundOrder.size(), false);
            flags[plantNum - 1] = true; // Only refund the selected plant
            
            RefundCommand* refundCmd = new RefundCommand(salesStaff, &refundOrder, &flags);
            auto result = customer->sendCommand(refundCmd);
            delete refundCmd;
            
            messageBuffer = "Refund request sent: " + result.first;
            inputBuffer = "";
            currentView = PAST_ORDERS;
            
        } catch (const std::exception& e) {
            messageBuffer = "Invalid input";
        }
    }
};

int main() {
    PlantShopGUI gui;
    gui.run();
    return 0;
}
