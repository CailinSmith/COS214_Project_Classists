#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

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
#include "Iterator.h"
#include "SeasonIterator.h"

#include "CeramicPot.h"
#include "ConcretePot.h"
#include "ClayPot.h"
#include "KraftWrapping.h"
#include "ExtraFertilizer.h"

#include "Rose.h"
#include "Basil.h"
#include "Tomato.h"
#include "Lettuce.h"
#include "JadePlant.h"
#include "WaterLily.h"
#include "SnakePlant.h"
#include "AloeVera.h"
#include "Chrysanthemum.h"
#include "Lavender.h"
#include "AppleTree.h"
#include "Pumpkin.h"
#include "BarrelCactus.h"
#include "WaterHyacinth.h"
#include "RubberTree.h"
#include "Coneflower.h"
#include "Pansy.h"
#include "Thyme.h"
#include "Strawberry.h"
#include "Kale.h"
#include "Echeveria.h"
#include "Cattails.h"
#include "PeaceLily.h"
#include "Chamomile.h"
#include "Sunflower.h"
#include "Rosemary.h"
#include "OrangeTree.h"
#include "Cucumber.h"
#include "ChristmasCactus.h"
#include "WaterLettuce.h"
#include "Pothos.h"
#include "Ginger.h"
#include "NurseryStaff.h"
#include "ReadyForSaleState.h"
#include "Summer.h"

using namespace ftxui;

/**
 * @class PlantShopGUI
 * @brief Main GUI class for the plant shop application using FTXUI
 * @author Jordan
 * @author Alex
 */
class PlantShopGUI {
private:
    ScreenInteractive screen;
    
    InventoryManager* inventoryManager;
    Nursery* nursery;
    Customer* customer;
    
    Staff* nurseryStaff;
    Staff* salesStaff;
    Staff* managerStaff;
    
    int mainMenuSelected;
    int categoryMenuSelected;
    int plantListSelected;
    int detailsScrollOffset;
    std::string inputBuffer;
    std::string messageBuffer;
    
    enum View {
        MAIN_MENU,
        VIEW_BY_SELECTION,
        CATEGORY_SELECTION,
        SEASON_SELECTION,
        PLANT_LIST,
        PLANT_DETAILS,
        CART_VIEW,
        DECORATION_MENU,
        CHECKOUT_SUMMARY,
        STOCK_CHECK,
        PAST_ORDERS,
        REFUND_SELECTION,
        REFUND_CONFIRMATION
    };
    View currentView;
    
    int cartListSelected;
    int decorationMenuSelected;
    int viewBySelected;
    int seasonMenuSelected;
    int currentDecoratingIndex;
    bool hasPot;
    bool hasWrapping;
    bool hasFertilizer;
    bool viewingBySeason;
    
    std::vector<bool> refundFlags;
    int refundListSelected;
    std::string refundResultMessage;
    float refundTotal;
    
    //scroll offsets
    int plantListScrollOffset;
    int checkoutScrollOffset;
    int refundScrollOffset;
    
    std::vector<std::string> categories;
    std::vector<std::string> seasons;
    std::string selectedCategory;
    std::string selectedSeason;
    std::vector<Plant*> currentPlants;
    Plant* selectedPlant;
    int selectedOrderIndex;

    // Private helper methods
    void initializePlants();
    void loadPlantsForCategory(const std::string& category);
    void loadPlantsForSeason(const std::string& season);
    void applyDecoration();
    void processMultiItemRefund();
    void showCart();
    void startCheckoutFlow();
    void performActualCheckout();
    
    // Rendering methods
    Element render();
    Element renderMainMenu();
    Element renderViewBySelection();
    Element renderCategorySelection();
    Element renderSeasonSelection();
    Element renderPlantList();
    Element renderPlantDetails();
    Element renderCart();
    Element renderDecorationMenu();
    Element renderCheckoutSummary();
    Element renderStockCheck();
    Element renderPastOrders();
    Element renderRefundSelection();
    Element renderRefundConfirmation();
    
    // Input handling methods
    bool handleInput(Event event);
    bool handleMainMenuInput(Event event);
    bool handleViewByInput(Event event);
    bool handleCategoryInput(Event event);
    bool handleSeasonInput(Event event);
    bool handlePlantListInput(Event event);
    bool handleDetailsInput(Event event);
    bool handleCartInput(Event event);
    bool handleDecorationInput(Event event);
    bool handleCheckoutSummaryInput(Event event);
    bool handlePastOrdersInput(Event event);
    bool handleRefundSelectionInput(Event event);
    bool handleRefundConfirmationInput(Event event);

public:
    /**
     * @brief Constructor - initializes the GUI and all necessary components
     */
    PlantShopGUI();
    
    /**
     * @brief Destructor - cleans up allocated resources
     */
    ~PlantShopGUI();
    
    /**
     * @brief Main entry point to run the GUI application
     */
    void run();
};

#endif // GUI_H
