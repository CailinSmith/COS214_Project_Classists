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
 * @see InventoryManager
 * @see Nursery
 * @see Customer
 */
class PlantShopGUI {
private:
    /**
     * @brief FTXUI ScreenInteractive for rendering the GUI
     */
    ScreenInteractive screen;

    /**
     * @brief Inventory manager for managing plant inventory
     */
    InventoryManager* inventoryManager;
    /**
     * @brief Nursery for managing nursery operations
     */
    Nursery* nursery;
    /**
     * @brief Customer using the GUI
     */
    Customer* customer;
    
    /**
     * @brief Staff members for handling various operations
     */
    Staff* nurseryStaff;
    /**
     * @brief Staff members for handling various operations
     */
    Staff* salesStaff;
    /**
     * @brief Staff members for handling various operations
     */
    Staff* managerStaff;
    
    /**
     * @brief Variable for main menu navigation and selections
     */
    int mainMenuSelected;
    /**
     * @brief Variable for category menu navigation and selections
     */
    int categoryMenuSelected;
    /**
     * @brief Variable for plant list navigation and selections
     */
    int plantListSelected;
    /**
     * @brief Variable for details view scrolling
     */
    int detailsScrollOffset;
    /**
     * @brief Input buffer for text input fields
     */
    std::string inputBuffer;
    /**
     * @brief Message buffer for displaying messages to the user
     */
    std::string messageBuffer;
    
    /**
     * @brief Enum representing the different views in the GUI
     */
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
    /**
     * @brief Current view being displayed
     */
    View currentView;
    
    /**
     * Variable for the cart list navigation and selections
    */ 
    int cartListSelected;
    /**
     * Variable for the decoration menu navigation and selections
    */
    int decorationMenuSelected;
    /**
     * Variable for the checkout summary navigation and selections
    */
    int viewBySelected;
    /**
     * Variable for the season menu navigation and selections
    */
    int seasonMenuSelected;
    /**
     * Variable for the decorating index selection
    */
    int currentDecoratingIndex;
    /**
     * Flag for if pot decorations have been applied to the selected plant
    */
    bool hasPot;
    /**
     * Flag for if wrapping decorations have been applied to the selected plant
    */
    bool hasWrapping;
    /**
     * Flag for if fertilizer decorations have been applied to the selected plant
    */
    bool hasFertilizer;
    /**
     * Flag for if viewing by season
    */
    bool viewingBySeason;
    
    /**
     * Variables for refund selection
    */
    std::vector<bool> refundFlags;
    /**
     * Variable for the refund list navigation and selections
    */
    int refundListSelected;
    /**
     * Variable for refund result message
    */
    std::string refundResultMessage;
    /**
     * Variable for refund total amount
    */
    float refundTotal;
    
    /**
     * Scroll offsets for various views
    */
    int plantListScrollOffset;
    /**
     * Scroll offset for checkout summary view
    */
    int checkoutScrollOffset;
    /**
     * Scroll offset for refund confirmation view
    */
    int refundScrollOffset;
    
    /**
     * @brief Lists for categories of plant types
     */
    std::vector<std::string> categories;
    /**
     * @brief Lists for the different seasons
     */
    std::vector<std::string> seasons;
    /**
     * @brief Currently selected category
     */
    std::string selectedCategory;
    /**
     * @brief Currently selected season
     */
    std::string selectedSeason;
    /**
     * @brief Currently loaded plants based on selection
     */
    std::vector<Plant*> currentPlants;
    /**
     * @brief Currently selected plant
     */
    Plant* selectedPlant;
    /**
     * @brief Currently selected order index for past orders
     */
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
