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

// Include all 32 plant types for initialization
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

class PlantShopGUI {
private:
    ScreenInteractive screen = ScreenInteractive::Fullscreen();
    
    InventoryManager* inventoryManager;
    Nursery* nursery;
    Customer* customer;
    
    // Chain of Responsibility: nursery -> sales -> manager
    Staff* nurseryStaff;
    Staff* salesStaff;
    Staff* managerStaff;
    
    int mainMenuSelected = 0;
    int categoryMenuSelected = 0;
    int plantListSelected = 0;
    int detailsScrollOffset = 0;
    std::string inputBuffer;
    std::string messageBuffer;
    
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
        inventoryManager = new InventoryManager();
        nursery = Nursery::getInstance(inventoryManager);
        customer = new Customer("John Doe");
        
        // Set up Chain of Responsibility: nursery -> sales -> manager
        nurseryStaff = new NurseryStaff("Nina");
        salesStaff = new SalesStaff("Sam");
        managerStaff = new Manager("Mike");
        nurseryStaff->setNext(salesStaff);
        salesStaff->setNext(managerStaff);

        nursery->setSeason(new Summer());
        
        initializePlants();
    }
    
    ~PlantShopGUI() {
        delete customer;
        delete nurseryStaff;
        delete salesStaff;
        delete managerStaff;
        delete inventoryManager;
        Nursery::destroyInstance();
    }
    
    // Initialize 2 of each of the 32 plant types with appropriate values for ReadyForSaleState state
    void initializePlants() {
        // Get current season from nursery
        std::string currentSeason = nursery->getSeason();
        
        // Helper lambda to set up a plant for ReadyForSaleState state
        // Values are now decimals: height (0.8-1.0), health (0.7-1.0), waterLevel (0.9-1.0)
        auto setupPlant = [&currentSeason](Plant* p, float height, float health, float waterLevel) {
            p->setHeight(height);
            p->setHealth(health);
            p->setWaterLevel(waterLevel);
            p->setPruned(true);
            p->setState(new ReadyForSaleState());
            p->calculateCost(currentSeason);
        };
        
        // Create 2 of each plant type with slightly different values
        // At least one of each pair has health >= 0.9
        
        Plant* rose1 = new Rose(); setupPlant(rose1, 0.85, 0.90, 0.95);
        Plant* rose2 = new Rose(); setupPlant(rose2, 0.92, 0.88, 0.98);
        
        Plant* chrys1 = new Chrysanthemum(); setupPlant(chrys1, 0.83, 0.92, 0.93);
        Plant* chrys2 = new Chrysanthemum(); setupPlant(chrys2, 0.89, 0.86, 0.96);
        
        Plant* pansy1 = new Pansy(); setupPlant(pansy1, 0.81, 0.80, 0.91);
        Plant* pansy2 = new Pansy(); setupPlant(pansy2, 0.87, 0.93, 0.94);
        
        Plant* cone1 = new Coneflower(); setupPlant(cone1, 0.90, 0.87, 0.97);
        Plant* cone2 = new Coneflower(); setupPlant(cone2, 0.95, 0.91, 0.99);
        
        Plant* sun1 = new Sunflower(); setupPlant(sun1, 0.94, 0.89, 0.95);
        Plant* sun2 = new Sunflower(); setupPlant(sun2, 0.98, 0.92, 0.98);
        
        Plant* basil1 = new Basil(); setupPlant(basil1, 0.82, 0.90, 0.92);
        Plant* basil2 = new Basil(); setupPlant(basil2, 0.86, 0.85, 0.95);
        
        Plant* lav1 = new Lavender(); setupPlant(lav1, 0.84, 0.91, 0.94);
        Plant* lav2 = new Lavender(); setupPlant(lav2, 0.88, 0.87, 0.97);
        
        Plant* thyme1 = new Thyme(); setupPlant(thyme1, 0.80, 0.81, 0.91);
        Plant* thyme2 = new Thyme(); setupPlant(thyme2, 0.85, 0.92, 0.93);
        
        Plant* rose_m1 = new Rosemary(); setupPlant(rose_m1, 0.83, 0.82, 0.92);
        Plant* rose_m2 = new Rosemary(); setupPlant(rose_m2, 0.87, 0.93, 0.95);
        
        Plant* tom1 = new Tomato(); setupPlant(tom1, 0.86, 0.85, 0.94);
        Plant* tom2 = new Tomato(); setupPlant(tom2, 0.91, 0.90, 0.97);
        
        Plant* let1 = new Lettuce(); setupPlant(let1, 0.81, 0.80, 0.91);
        Plant* let2 = new Lettuce(); setupPlant(let2, 0.84, 0.91, 0.93);
        
        Plant* kale1 = new Kale(); setupPlant(kale1, 0.82, 0.92, 0.92);
        Plant* kale2 = new Kale(); setupPlant(kale2, 0.86, 0.84, 0.95);
        
        Plant* cuc1 = new Cucumber(); setupPlant(cuc1, 0.84, 0.83, 0.93);
        Plant* cuc2 = new Cucumber(); setupPlant(cuc2, 0.88, 0.91, 0.96);
        
        Plant* apple1 = new AppleTree(); setupPlant(apple1, 0.93, 0.88, 0.96);
        Plant* apple2 = new AppleTree(); setupPlant(apple2, 0.97, 0.92, 0.99);
        
        Plant* pump1 = new Pumpkin(); setupPlant(pump1, 0.87, 0.84, 0.94);
        Plant* pump2 = new Pumpkin(); setupPlant(pump2, 0.91, 0.90, 0.97);
        
        Plant* straw1 = new Strawberry(); setupPlant(straw1, 0.82, 0.81, 0.91);
        Plant* straw2 = new Strawberry(); setupPlant(straw2, 0.86, 0.92, 0.94);
        
        Plant* orange1 = new OrangeTree(); setupPlant(orange1, 0.96, 0.93, 0.97);
        Plant* orange2 = new OrangeTree(); setupPlant(orange2, 0.99, 0.95, 0.99);
        
        Plant* jade1 = new JadePlant(); setupPlant(jade1, 0.83, 0.90, 0.92);
        Plant* jade2 = new JadePlant(); setupPlant(jade2, 0.87, 0.86, 0.95);
        
        Plant* cact1 = new BarrelCactus(); setupPlant(cact1, 0.84, 0.91, 0.91);
        Plant* cact2 = new BarrelCactus(); setupPlant(cact2, 0.88, 0.87, 0.94);
        
        Plant* echev1 = new Echeveria(); setupPlant(echev1, 0.80, 0.80, 0.90);
        Plant* echev2 = new Echeveria(); setupPlant(echev2, 0.83, 0.92, 0.93);
        
        Plant* xmas1 = new ChristmasCactus(); setupPlant(xmas1, 0.82, 0.82, 0.91);
        Plant* xmas2 = new ChristmasCactus(); setupPlant(xmas2, 0.86, 0.93, 0.94);
        
        Plant* wlily1 = new WaterLily(); setupPlant(wlily1, 0.81, 0.85, 0.95);
        Plant* wlily2 = new WaterLily(); setupPlant(wlily2, 0.85, 0.91, 0.98);
        
        Plant* whya1 = new WaterHyacinth(); setupPlant(whya1, 0.83, 0.86, 0.96);
        Plant* whya2 = new WaterHyacinth(); setupPlant(whya2, 0.87, 0.92, 0.99);
        
        Plant* cat1 = new Cattails(); setupPlant(cat1, 0.91, 0.87, 0.97);
        Plant* cat2 = new Cattails(); setupPlant(cat2, 0.95, 0.93, 0.99);
        
        Plant* wlet1 = new WaterLettuce(); setupPlant(wlet1, 0.81, 0.84, 0.95);
        Plant* wlet2 = new WaterLettuce(); setupPlant(wlet2, 0.84, 0.91, 0.98);
        
        Plant* snake1 = new SnakePlant(); setupPlant(snake1, 0.85, 0.83, 0.92);
        Plant* snake2 = new SnakePlant(); setupPlant(snake2, 0.89, 0.90, 0.95);
        
        Plant* rubber1 = new RubberTree(); setupPlant(rubber1, 0.92, 0.88, 0.94);
        Plant* rubber2 = new RubberTree(); setupPlant(rubber2, 0.96, 0.92, 0.97);
        
        Plant* peace1 = new PeaceLily(); setupPlant(peace1, 0.83, 0.84, 0.96);
        Plant* peace2 = new PeaceLily(); setupPlant(peace2, 0.87, 0.91, 0.99);
        
        Plant* pothos1 = new Pothos(); setupPlant(pothos1, 0.86, 0.85, 0.93);
        Plant* pothos2 = new Pothos(); setupPlant(pothos2, 0.90, 0.92, 0.96);
        
        Plant* aloe1 = new AloeVera(); setupPlant(aloe1, 0.82, 0.82, 0.92);
        Plant* aloe2 = new AloeVera(); setupPlant(aloe2, 0.86, 0.91, 0.95);
        
        Plant* cham1 = new Chamomile(); setupPlant(cham1, 0.81, 0.81, 0.91);
        Plant* cham2 = new Chamomile(); setupPlant(cham2, 0.85, 0.93, 0.94);
        
        Plant* ging1 = new Ginger(); setupPlant(ging1, 0.84, 0.83, 0.94);
        Plant* ging2 = new Ginger(); setupPlant(ging2, 0.88, 0.92, 0.97);
        
        // Add all plants to inventory for sale
        inventoryManager->addToSale(rose1); inventoryManager->addToSale(rose2);
        inventoryManager->addToSale(chrys1); inventoryManager->addToSale(chrys2);
        inventoryManager->addToSale(pansy1); inventoryManager->addToSale(pansy2);
        inventoryManager->addToSale(cone1); inventoryManager->addToSale(cone2);
        inventoryManager->addToSale(sun1); inventoryManager->addToSale(sun2);
        inventoryManager->addToSale(basil1); inventoryManager->addToSale(basil2);
        inventoryManager->addToSale(lav1); inventoryManager->addToSale(lav2);
        inventoryManager->addToSale(thyme1); inventoryManager->addToSale(thyme2);
        inventoryManager->addToSale(rose_m1); inventoryManager->addToSale(rose_m2);
        inventoryManager->addToSale(tom1); inventoryManager->addToSale(tom2);
        inventoryManager->addToSale(let1); inventoryManager->addToSale(let2);
        inventoryManager->addToSale(kale1); inventoryManager->addToSale(kale2);
        inventoryManager->addToSale(cuc1); inventoryManager->addToSale(cuc2);
        inventoryManager->addToSale(apple1); inventoryManager->addToSale(apple2);
        inventoryManager->addToSale(pump1); inventoryManager->addToSale(pump2);
        inventoryManager->addToSale(straw1); inventoryManager->addToSale(straw2);
        inventoryManager->addToSale(orange1); inventoryManager->addToSale(orange2);
        inventoryManager->addToSale(jade1); inventoryManager->addToSale(jade2);
        inventoryManager->addToSale(cact1); inventoryManager->addToSale(cact2);
        inventoryManager->addToSale(echev1); inventoryManager->addToSale(echev2);
        inventoryManager->addToSale(xmas1); inventoryManager->addToSale(xmas2);
        inventoryManager->addToSale(wlily1); inventoryManager->addToSale(wlily2);
        inventoryManager->addToSale(whya1); inventoryManager->addToSale(whya2);
        inventoryManager->addToSale(cat1); inventoryManager->addToSale(cat2);
        inventoryManager->addToSale(wlet1); inventoryManager->addToSale(wlet2);
        inventoryManager->addToSale(snake1); inventoryManager->addToSale(snake2);
        inventoryManager->addToSale(rubber1); inventoryManager->addToSale(rubber2);
        inventoryManager->addToSale(peace1); inventoryManager->addToSale(peace2);
        inventoryManager->addToSale(pothos1); inventoryManager->addToSale(pothos2);
        inventoryManager->addToSale(aloe1); inventoryManager->addToSale(aloe2);
        inventoryManager->addToSale(cham1); inventoryManager->addToSale(cham2);
        inventoryManager->addToSale(ging1); inventoryManager->addToSale(ging2);
    }
    
    struct ColoredChar {
        std::string ch;  // Changed to string to support UTF-8 multi-byte characters (blocks, etc.)
        int fgColor; // RGB packed as int (R<<16 | G<<8 | B)
        int bgColor; // RGB packed as int
        
        ColoredChar(std::string c = " ", int fg = 0xFFFFFF, int bg = 0x000000) : ch(c), fgColor(fg), bgColor(bg) {}
    };
    
    // Parse ANSI color codes and extract colored characters
    std::vector<std::vector<ColoredChar>> parseAnsiImage(const std::string& ansiText) {
        std::vector<std::vector<ColoredChar>> result;
        std::vector<ColoredChar> currentLine;
        
        int currentFgR = 255, currentFgG = 255, currentFgB = 255;
        int currentBgR = 0, currentBgG = 0, currentBgB = 0;
        
        for (size_t i = 0; i < ansiText.length(); i++) {
            if (ansiText[i] == '\033' || ansiText[i] == '\x1b') {
                // Found escape sequence, parse it
                if (i + 1 < ansiText.length() && ansiText[i + 1] == '[') {
                    i += 2; // Skip ESC[
                    std::string code;
                    while (i < ansiText.length() && ansiText[i] != 'm' && ansiText[i] != 'l' && ansiText[i] != 'h') {
                        code += ansiText[i];
                        i++;
                    }
                    
                    // Skip non-color escape sequences (like cursor hide/show)
                    if (i < ansiText.length() && (ansiText[i] == 'l' || ansiText[i] == 'h')) {
                        continue;
                    }
                    
                    // Parse RGB color codes: 38;2;R;G;B for foreground, 48;2;R;G;B for background
                    std::vector<int> numbers;
                    std::string num;
                    for (char c : code) {
                        if (c == ';') {
                            if (!num.empty()) {
                                numbers.push_back(std::stoi(num));
                                num.clear();
                            }
                        } else if (std::isdigit(c)) {
                            num += c;
                        }
                    }
                    if (!num.empty()) {
                        numbers.push_back(std::stoi(num));
                    }
                    
                    // Process the numbers
                    for (size_t j = 0; j < numbers.size(); j++) {
                        if (numbers[j] == 0) {
                            // Reset
                            currentFgR = currentFgG = currentFgB = 255;
                            currentBgR = currentBgG = currentBgB = 0;
                        } else if (numbers[j] == 38 && j + 4 < numbers.size() && numbers[j + 1] == 2) {
                            // Foreground RGB: 38;2;R;G;B
                            currentFgR = numbers[j + 2];
                            currentFgG = numbers[j + 3];
                            currentFgB = numbers[j + 4];
                            j += 4;
                        } else if (numbers[j] == 48 && j + 4 < numbers.size() && numbers[j + 1] == 2) {
                            // Background RGB: 48;2;R;G;B
                            currentBgR = numbers[j + 2];
                            currentBgG = numbers[j + 3];
                            currentBgB = numbers[j + 4];
                            j += 4;
                        }
                    }
                }
            } else if (ansiText[i] == '\n') {
                if (!currentLine.empty()) {
                    result.push_back(currentLine);
                    currentLine.clear();
                }
            } else if (ansiText[i] >= 32 || (unsigned char)ansiText[i] >= 128) {  // Printable ASCII + UTF-8
                // Handle multi-byte UTF-8 characters properly
                std::string utf8Char;
                unsigned char byte = ansiText[i];
                
                if ((byte & 0x80) == 0) {
                    // Single-byte ASCII
                    utf8Char = ansiText[i];
                } else if ((byte & 0xE0) == 0xC0) {
                    // 2-byte UTF-8
                    utf8Char = ansiText.substr(i, 2);
                    i += 1;
                } else if ((byte & 0xF0) == 0xE0) {
                    // 3-byte UTF-8 (block characters like █ are here)
                    utf8Char = ansiText.substr(i, 3);
                    i += 2;
                } else if ((byte & 0xF8) == 0xF0) {
                    // 4-byte UTF-8
                    utf8Char = ansiText.substr(i, 4);
                    i += 3;
                } else {
                    // Invalid UTF-8, skip
                    continue;
                }
                
                int fgColor = (currentFgR << 16) | (currentFgG << 8) | currentFgB;
                int bgColor = (currentBgR << 16) | (currentBgG << 8) | currentBgB;
                currentLine.push_back(ColoredChar(utf8Char, fgColor, bgColor));
            }
        }
        
        if (!currentLine.empty()) {
            result.push_back(currentLine);
        }
        
        return result;
    }
    
    // Convert RGB color (stored as int) to FTXUI Color
    Color terminalColorToFTXUI(int colorCode) {
        // Extract RGB components from packed integer
        int r = (colorCode >> 16) & 0xFF;
        int g = (colorCode >> 8) & 0xFF;
        int b = colorCode & 0xFF;
        
        return Color::RGB(r, g, b);
    }
    
    // Helper function to convert image to ASCII art using chafa
    std::string convertImageToASCII(const std::string& imagePath, int width = 50, int height = 25) {
        // Check if image file exists
        std::ifstream fileCheck(imagePath);
        if (!fileCheck.good()) {
            return "[Image not found: " + imagePath + "]";
        }
        fileCheck.close();
        
        std::string tempFile = "/tmp/ascii_temp.txt";
        std::string command = "chafa --size " + std::to_string(width) + "x" + std::to_string(height) + 
                             " --symbols block --color-space rgb --dither none --fill all \"" + imagePath + "\" > " + tempFile + " 2>&1";
        
        int result = system(command.c_str());
        
        if (result != 0) {
            return "[chafa not available. Install with: sudo apt-get install chafa]";
        }
        
        // Read the generated ASCII art
        std::ifstream file(tempFile);
        if (!file.is_open()) {
            return "[Failed to generate ASCII art]";
        }
        
        std::stringstream buffer;
        buffer << file.rdbuf();
        file.close();
        
        std::string output = buffer.str();
        
        remove(tempFile.c_str());
        
        return output;
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
            "View Plants",
            "My Cart",
            "Refunds",
            "Checkout",
            "Exit"
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
            text("🌿 GreensOnly Plant Shop 🌿") | bold | center | color(Color::Green),
            separator(),
            text("") | size(HEIGHT, EQUAL, 1),
            vbox(menuItems),
            text("") | size(HEIGHT, EQUAL, 1),
            separator(),
            cartInfo,
            text("") | size(HEIGHT, EQUAL, 1),
            text(messageBuffer) | color(Color::Yellow),
            text("Use ↑↓ arrows to navigate, Enter to select") | dim,
            text("") | size(HEIGHT, EQUAL, 1)
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
                // Format price as R0.00
                std::ostringstream priceStream;
                priceStream << std::fixed << std::setprecision(2) << p->getCost();
                std::string plantInfo = std::to_string(i + 1) + ". " + p->getName() + 
                                      " - R" + priceStream.str();
                
                if (static_cast<int>(i) == plantListSelected) {
                    plantItems.push_back(text("► " + plantInfo) | color(Color::Green) | bold);
                } else {
                    plantItems.push_back(text("  " + plantInfo));
                }
            }
        }
        
        std::string header = (selectedCategory == "All Plants") ? "All Plants" : (selectedCategory + " Plants");

        return vbox({
            text("🌿 " + header + " 🌿") | bold | center,
            separator(),
            vbox(plantItems),
            separator(),
            text("Use ↑↓ arrows to select plant, Enter to view details, 'b' to go back") | dim
        }) | border | center;
    }
    
    Element renderPlantDetails() {
        if (!selectedPlant) {
            return text("No plant selected") | center;
        }
        
        AskInfoCommand* infoCmd = new AskInfoCommand(nurseryStaff, selectedPlant);
        auto result = customer->sendCommand(infoCmd);
        delete infoCmd;     
        std::string info = result.first;
        
        std::string imagePath = selectedPlant->getImagePath();
        //Size adjuster here for images, it's width (characters) x height (lines)
        std::string asciiArt = convertImageToASCII(imagePath, 30, 15);
        
        // Parse the ANSI codes and convert to FTXUI colored elements
        auto coloredImage = parseAnsiImage(asciiArt);
        
        Elements content;
        
        content.push_back(text("🌿 " + selectedPlant->getName() + " 🌿") | bold | center | color(Color::Green));
        content.push_back(separator());
        Elements scrollableContent;
        
        if (!coloredImage.empty() && coloredImage[0].size() > 0) {
            Elements asciiLines;
            for (const auto& line : coloredImage) {
                Elements lineChars;
                for (const auto& coloredChar : line) {
                    auto elem = text(coloredChar.ch) | 
                               color(terminalColorToFTXUI(coloredChar.fgColor)) |
                               bgcolor(terminalColorToFTXUI(coloredChar.bgColor));
                    lineChars.push_back(elem);
                }
                if (!lineChars.empty()) {
                    asciiLines.push_back(hbox(lineChars));
                }
            }
            
            if (!asciiLines.empty()) {
                scrollableContent.push_back(vbox(asciiLines) | center);
                scrollableContent.push_back(separator());
            }
        }
        
        scrollableContent.push_back(text("Plant Information:") | bold | color(Color::Green));
        std::istringstream infoStream(info);
        std::string line;
        while (std::getline(infoStream, line)) {
            if (!line.empty()) {
                scrollableContent.push_back(text("  " + line));
            }
        }
        
        scrollableContent.push_back(text("") | size(HEIGHT, EQUAL, 1));      
        content.push_back(vbox(scrollableContent) | flex_shrink);
        
        content.push_back(separator());
        
        // cart button doesn't work rn
        content.push_back(
            hbox({
                filler(),
                text(" Add to Cart ") | bgcolor(Color::Green) | color(Color::White) | bold | center,
                filler()
            })
        );
        content.push_back(text("") | size(HEIGHT, EQUAL, 1));
        content.push_back(text("Press 'b' to go back") | dim | center);
        
        return vbox(content) | border | size(WIDTH, LESS_THAN, 100) | center;
    }
    
    Element renderStockCheck() {
        if (!selectedPlant) {
            return text("No plant selected") | center;
        }
        
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
                std::ostringstream priceStream;
                priceStream << std::fixed << std::setprecision(2) << r->getCost();
                std::string orderInfo = "Order " + std::to_string(i + 1) + ": " + 
                                       r->getDate() + " - R" + priceStream.str();
                
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
            std::ostringstream priceStream;
            priceStream << std::fixed << std::setprecision(2) << p->getCost();
            std::string plantInfo = std::to_string(i + 1) + ". " + p->getName() + 
                                  " - R" + priceStream.str();
            plantElements.push_back(text(plantInfo));
        }
        
        std::ostringstream totalStream;
        totalStream << std::fixed << std::setprecision(2) << selectedReceipt->getCost();
        
        return vbox({
            text("🌿 Select Plant to Refund 🌿") | bold | center,
            separator(),
            text("Order Date: " + selectedReceipt->getDate()) | bold,
            text("Total: R" + totalStream.str()) | bold,
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
        messageBuffer = "";
        
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
                case 0:
                    currentView = CATEGORY_SELECTION;
                    categoryMenuSelected = 0;
                    break;
                case 1: 
                    showCart();
                    break;
                case 2:
                    currentView = PAST_ORDERS;
                    selectedOrderIndex = 0;
                    break;
                case 3: 
                    performCheckout();
                    break;
                case 4:
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
        } else if (event == Event::Return) {
            // View plant details
            selectedPlant = currentPlants[plantListSelected];
            currentView = PLANT_DETAILS;
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
            std::ostringstream totalStream;
            totalStream << std::fixed << std::setprecision(2) << customer->totalCost();
            messageBuffer = "Cart has " + std::to_string(order.size()) + " items. Total: R" + totalStream.str();
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
            std::ostringstream totalStream;
            totalStream << std::fixed << std::setprecision(2) << result.second->getCost();
            messageBuffer = "Checkout successful! Total: R" + totalStream.str();
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
