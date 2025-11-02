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
 * @author Jordan Naidoo
 * @author Alex Lange
 * @brief
 * Main GUI class for the plant shop application using FTXUI
 * 
 * This class manages the entire graphical user interface for the plant shop,
 * providing an interactive terminal-based interface for customers to browse plants,
 * manage their cart, make purchases, and handle refunds. It integrates with the
 * inventory management system, nursery operations, and staff members.
 * 
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

    /**
     * @brief Initializes the plant inventory with demo plants
     */
    void initializePlants();
    
    /**
     * @brief Loads plants matching a specific category
     * @param category The category name to filter plants by
     */
    void loadPlantsForCategory(const std::string& category);
    
    /**
     * @brief Loads plants matching a specific season
     * @param season The season name to filter plants by
     */
    void loadPlantsForSeason(const std::string& season);
    
    /**
     * @brief Applies decorations to the currently selected plant
     */
    void applyDecoration();
    
    /**
     * @brief Processes refund for multiple items from past orders
     */
    void processMultiItemRefund();
    
    /**
     * @brief Displays the shopping cart view
     */
    void showCart();
    
    /**
     * @brief Initiates the checkout process flow
     */
    void startCheckoutFlow();
    
    /**
     * @brief Performs the actual checkout transaction
     */
    void performActualCheckout();
    
    /**
     * @brief Renders the current view
     * @return Element representing the rendered UI
     */
    Element render();
    
    /**
     * @brief Renders the main menu
     * @return Element representing the main menu UI
     */
    Element renderMainMenu();
    
    /**
     * @brief Renders the view selection menu
     * @return Element representing the view selection UI
     */
    Element renderViewBySelection();
    
    /**
     * @brief Renders the category selection menu
     * @return Element representing the category selection UI
     */
    Element renderCategorySelection();
    
    /**
     * @brief Renders the season selection menu
     * @return Element representing the season selection UI
     */
    Element renderSeasonSelection();
    
    /**
     * @brief Renders the plant list view
     * @return Element representing the plant list UI
     */
    Element renderPlantList();
    
    /**
     * @brief Renders detailed information about a selected plant
     * @return Element representing the plant details UI
     */
    Element renderPlantDetails();
    
    /**
     * @brief Renders the shopping cart
     * @return Element representing the cart UI
     */
    Element renderCart();
    
    /**
     * @brief Renders the decoration menu
     * @return Element representing the decoration menu UI
     */
    Element renderDecorationMenu();
    
    /**
     * @brief Renders the checkout summary
     * @return Element representing the checkout summary UI
     */
    Element renderCheckoutSummary();
    
    /**
     * @brief Renders the stock check view
     * @return Element representing the stock check UI
     */
    Element renderStockCheck();
    
    /**
     * @brief Renders the past orders view
     * @return Element representing the past orders UI
     */
    Element renderPastOrders();
    
    /**
     * @brief Renders the refund selection view
     * @return Element representing the refund selection UI
     */
    Element renderRefundSelection();
    
    /**
     * @brief Renders the refund confirmation view
     * @return Element representing the refund confirmation UI
     */
    Element renderRefundConfirmation();
    
    /**
     * @brief Handles input events
     * @param event The input event to handle
     * @return true if the event was handled, false otherwise
     */
    bool handleInput(Event event);
    
    /**
     * @brief Handles input for the main menu
     * @param event The input event to handle
     * @return true if the event was handled, false otherwise
     */
    bool handleMainMenuInput(Event event);
    
    /**
     * @brief Handles input for the view selection menu
     * @param event The input event to handle
     * @return true if the event was handled, false otherwise
     */
    bool handleViewByInput(Event event);
    
    /**
     * @brief Handles input for the category selection menu
     * @param event The input event to handle
     * @return true if the event was handled, false otherwise
     */
    bool handleCategoryInput(Event event);
    
    /**
     * @brief Handles input for the season selection menu
     * @param event The input event to handle
     * @return true if the event was handled, false otherwise
     */
    bool handleSeasonInput(Event event);
    
    /**
     * @brief Handles input for the plant list view
     * @param event The input event to handle
     * @return true if the event was handled, false otherwise
     */
    bool handlePlantListInput(Event event);
    
    /**
     * @brief Handles input for the plant details view
     * @param event The input event to handle
     * @return true if the event was handled, false otherwise
     */
    bool handleDetailsInput(Event event);
    
    /**
     * @brief Handles input for the cart view
     * @param event The input event to handle
     * @return true if the event was handled, false otherwise
     */
    bool handleCartInput(Event event);
    
    /**
     * @brief Handles input for the decoration menu
     * @param event The input event to handle
     * @return true if the event was handled, false otherwise
     */
    bool handleDecorationInput(Event event);
    
    /**
     * @brief Handles input for the checkout summary
     * @param event The input event to handle
     * @return true if the event was handled, false otherwise
     */
    bool handleCheckoutSummaryInput(Event event);
    
    /**
     * @brief Handles input for the past orders view
     * @param event The input event to handle
     * @return true if the event was handled, false otherwise
     */
    bool handlePastOrdersInput(Event event);
    
    /**
     * @brief Handles input for the refund selection view
     * @param event The input event to handle
     * @return true if the event was handled, false otherwise
     */
    bool handleRefundSelectionInput(Event event);
    
    /**
     * @brief Handles input for the refund confirmation view
     * @param event The input event to handle
     * @return true if the event was handled, false otherwise
     */
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
