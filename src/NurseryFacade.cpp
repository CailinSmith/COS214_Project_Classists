#include "NurseryFacade.h"
#include <iostream>
#include <sstream>
#include <random>
#include <map>
#include <functional>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include "SalesArea.h"
#include "NurseryArea.h"
#include "SalesStaff.h"
#include "NurseryStaff.h"
#include "Manager.h"
#include "CheckoutCommand.h"
#include "RemoveCommand.h"
#include "RemoveSaleCommand.h"
#include "AskInfoCommand.h"
#include "CheckStockCommand.h"
#include "RefundCommand.h"
#include "WaterCommand.h"
#include "PruneCommand.h"
#include "FertiliseCommand.h"
#include "Spring.h"
#include "Summer.h"
#include "Autumn.h"
#include "Winter.h"
//plant types used for staff "add to nursery" helper (full list)
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
#include "Customer.h"

using namespace std;

static const string MENU_BLUE = "\033[34m";
static const string MENU_RESET = "\033[0m";
static const string MENU_SEP = "============================================================";
static const string MENU_GREEN = "\033[32m";

NurseryFacade::NurseryFacade(InventoryManager* mgr) {
    if (mgr == nullptr) {
        manager_ = new InventoryManager();
    } else {
        manager_ = mgr;
    }
    nursery_ = Nursery::getInstance(manager_);

    salesArea_ = new SalesArea();
    nurseryArea_ = new NurseryArea();
    managerStaff_ = new Manager(std::string("Jordan"));
    salesStaff_ = new SalesStaff(std::string("Alice"));
    nurseryStaff_ = new NurseryStaff(std::string("Jack"));
    //mediator
    if (salesArea_) {
        salesArea_->registerColleague(managerStaff_);
        salesArea_->registerColleague(salesStaff_);
    }
    if (nurseryArea_) {
        nurseryArea_->registerColleague(managerStaff_);
        nurseryArea_->registerColleague(nurseryStaff_);
    }

    //chain of responsibility
    if (nurseryStaff_ && salesStaff_) nurseryStaff_->setNext(salesStaff_);
    if (salesStaff_ && managerStaff_) salesStaff_->setNext(managerStaff_);

    running_ = false;
}

NurseryFacade::~NurseryFacade() {
    stop();

    for (Receipt* r : pastReceipts_) {
        delete r;
    }
    pastReceipts_.clear();

    currentOrder_.clear();

    soldProducts_.clear();

    if (manager_) {
        delete manager_;
        manager_ = nullptr;
    }

    if (salesArea_) {
        if (managerStaff_) salesArea_->unregisterColleague(managerStaff_);
        if (salesStaff_) salesArea_->unregisterColleague(salesStaff_);
    }
    if (nurseryArea_) {
        if (managerStaff_) nurseryArea_->unregisterColleague(managerStaff_);
        if (nurseryStaff_) nurseryArea_->unregisterColleague(nurseryStaff_);
    }
    if (managerStaff_) { delete managerStaff_; managerStaff_ = nullptr; }
    if (salesStaff_) { delete salesStaff_; salesStaff_ = nullptr; }
    if (nurseryStaff_) { delete nurseryStaff_; nurseryStaff_ = nullptr; }

    Nursery::destroyInstance();

    if (salesArea_) { delete salesArea_; salesArea_ = nullptr; }
    if (nurseryArea_) { delete nurseryArea_; nurseryArea_ = nullptr; }
}

//stop(): atomically clear running_ and join background threads. We use
//compare_exchange_strong to avoid repeated joins if stop() is called twice.
void NurseryFacade::stop() {
    bool expected = true;
    if (running_.compare_exchange_strong(expected, false)) {
        //wake up any waiting threads
        cv_.notify_all();
        for (auto &t : threads_) {
            if (t.joinable()) t.join();
        }
        threads_.clear();
    }
}

void NurseryFacade::runSettings() {
    while (running_) {
        cout << endl;
        cout << MENU_BLUE << MENU_SEP << "\n";
        cout << "--- SETTINGS ---\n";
        cout << MENU_SEP << MENU_RESET << "\n";
        cout << "1) Set tick interval (tps) - current: " << tickInterval_.count() << " tps\n";
        cout << "2) Set season\n";
        cout << "3) Return\n";
        cout << MENU_BLUE << "Choice: " << MENU_RESET;
        string line; if (!getline(cin, line)) break;
        if (line == "1") {
            cout << "Enter tick interval in milliseconds: "; string v; getline(cin, v);
            try { int tps = stoi(v); if (tps < 100) tps = 100; setTickInterval(std::chrono::milliseconds(tps)); cout << "Tick interval set to " << tps << " tps\n"; }
            catch(...) { cout << "Invalid value\n"; }
        } else if (line == "2") {
            cout << "Choose season:\n1) Spring\n2) Summer\n3) Autumn\n4) Winter\n";
            cout << MENU_BLUE << "Choice: " << MENU_RESET; string s; getline(cin, s);
            if (!nursery_) { cout << "Nursery not initialised\n"; continue; }
            SeasonState* ss = nullptr;
            try {
                int c = stoi(s);
                if (c==1) ss = new Spring();
                else if (c==2) ss = new Summer();
                else if (c==3) ss = new Autumn();
                else if (c==4) ss = new Winter();
            } catch(...) { ss = nullptr; }
            if (!ss) { cout << "Invalid season\n"; continue; }
            nursery_->setSeason(ss);
            cout << "Season set to: " << nursery_->getSeason() << "\n";
        } else if (line == "3") {
            break;
        } else {
            cout << "Invalid option\n";
        }
    }
}

void NurseryFacade::runMainMenu() {
    while (running_) {
    cout << endl;
    cout << MENU_BLUE << MENU_SEP << "\n";
    cout << "=== WELCOME TO GREENSONLY ===\n";
    cout << MENU_SEP << MENU_RESET << "\n";
    cout << "1) Customer\n";
    cout << "2) Staff\n";
    cout << "3) Settings\n";
    cout << "4) Exit\n";
    cout << MENU_BLUE << "Choose an option: " << MENU_RESET;
        string line;
        if (!std::getline(cin, line)) break;
        if (line == "1") runCustomerMenu();
        else if (line == "2") runStaffMenu();
        else if (line == "3") runSettings();
        else if (line == "4") {
            cout << "Exiting demo...\n";
            break;
        } else {
            cout << "Invalid option\n";
        }
    }
}

void NurseryFacade::runCustomerMenu() {
    while (running_) {
    cout << endl;
    cout << MENU_BLUE << MENU_SEP << "\n";
    cout << "--- CUSTOMER MENU ---\n";
    cout << MENU_SEP << MENU_RESET << "\n";
    cout << "1) View sale plants\n";
    cout << "2) Browse by category\n";
    cout << "3) View seasonal plants\n";
    cout << "4) View current order\n";
    cout << "5) Checkout\n";
    cout << "6) View past receipts\n";
    cout << "7) Return\n";
    cout << MENU_BLUE << "Choose: " << MENU_RESET;
        string line;
        if (!getline(cin, line)) break;

        if (line == "1") {
            listSalePlants();
        } else if (line == "2") {
            listSaleCategories();
            cout << MENU_BLUE << "Choose a category number (or 0 to return): " << MENU_RESET;
            string catSel; getline(cin, catSel);
            size_t catIdx = 0;
            try { catIdx = stoi(catSel); } catch(...) { cout << "Invalid input\n"; continue; }
            if (catIdx == 0) continue;

            map<string, vector<Plant*>> groups;
            {
                lock_guard<mutex> lk(mtx_);
                for (Plant* p : manager_->getForSalePlants()) groups[p->getCategory()].push_back(p);
            }
            if (groups.empty()) { cout << "No categories available\n"; continue; }
            vector<string> cats; cats.reserve(groups.size());
            for (auto &kv : groups) cats.push_back(kv.first);
            if (catIdx < 1 || catIdx > cats.size()) { cout << "Invalid category\n"; continue; }
            string chosen = cats[catIdx-1];

            auto items = groups[chosen];
            cout << "==== Plants in category '" << chosen << "' ====\n";
            for (size_t i=0;i<items.size();++i) cout << i+1 << ") " << items[i]->getName() << " - R" << items[i]->getCost() << "\n";

            while (true) {
                cout << endl;
                cout << "Options:\n";
                cout << "\t i) info <num>    - show details for item #<num>\n";
                cout << "\t s) stock <num>   - show stock count for item #<num>\n";
                cout << "\t a) add <num>     - add item #<num> to current order\n";
                cout << "\t r) return        - return to previous menu\n";
                cout << MENU_BLUE << "Enter option (e.g. 'i 1' or 'i1'): " << MENU_RESET;
                string sub; getline(cin, sub);
                if (sub.size()==0) continue;
                //compact to accept w/o spaces
                string compact;
                for (char c : sub) if (!isspace((unsigned char)c)) compact.push_back((char)std::tolower((unsigned char)c));
                char cmd = compact.empty() ? '\0' : compact[0];
                string numStr = compact.size() > 1 ? compact.substr(1) : string();

                if (cmd == 'i') {
                        if (!numStr.empty()) {
                            try {
                                int num = stoi(numStr);
                                if (num>=1 && num <= (int)items.size()) {
                                    Plant* p = items[num-1];
                                    Customer tmp("Guest");
                                    AskInfoCommand cmd(nurseryStaff_, p);
                                    auto res = tmp.sendCommand(&cmd);
                                    cout << res.first;
                                } else cout << "Index out of range\n";
                            } catch(...) { cout << "Invalid input\n"; }
                        } else cout << "Missing number\n";
                        continue;
                } else if (cmd == 's') {
                        if (!numStr.empty()) {
                            try {
                                int num = stoi(numStr);
                                if (num>=1 && num <= (int)items.size()) {
                                    Plant* p = items[num-1];
                                    Customer tmp("Guest");
                                    CheckStockCommand cmd(nurseryStaff_, p);
                                    auto res = tmp.sendCommand(&cmd);
                                    cout << res.first;
                                } else cout << "Index out of range\n";
                            } catch(...) { cout << "Invalid input\n"; }
                        } else cout << "Missing number\n";
                        continue;
                } else if (cmd == 'a') {
                    if (!numStr.empty()) {
                        try {
                            int num = stoi(numStr);
                            if (num>=1 && num <= (int)items.size()) {
                                Plant* p = items[num-1];
                                lock_guard<mutex> lk(mtx_);
                                if (!manager_->isInSale(p)) { cout << "Item no longer available\n"; }
                                else {
                                    //prevent adding the same plant to order
                                    Plant* base = p->getBasePlant();
                                    if (std::any_of(currentOrder_.begin(), currentOrder_.end(), [&](Product* q){ return q->getBasePlant() == base; })) {
                                        cout << p->getName() << " is already in the current order.\n";
                                    } else {
                                        currentOrder_.push_back(p);
                                        cout << p->getName() << " added to current order.\n";
                                    }
                                }
                            } else cout << "Index out of range\n";
                        } catch(...) { cout << "Invalid input\n"; }
                    } else cout << "Missing number\n";
                    //keep prompting mense
                    continue;
                } else if (cmd == 'r') {
                    break; //return to customer menu
                } else {
                    cout << "Unknown option\n";
                    cout << MENU_BLUE << "Press ENTER to continue." << MENU_RESET;
                    string cont; getline(cin, cont);
                    continue;
                }
            }

        } else if (line == "3") {
            listSeasonalPlants(true);  
            cout << MENU_BLUE << "Press ENTER to continue." << MENU_RESET;
            string cont; getline(cin, cont);
        } else if (line == "4") {
            cout << "Current order items:\n";
            for (size_t i=0;i<currentOrder_.size();++i) {
                cout << i+1 << ") " << currentOrder_[i]->getName() << " - R" << currentOrder_[i]->getCost() << "\n";
            }
            cout << "Total items: " << currentOrder_.size() << "\n";
            cout << MENU_BLUE << "Press ENTER to continue." << MENU_RESET;
            string cont; getline(cin, cont);
        }
        else if (line == "5") {
            performCheckout();
        }
        else if (line == "6") {
            if (pastReceipts_.empty()) {
                cout << "No past receipts available.\n";
                continue;
            }
            cout << "Past receipts:\n";
            for (size_t i=0;i<pastReceipts_.size();++i) {
                cout << i+1 << ") " << pastReceipts_[i]->getDate() << " - R" << pastReceipts_[i]->getCost() << "\n";
            }
            cout << MENU_BLUE << "Choose a receipt number to view (or 0 to return): " << MENU_RESET;
            string sel; if (!getline(cin, sel)) break;
            int rnum = -1;
            try { rnum = stoi(sel); } catch(...) { rnum = -1; }
            if (rnum == 0) continue;
            if (rnum < 1 || (size_t)rnum > pastReceipts_.size()) { cout << "Invalid receipt\n"; continue; }
            size_t idx = (size_t)rnum - 1;
            Receipt* chosen = pastReceipts_[idx];
            cout << chosen->toString() << "\n";
            cout << "Options: (r) Refund items from this receipt  (b) Back\n";
            cout << MENU_BLUE << "Choice: " << MENU_RESET;
            string op; if (!getline(cin, op)) break;
            if (op == "b" || op == "B") continue;
            if (op == "r" || op == "R") {
                const std::vector<Product*>* plants = chosen->getPlants();
                if (!plants || plants->empty()) { 
                    cout << "Nothing to refund on this receipt.\n"; 
                    continue; 
                }
                
                vector<Product*> plantsToCheck;
                for (auto p : *plants) plantsToCheck.push_back(p);
                
                vector<Product*> toRefund;
                for (Product* p : plantsToCheck) {
                    string pname = p ? p->getName() : string("<unknown>");
                    while (true) {
                        cout << "Refund " << pname << "? (y/n): "; 
                        string a; 
                        if (!getline(cin, a)) break;
                        if (a == "y" || a == "Y") { 
                            toRefund.push_back(p); 
                            break; 
                        }
                        if (a == "n" || a == "N") { 
                            break; 
                        }
                        cout << "Please enter 'y' or 'n'.\n";
                    }
                }
                
                if (toRefund.empty()) {
                    cout << "No items refunded.\n";
                    continue;
                }
                
                float refundTotal = 0.0f;
                Nursery* nursery = Nursery::getInstance();
                string season = nursery ? nursery->getSeason() : "";
                
                for (Product* p : toRefund) {
                    refundTotal += p->calculateCost(season);
                    chosen->removeProduct(p);  
                    delete p; 
                }
                
                cout << "Refund processed: R" << refundTotal << "\n";
                
                if (chosen->getPlants()->empty()) {
                    pastReceipts_.erase(pastReceipts_.begin() + idx);
                    delete chosen;
                    cout << "All items refunded - receipt removed.\n";
                } else {
                    cout << "Updated receipt:\n" << chosen->toString() << "\n";
                }
            }
        }
        else if (line == "7") break;
        else cout << "Invalid option\n";
    }
}
           
void NurseryFacade::runStaffMenu() {
    Staff* currentStaff = nullptr;

    while (running_) {
        cout << "Choose staff to act as:\n";
    cout << "1) Manager (" << (managerStaff_? managerStaff_->getName() : string("-")) << ")\n";
    cout << "2) Sales staff (" << (salesStaff_? salesStaff_->getName() : string("-")) << ")\n";
    cout << "3) Nursery staff (" << (nurseryStaff_? nurseryStaff_->getName() : string("-")) << ")\n";
    cout << "4) Cancel/Return\n";
    cout << MENU_BLUE << "Choice: " << MENU_RESET;
        string sel; if (!getline(cin, sel)) return;
        if (sel == "4") return;
        if (sel == "1") currentStaff = managerStaff_;
        else if (sel == "2") currentStaff = salesStaff_;
        else if (sel == "3") currentStaff = nurseryStaff_;
        else { cout << "Invalid option\n"; continue; }
        break;
    }

    bool switchRequested = false;
    while (running_) {
        cout << endl;
        cout << MENU_BLUE << MENU_SEP << "\n";
        cout << "--- STAFF MENU ---\n";
        cout << MENU_SEP << MENU_RESET << "\n";
        bool isSales = (currentStaff && currentStaff->getPosition() == string("Sales staff"));


        vector<int> displayToActual;
        auto labelFor = [&](int actual) -> string {
            switch(actual) {
                case 1: return string("View plants (sale)");
                case 2: return string("View plants (nursery)");
                case 3: return string("Care for a plant");
                case 4: return string("Move plant between nursery/sale");
                case 5: return string("Send message to area");
                case 6: return string("View notifications");
                case 7: return string("Clear notifications");
                case 8: return string("Switch staff");
                case 9: return string("Remove plant from system");
                case 10: return string("Add plant to nursery");
                case 11: return string("View seasonal plants");
                case 12: return string("Return");
                default: return string("");
            }
        };

        if (isSales) {
            // allowed actions for sales staff (omit 10 = "Add plant to nursery")
            vector<int> allowed = {4,5,6,7,8,9,11,12};
            for (size_t i = 0; i < allowed.size(); ++i) {
                cout << i+1 << ") " << labelFor(allowed[i]) << "\n";
                displayToActual.push_back(allowed[i]);
            }
            cout << MENU_BLUE << "Choose: " << MENU_RESET;
        } else {
            cout << "1) View plants (sale)\n";
            cout << "2) View plants (nursery)\n";
            cout << "3) Care for a plant\n";
            cout << "4) Move plant between nursery/sale\n";
            cout << "5) Send message to area\n";
            cout << "6) View notifications\n";
            cout << "7) Clear notifications\n";
            cout << "8) Switch staff\n";
            cout << "9) Remove plant from system\n";
            cout << "10) Add plant to nursery\n";
            cout << "11) View seasonal plants\n";
            cout << "12) Return\n";
            cout << MENU_BLUE << "Choose: " << MENU_RESET;
        }
        string line;
        if (!getline(cin, line)) break;
        if (isSales) {
            try {
                int d = stoi(line);
                if (d >= 1 && (size_t)d <= displayToActual.size()) {
                    line = to_string(displayToActual[d-1]);
                }
            } catch(...) { /* keep original line if not a number */ }
        }
            if (line == "1") {
                if (currentStaff && currentStaff->getPosition() == string("Sales staff")) { cout << "Not permitted for Sales staff\n"; continue; }
                {
                    lock_guard<mutex> lk(mtx_);
                    auto const &sale = manager_->getForSalePlants();
                    if (sale.empty()) { cout << "No plants for sale right now.\n"; cout << MENU_BLUE << "Press ENTER to return to staff menu..." << MENU_RESET; string tmp; getline(cin,tmp); break; }
                    //copy pointers locally to avoid holding lock during input
                    vector<Plant*> items;
                    items.reserve(sale.size());
                    for (auto p : sale) items.push_back(p);

                    while (true) {
                        cout << endl;
                        cout << MENU_GREEN << MENU_SEP << "\n";
                        cout << "==== Sale plants ====\n";
                        cout << MENU_SEP << MENU_RESET << "\n";
                        for (size_t i=0;i<items.size();++i) cout << i+1 << ") " << items[i]->getName() << " (" << items[i]->getCategory() << ") - " << items[i]->getState() << "\n";
                        cout << "Options:\n\t i) info <num> - show staff summary for item #<num>\n\t r) return - return to staff menu\n";
                        cout << MENU_BLUE << "Enter option (e.g. 'i1' or 'i 1'): " << MENU_RESET;
                        string sub; getline(cin, sub);
                        if (sub.size()==0) continue;
                        string compact;
                        for (char c : sub) if (!isspace((unsigned char)c)) compact.push_back((char)std::tolower((unsigned char)c));
                        char cmd = compact.empty() ? '\0' : compact[0];
                        string numStr = compact.size() > 1 ? compact.substr(1) : string();
                        if (cmd == 'i') {
                            if (!numStr.empty()) {
                                try {
                                    int num = stoi(numStr);
                                    if (num>=1 && num <= (int)items.size()) {
                                            Plant* p = items[num-1];
                                            cout << p->summary();
                                            cout << MENU_BLUE << "Press ENTER to continue." << MENU_RESET;
                                            string tmp; getline(cin, tmp);
                                        continue;
                                    } else cout << "Index out of range\n";
                                } catch(...) { cout << "Invalid input\n"; }
                            } else cout << "Missing number\n";
                            cout << MENU_BLUE << "Press ENTER to continue." << MENU_RESET; string tmp; getline(cin,tmp); continue;
                        } else if (cmd == 'r') {
                            break;
                        } else {
                            cout << "Unknown option\n";
                            cout << MENU_BLUE << "Press ENTER to continue." << MENU_RESET; string tmp; getline(cin,tmp); continue;
                        }
                    }
                }
        }
        else if (line == "2") {
            if (currentStaff && currentStaff->getPosition() == string("Sales staff")) { cout << "Not permitted for Sales staff\n"; continue; }
            {
                lock_guard<mutex> lk(mtx_);
                auto const &nur = manager_->getNurseryPlants();
                if (nur.empty()) { cout << "No nursery plants right now.\n"; cout << MENU_BLUE << "Press ENTER to return to staff menu..." << MENU_RESET; string tmp; getline(cin,tmp); break; }

                vector<Plant*> items;
                items.reserve(nur.size());
                for (auto p : nur) items.push_back(p);

                while (true) {
                    cout << endl;
                    cout << MENU_GREEN << MENU_SEP << "\n";
                    cout << "==== Nursery plants ====\n";
                    cout << MENU_SEP << MENU_RESET << "\n";
                    for (size_t i=0;i<items.size();++i) cout << i+1 << ") " << items[i]->getName() << " (" << items[i]->getCategory() << ") - " << items[i]->getState() << "\n";
                    cout << "Options:\n\t i) info <num> - show staff summary for item #<num>\n\t r) return - return to staff menu\n";
                    cout << MENU_BLUE << "Enter option (e.g. 'i1' or 'i 1'): " << MENU_RESET;
                    string sub; getline(cin, sub);
                    if (sub.size()==0) continue;
                    string compact;
                    for (char c : sub) if (!isspace((unsigned char)c)) compact.push_back((char)std::tolower((unsigned char)c));
                    char cmd = compact.empty() ? '\0' : compact[0];
                    string numStr = compact.size() > 1 ? compact.substr(1) : string();
                    if (cmd == 'i') {
                        if (!numStr.empty()) {
                            try {
                                int num = stoi(numStr);
                                if (num>=1 && num <= (int)items.size()) {
                                    Plant* p = items[num-1];
                                    cout << p->summary();
                                    cout << MENU_BLUE << "Press ENTER to continue." << MENU_RESET;
                                    string tmp; getline(cin, tmp);
                                    continue;
                                } else cout << "Index out of range\n";
                            } catch(...) { cout << "Invalid input\n"; }
                        } else cout << "Missing number\n";
                        cout << MENU_BLUE << "Press ENTER to continue." << MENU_RESET; string tmp; getline(cin,tmp); continue;
                    } else if (cmd == 'r') {
                        break;
                    } else {
                        cout << "Unknown option\n";
                        cout << MENU_BLUE << "Press ENTER to continue." << MENU_RESET; string tmp; getline(cin,tmp); continue;
                    }
                }
            }
        }
        else if (line == "3") {
            if (currentStaff && currentStaff->getPosition() == string("Sales staff")) { cout << "Not permitted for Sales staff\n"; continue; }
            cout << "Enter 's' for sale list or 'n' for nursery: ";
            string which; getline(cin, which);

            //show chosen list first
            vector<Plant*> listing;
            {
                lock_guard<mutex> lk(mtx_);
                if (which == "s") {
                    auto &sale = manager_->getForSalePlants();
                    for (size_t i=0;i<sale.size();++i) {
                        cout << i+1 << ") " << sale[i]->getName() << " (" << sale[i]->getCategory() << ")\n";
                        listing.push_back(sale[i]);
                    }
                } else {
                    auto &nur = manager_->getNurseryPlants();
                    for (size_t i=0;i<nur.size();++i) {
                        cout << i+1 << ") " << nur[i]->getName() << " (" << nur[i]->getCategory() << ") - " << nur[i]->getState() << "\n";
                        listing.push_back(nur[i]);
                    }
                }
            }

            //prompt for index
            while (true) {
                cout << MENU_BLUE << "Enter index (or 'r' to return): " << MENU_RESET;
                string idxs; if (!getline(cin, idxs)) break;
                if (idxs == "r" || idxs == "R") break;
                try {
                    size_t idx = stoi(idxs);
                    if (idx>=1 && idx<=listing.size()) {
                        Plant* p = listing[idx-1];
                        cout << "Care options: 1) water 2) prune 3) fertilise\n";
                        string opt; getline(cin,opt);
                        if (opt=="1") {
                            WaterCommand waterCmd(p);
                            waterCmd.execute();
                        } else if (opt=="2") {
                            PruneCommand pruneCmd(p);
                            pruneCmd.execute();
                        } else if (opt=="3") {
                            FertiliseCommand fertiliseCmd(p);
                            fertiliseCmd.execute();
                        }
                        cout << "Done." << "\n";
                        break;
                    } else {
                        cout << "Index out of range\n";
                        continue;
                    }
                } catch(...) { cout << "Invalid index\n"; continue; }
            }
        }
        else if (line == "4") {
            cout << "Move from (s)ale or (n)ursery? "; string which; getline(cin,which);

            //copy the chosen list under lock and show it to the user
            vector<Plant*> listing;
            {
                lock_guard<mutex> lk(mtx_);
                if (which == "s") {
                    auto &sale = manager_->getForSalePlants();
                    if (sale.empty()) { cout << "No plants for sale right now.\n"; cout << MENU_BLUE << "Press ENTER to return to staff menu..." << MENU_RESET; string tmp; getline(cin,tmp); continue; }
                    for (size_t i=0;i<sale.size();++i) listing.push_back(sale[i]);
                } else {
                    auto &nur = manager_->getNurseryPlants();
                    if (nur.empty()) { cout << "No nursery plants right now.\n"; cout << MENU_BLUE << "Press ENTER to return to staff menu..." << MENU_RESET; string tmp; getline(cin,tmp); continue; }
                    for (size_t i=0;i<nur.size();++i) listing.push_back(nur[i]);
                }
            }

            cout << "Listing items in source room:\n";
            for (size_t i=0;i<listing.size();++i) {
                cout << i+1 << ") " << listing[i]->getName() << " (" << listing[i]->getCategory() << ") - " << listing[i]->getState() << "\n";
            }

            //ask for index; perform the move while re-locking to ensure consistent state
            while (true) {
                cout << MENU_BLUE << "Enter index to move (or 'r' to return): " << MENU_RESET;
                string idxs; if (!getline(cin, idxs)) break;
                if (idxs == "r" || idxs == "R") break;
                try {
                    size_t idx = stoi(idxs);
                    if (idx>=1 && idx<=listing.size()) {
                        Plant* p = listing[idx-1];
                        lock_guard<mutex> lk(mtx_);
                        if (which=="s") {
                            if (!manager_->isInSale(p)) { cout << "Item no longer in sale.\n"; break; }
                            manager_->removeFromSale(p);
                            manager_->addToNursery(p);
                            cout << "Moved to nursery\n";
                        } else {
                            if (!manager_->isInNursery(p)) { cout << "Item no longer in nursery.\n"; break; }
                            manager_->removeFromNursery(p);
                            manager_->addToSale(p);
                            cout << "Moved to sale\n";
                        }
                        break;
                    } else {
                        cout << "Index out of range\n"; continue;
                    }
                } catch(...) { cout << "Invalid index\n"; continue; }
            }
        }
        else if (line == "5") {
            cout << "Enter message for staff area: "; string msg; getline(cin,msg);
            //choose room
            if (currentStaff->getPosition() == string("Manager")) {
                Manager* mgr = dynamic_cast<Manager*>(currentStaff);
                if (mgr) {
                    cout << "Send to: 1) Sales area 2) Nursery area 3) All rooms\n";
                    cout << MENU_BLUE << "Choice: " << MENU_RESET;
                    string dest; getline(cin, dest);
                    if (dest == "1") mgr->setReceiver(salesArea_);
                    else if (dest == "2") mgr->setReceiver(nurseryArea_);
                    else mgr->setReceiver(nullptr); 
                    mgr->setMessage(msg);
                    mgr->send();
                }
            } else {
                currentStaff->setMessage(msg);
                currentStaff->send();
            }
            cout << "Message sent.\n";
        }
        else if (line == "6") {
            cout << "--- Notifications (most recent last) ---\n";
            cout << currentStaff->getChatHistoryString();
            cout << "--- end notifications ---\n";
            cout << "Press Enter to return to staff menu...";
            string tmp; getline(cin,tmp);
        }
        else if (line == "7") {
            //clear notifications
            currentStaff->clearChatHistory();
            cout << "Notifications cleared. Press Enter to return to staff menu...";
            string tmp; getline(cin,tmp);
        }
        else if (line == "11") {
            listSeasonalPlants();
            cout << MENU_BLUE << "Press ENTER to return to staff menu..." << MENU_RESET;
            string tmp; getline(cin, tmp);
        }
        else if (line == "12") break;
        else if (line == "8") { switchRequested = true; break; }
        else if (line == "9") {
            cout << "Remove from (s)ale or (n)ursery? "; string which; getline(cin, which);

            //copy and display the chosen list under lock
            vector<Plant*> listing;
            {
                lock_guard<mutex> lk(mtx_);
                if (which == "s") {
                    auto &sale = manager_->getForSalePlants();
                    if (sale.empty()) { cout << "No plants for sale right now.\n"; cout << MENU_BLUE << "Press ENTER to return to staff menu..." << MENU_RESET; string tmp; getline(cin,tmp); continue; }
                    for (size_t i=0;i<sale.size();++i) {
                        cout << i+1 << ") " << sale[i]->getName() << " (" << sale[i]->getCategory() << ")\n";
                        listing.push_back(sale[i]);
                    }
                } else {
                    auto &nur = manager_->getNurseryPlants();
                    if (nur.empty()) { cout << "No nursery plants right now.\n"; cout << MENU_BLUE << "Press ENTER to return to staff menu..." << MENU_RESET; string tmp; getline(cin,tmp); continue; }
                    for (size_t i=0;i<nur.size();++i) {
                        cout << i+1 << ") " << nur[i]->getName() << " (" << nur[i]->getCategory() << ") - " << nur[i]->getState() << "\n";
                        listing.push_back(nur[i]);
                    }
                }
            }

            //ask for index and confirm removal
            while (true) {
                cout << MENU_BLUE << "Enter index to remove (or 'r' to return): " << MENU_RESET;
                string idxs; if (!getline(cin, idxs)) break;
                if (idxs == "r" || idxs == "R") break;
                try {
                    size_t idx = stoi(idxs);
                    if (idx>=1 && idx<=listing.size()) {
                        Plant* p = listing[idx-1];
                        cout << "Are you sure you want to permanently remove '" << p->getName() << "'? (y/n): "; string conf; getline(cin, conf);
                        if (conf == "y" || conf == "Y") {
                            if (which == "s") {
                                RemoveSaleCommand cmd(p, manager_);
                                cmd.execute();
                                cout << "Removed from sale.\n";
                            } else {
                                RemoveCommand cmd(p, manager_);
                                cmd.execute();
                                cout << "Removed from nursery.\n";
                            }
                            cout << MENU_BLUE << "Press ENTER to return to staff menu..." << MENU_RESET; string tmp; getline(cin,tmp);
                            break;
                        } else {
                            cout << "Aborted removal.\n";
                            cout << MENU_BLUE << "Press ENTER to return to staff menu..." << MENU_RESET; string tmp; getline(cin,tmp);
                            break;
                        }
                    } else { cout << "Index out of range\n"; continue; }
                } catch(...) { cout << "Invalid index\n"; continue; }
            }
        }
    else if (line == "10") {
            using Factory = std::function<Plant*()>;
            //list of all available plant factories
            vector<pair<string, Factory>> all = {
                {"Rose", [](){ return new Rose(); }},
                {"Basil", [](){ return new Basil(); }},
                {"Tomato", [](){ return new Tomato(); }},
                {"Lettuce", [](){ return new Lettuce(); }},
                {"JadePlant", [](){ return new JadePlant(); }},
                {"WaterLily", [](){ return new WaterLily(); }},
                {"SnakePlant", [](){ return new SnakePlant(); }},
                {"AloeVera", [](){ return new AloeVera(); }},
                {"Chrysanthemum", [](){ return new Chrysanthemum(); }},
                {"Lavender", [](){ return new Lavender(); }},
                {"AppleTree", [](){ return new AppleTree(); }},
                {"Pumpkin", [](){ return new Pumpkin(); }},
                {"BarrelCactus", [](){ return new BarrelCactus(); }},
                {"WaterHyacinth", [](){ return new WaterHyacinth(); }},
                {"RubberTree", [](){ return new RubberTree(); }},
                {"Coneflower", [](){ return new Coneflower(); }},
                {"Pansy", [](){ return new Pansy(); }},
                {"Thyme", [](){ return new Thyme(); }},
                {"Strawberry", [](){ return new Strawberry(); }},
                {"Kale", [](){ return new Kale(); }},
                {"Echeveria", [](){ return new Echeveria(); }},
                {"Cattails", [](){ return new Cattails(); }},
                {"PeaceLily", [](){ return new PeaceLily(); }},
                {"Chamomile", [](){ return new Chamomile(); }},
                {"Sunflower", [](){ return new Sunflower(); }},
                {"Rosemary", [](){ return new Rosemary(); }},
                {"OrangeTree", [](){ return new OrangeTree(); }},
                {"Cucumber", [](){ return new Cucumber(); }},
                {"ChristmasCactus", [](){ return new ChristmasCactus(); }},
                {"WaterLettuce", [](){ return new WaterLettuce(); }},
                {"Pothos", [](){ return new Pothos(); }},
                {"Ginger", [](){ return new Ginger(); }}
            };

            vector<string> categories;
            unordered_map<string, vector<size_t>> catToIndices;
            for (size_t i = 0; i < all.size(); ++i) {
                Plant* tmp = nullptr;
                try { tmp = all[i].second(); } catch(...) { tmp = nullptr; }
                if (!tmp) continue;
                string cat = tmp->getCategory();
                delete tmp;
                if (catToIndices.find(cat) == catToIndices.end()) {
                    categories.push_back(cat);
                }
                catToIndices[cat].push_back(i);
            }

            cout << "==== Available categories ====\n";
            for (size_t i = 0; i < categories.size(); ++i) {
                cout << i+1 << ") " << categories[i] << " (" << catToIndices[categories[i]].size() << " plants)\n";
            }
            cout << MENU_BLUE << "Choose a category number (or 0 to return): " << MENU_RESET;
            string catline; if (!getline(cin, catline)) continue;
            int catnum = 0;
            try { catnum = stoi(catline); } catch(...) { catnum = -1; }
            if (catnum == 0) continue;
            if (catnum < 1 || (size_t)catnum > categories.size()) { cout << "Invalid category\n"; continue; }

            string chosenCat = categories[catnum-1];
            auto &indices = catToIndices[chosenCat];

            cout << "==== Plants in category '" << chosenCat << "' ====\n";
            for (size_t i = 0; i < indices.size(); ++i) {
                size_t idx = indices[i];
                Plant* tmp = all[idx].second();
                double cost = tmp ? tmp->getCost() : 0.0;
                string name = all[idx].first;
                delete tmp;
                cout << i+1 << ") " << name << " - R" << cost << "\n";
            }

            cout << MENU_BLUE << "Choose plant number to create (or 0 to cancel): " << MENU_RESET;
            string pick; if (!getline(cin, pick)) continue;
            int pnum = -1;
            try { pnum = stoi(pick); } catch(...) { pnum = -1; }
            if (pnum == 0) continue;
            if (pnum < 1 || (size_t)pnum > indices.size()) { cout << "Invalid plant selection\n"; continue; }

            size_t chosenIndex = indices[pnum-1];
            Plant* p = nullptr;
            try { p = all[chosenIndex].second(); } catch(...) { p = nullptr; }
            if (!p) { cout << "Failed to create plant\n"; continue; }

            //add to nursery under lock
            {
                lock_guard<mutex> lk(mtx_);
                manager_->addToNursery(p);
            }
            cout << p->getName() << " added to nursery.\n";
            cout << MENU_BLUE << "Press ENTER to return to staff menu..." << MENU_RESET; string tmp; getline(cin,tmp);
        }
        else cout << "Invalid option\n";
    }

    //if user chose to switch staff, loop back into the selection flow.
    if (switchRequested) { runStaffMenu(); return; }
}

void NurseryFacade::listSalePlants() {
    //Copy sale pointers while holding the lock, then release the lock so
    //interactive operations (which may also lock) don't deadlock.
    vector<Plant*> items;
    {
        lock_guard<mutex> lk(mtx_);
        auto const &sale = manager_->getForSalePlants();
        if (sale.empty()) { cout << "No plants for sale right now.\n"; return; }
        items.reserve(sale.size());
        for (size_t i=0;i<sale.size();++i) items.push_back(sale[i]);
    }
    //pretty heading
    cout << endl;
    cout << MENU_GREEN << MENU_SEP << "\n";
    cout << "==== Sale plants ====" << "\n";
    cout << MENU_SEP << MENU_RESET << "\n";
    for (size_t i=0;i<items.size();++i) {
    cout << i+1 << ") " << items[i]->getName() << " - " << items[i]->getCategory() << " - R" << items[i]->getCost() << "\n";
    }

    while (true) {
        cout << endl;
        cout << "Options:\n";
        cout << "\t i) info <num>    - show details for item #<num>\n";
        cout << "\t s) stock <num>   - show stock count for item #<num>\n";
        cout << "\t a) add <num>     - add item #<num> to current order\n";
        cout << "\t r) return        - return to previous menu\n";
        cout << MENU_BLUE << "Enter option (e.g. 'i 1' or 'i1'): " << MENU_RESET;
        string sub; getline(cin, sub);
        if (sub.size()==0) continue;
        string compact;
        for (char c : sub) if (!isspace((unsigned char)c)) compact.push_back((char)std::tolower((unsigned char)c));
        char cmd = compact.empty() ? '\0' : compact[0];
        string numStr = compact.size() > 1 ? compact.substr(1) : string();

    if (cmd == 'i') {
            if (!numStr.empty()) {
                try {
                    int num = stoi(numStr);
                    if (num>=1 && num <= (int)items.size()) {
                        Plant* p = items[num-1];
                        Customer tmp("Guest");
                        AskInfoCommand cmd(nurseryStaff_, p);
                        auto res = tmp.sendCommand(&cmd);
                        cout << res.first;
                    } else cout << "Index out of range\n";
                } catch(...) { cout << "Invalid input\n"; }
            } else cout << "Missing number\n";
            continue;
        } else if (cmd == 's') {
            if (!numStr.empty()) {
                try {
                    int num = stoi(numStr);
                    if (num>=1 && num <= (int)items.size()) {
                        Plant* p = items[num-1];
                        Customer tmp("Guest");
                        CheckStockCommand cmd(nurseryStaff_, p);
                        auto res = tmp.sendCommand(&cmd);
                        cout << res.first;
                    }
                    else cout << "Index out of range\n";
                } catch(...) { cout << "Invalid input\n"; }
            } else cout << "Missing number\n";
            continue;
        } else if (cmd == 'a') {
            if (!numStr.empty()) {
                try {
                    int num = stoi(numStr);
                    if (num>=1 && num <= (int)items.size()) {
                        Plant* p = items[num-1];
                        lock_guard<mutex> lk(mtx_);
                        if (!manager_->isInSale(p)) { cout << "Item no longer available\n"; }
                        else {
                            //prevent duplicates
                            Plant* base = p->getBasePlant();
                            if (std::any_of(currentOrder_.begin(), currentOrder_.end(), [&](Product* q){ return q->getBasePlant() == base; })) {
                                cout << p->getName() << " is already in the current order.\n";
                            } else {
                                currentOrder_.push_back(p);
                                cout << p->getName() << " added to current order.\n";
                            }
                        }
                    } else cout << "Index out of range\n";
                } catch(...) { cout << "Invalid input\n"; }
            } else cout << "Missing number\n";
            continue;
        } else if (cmd == 'r') {
            break;
        } else {
            cout << "Unknown option\n";
            cout << MENU_BLUE << "Press ENTER to continue." << MENU_RESET;
            string cont; getline(cin, cont);
            continue;
        }
    }
}

void NurseryFacade::listSaleCategories() {
    lock_guard<mutex> lk(mtx_);
    auto const &sale = manager_->getForSalePlants();
    if (sale.empty()) { cout << "No plants for sale right now.\n"; return; }
    std::map<string, int> counts;
    for (auto p : sale) counts[p->getCategory()]++;
    cout << endl;
    cout << "==== Available categories ====\n";
    int i = 1;
    for (auto &kv : counts) {
        cout << i++ << ") " << kv.first << " (" << kv.second << " plants)\n";
    }
}

void NurseryFacade::listPlantsInCategory(const std::string &category) {
    lock_guard<mutex> lk(mtx_);
    auto const &sale = manager_->getForSalePlants();
    cout << endl;
    cout << "Plants in category '" << category << "':\n";
    int idx = 1;
    for (auto p : sale) {
        if (p->getCategory() == category) {
            cout << idx << ") " << p->getName() << " - R" << p->getCost() << "\n";
        }
        ++idx;
    }
}

void NurseryFacade::listSeasonalPlants(bool customerView) {
    if (!nursery_) {
        cout << "Nursery not available\n";
        return;
    }
    
    lock_guard<mutex> lk(mtx_);
    string currentSeason = nursery_->getSeason();
    
    cout << endl;
    cout << MENU_GREEN << "========================================" << MENU_RESET << endl;
    cout << MENU_GREEN << "  SEASONAL PLANTS (" << currentSeason << ")" << MENU_RESET << endl;
    cout << MENU_GREEN << "========================================" << MENU_RESET << endl;
    cout << endl;
    
    // Create appropriate iterator based on view type
    Iterator<Plant>* seasonalIterator = nullptr;
    if (customerView) {
        // Customers only see plants for sale
        seasonalIterator = manager_->createSaleIterator(currentSeason);
    } else {
        // Staff see all plants (both nursery and sale)
        seasonalIterator = manager_->createIterator(currentSeason);
    }
    
    if (!seasonalIterator) {
        cout << "Unable to create iterator for season: " << currentSeason << endl;
        return;
    }
    
    // Collect all seasonal plants
    vector<Plant*> seasonalPlants;
    for (Plant* plant = seasonalIterator->first(); !seasonalIterator->isDone(); plant = seasonalIterator->next()) {
        if (plant != nullptr) {
            seasonalPlants.push_back(plant);
        }
    }
    
    if (seasonalPlants.empty()) {
        if (customerView) {
            cout << "No plants for sale for the current season (" << currentSeason << ").\n";
        } else {
            cout << "No plants available for the current season (" << currentSeason << ").\n";
        }
    } else {
        cout << "Found " << seasonalPlants.size() << " plant(s) for " << currentSeason << " season:\n";
        cout << endl;
        
        int idx = 1;
        for (Plant* plant : seasonalPlants) {
            if (customerView) {
                cout << idx << ") " << plant->getName() 
                     << " - R" << plant->getCost() 
                     << " (Category: " << plant->getCategory() << ")" << endl;
            } else {
                string location = manager_->isInSale(plant) ? "For Sale" : "In Nursery";
                cout << idx << ") " << plant->getName() 
                     << " - R" << plant->getCost() 
                     << " [" << location << "]"
                     << " (Category: " << plant->getCategory() << ")" << endl;
            }
            idx++;
        }
    }
    
    cout << endl;
    delete seasonalIterator;
}

size_t NurseryFacade::getStockCountByName(const std::string &name) {
    lock_guard<mutex> lk(mtx_);
    size_t count = 0;
    for (auto p : manager_->getForSalePlants()) if (p->getName() == name) ++count;
    return count;
}

void NurseryFacade::viewPlantInfo(size_t index) {
    lock_guard<mutex> lk(mtx_);
    auto const &sale = manager_->getForSalePlants();
    if (index<1 || index>sale.size()) { cout << "Index out of range\n"; return; }
    Plant* p = sale[index-1];
    cout << "Name: " << p->getName() << "\n";
    cout << "Category: " << p->getCategory() << "\n";
    cout << "State: " << p->getState() << "\n";
    cout << "Health: " << p->getHealth() << "\n";
    cout << "Cost: R" << p->getCost() << "\n";
}

Plant* NurseryFacade::pickSalePlant(size_t index) {
    lock_guard<mutex> lk(mtx_);
    auto const &sale = manager_->getForSalePlants();
    if (index<1 || index>sale.size()) return nullptr;
    return sale[index-1];
}

void NurseryFacade::performCheckout() {
    if (currentOrder_.empty()) { cout << "Order is empty.\n"; return; }

    for (size_t i=0;i<currentOrder_.size();++i) {
        Product* p = currentOrder_[i];
        Plant* plant = dynamic_cast<Plant*>(p);
        if (!plant) continue; 
        string ans;
        while (true) {
            cout << "Decorate " << plant->getName() << "? (y/n): ";
            if (!getline(cin, ans)) break; 
            if (ans.size() != 1) { cout << "Please enter 'y' or 'n'.\n"; continue; }
            if (ans == "y" || ans == "Y") break; //proceed to decoration options
            if (ans == "n" || ans == "N") { ans = "n"; break; }
            cout << "Please enter 'y' or 'n'.\n";
        }
        if (ans == "y" || ans == "Y") {
            cout << "Decoration options:\n";
            cout << "1) Ceramic pot (+80)\n";
            cout << "2) Concrete pot (+60)\n";
            cout << "3) Clay pot (+50)\n";
            cout << "4) Kraft wrapping (+20)\n";
            cout << "5) Extra fertilizer (+80)\n";
            cout << MENU_BLUE << "Choose: " << MENU_RESET; string opt; getline(cin,opt);
        Product* decorated = nullptr;
        if (opt=="1") decorated = new CeramicPot(plant);
        else if (opt=="2") decorated = new ConcretePot(plant);
        else if (opt=="3") decorated = new ClayPot(plant);
        else if (opt=="4") decorated = new KraftWrapping(plant);
        else if (opt=="5") decorated = new ExtraFertilizer(plant);
            if (decorated) {
                currentOrder_[i] = decorated;
            }
        }
    }

    Customer cust("Guest");
    //Add products into the temporary customer's cart using addToCart()
    //so the command receives a proper customer-owned order reference.
    for (Product* p : currentOrder_) {
        cust.addToCart(p);
    }
    CheckoutCommand cmd(nurseryStaff_, &cust.getOrder(), nullptr);
    auto res = cust.sendCommand(&cmd);

    if (!cust.getReceipts().empty()) {
        Receipt* r = cust.getReceipts().back();
        cout << r->toString() << "\n";
        pastReceipts_.push_back(r);
        cust.getReceipts().pop_back();
    } else {
        cout << res.first << "\n";
    }

    currentOrder_.clear();
}

//start(): spawn background threads and run the blocking main menu.
//This method is idempotent: if already running it returns immediately.
void NurseryFacade::start() {
    bool expected = false;
    if (!running_.compare_exchange_strong(expected, true)) {
        //already running
        return;
    }

    //spawn background threads
    //If inventory is empty, seed demo plants once at startup.
    if (manager_->getSaleCount() == 0 && manager_->getNurseryCount() == 0) {
        manager_->populateDemoInventory(8, 8);
    }

    //register observers only after demo inventory has been created/added
    if (manager_) {
        if (managerStaff_) manager_->registerObserver(managerStaff_);
        if (nurseryStaff_) manager_->registerObserver(nurseryStaff_);
    }

    threads_.emplace_back(&NurseryFacade::tickLoop, this);
    //threads_.emplace_back(&NurseryFacade::automatedCustomerLoop, this); //disabled for now
    threads_.emplace_back(&NurseryFacade::automatedStaffLoop, this);

    //run the interactive menu (blocks until user exits or stop() called)
    runMainMenu();

    //ensure threads are stopped and joined
    stop();
}

void NurseryFacade::decorateProductMenu(size_t orderIndex) {
    if (orderIndex >= currentOrder_.size()) return;
    Product* p = currentOrder_[orderIndex];
    Plant* plant = dynamic_cast<Plant*>(p);
    if (!plant) return;

    string ans;
    while (true) {
        cout << "Decorate " << plant->getName() << "? (y/n): ";
        if (!getline(cin, ans)) return;
        if (ans.size() != 1) { cout << "Please enter 'y' or 'n'.\n"; continue; }
        if (ans == "y" || ans == "Y") break;
        if (ans == "n" || ans == "N") return;
        cout << "Please enter 'y' or 'n'.\n";
    }

    cout << "Decoration options:\n";
    cout << "1) Ceramic pot (+80)\n";
    cout << "2) Concrete pot (+60)\n";
    cout << "3) Clay pot (+50)\n";
    cout << "4) Kraft wrapping (+20)\n";
    cout << "5) Extra fertilizer (+80)\n";
    cout << MENU_BLUE << "Choose: " << MENU_RESET; string opt; getline(cin,opt);
    Product* decorated = nullptr;
    if (opt=="1") decorated = new CeramicPot(plant);
    else if (opt=="2") decorated = new ConcretePot(plant);
    else if (opt=="3") decorated = new ClayPot(plant);
    else if (opt=="4") decorated = new KraftWrapping(plant);
    else if (opt=="5") decorated = new ExtraFertilizer(plant);
    if (decorated) {
        currentOrder_[orderIndex] = decorated;
    }
}

//tickLoop: periodically invoked background updater. It locks the manager
//while iterating and calling changePlantState on each plant. If a nursery
//plant reaches the ReadyForSale state it is moved into the sale list.
//Note: calling expensive operations while holding the lock may slow UI.
void NurseryFacade::tickLoop() {
    std::unique_lock<std::mutex> lk(mtx_, std::defer_lock);
    while (running_) {
        std::this_thread::sleep_for(tickInterval_);
        if (!running_) break;
        lk.lock();
        // auto const &sale = manager_->getForSalePlants();
        // for (auto p : sale) {
        //     if (p) {
        //         p->changeHealth();
        //     }
        // }
        auto const &nur = manager_->getNurseryPlants();
        for (auto p : nur) {
            if (p) {
                p->changeHealth();
                if (p->getState() == "ReadyForSale" && !manager_->isInSale(p)) {
                    manager_->addToSale(p);
                }
            }
        }
        lk.unlock();
    }
}

void NurseryFacade::automatedCustomerLoop() {
    std::mt19937 rng((unsigned)std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> wait(2000,6000);
    while (running_) {
        std::this_thread::sleep_for(std::chrono::milliseconds(wait(rng)));
        if (!running_) break;
        lock_guard<mutex> lk(mtx_);
        auto &sale = manager_->getForSalePlants();
        if (sale.empty()) continue;
        size_t idx = (size_t)(rng() % sale.size());
        Plant* p = sale[idx];
    if (p) p->changeHealth();
        vector<Product*> order; order.push_back(p);
    Receipt tmp(order);
    //cout << "[AutomatedCustomer] purchased " << p->getName() << " total R" << tmp.getCost() << "\n";
    soldProducts_.push_back(p);
    }
}

//automatedStaffLoop: simulates staff caring for nursery plants and moving
//ready plants to the sale list. This demonstrates concurrent state changes
//and interactions with the InventoryManager.
void NurseryFacade::automatedStaffLoop() {
    std::uniform_int_distribution<int> wait(3000,7000);
    std::mt19937 rng((unsigned)std::chrono::system_clock::now().time_since_epoch().count()+123);
    size_t pos = 0;
    while (running_) {
        //sleep between actions to simulate time taken
        std::this_thread::sleep_for(std::chrono::milliseconds(wait(rng)));
        if (!running_) break;

        Plant* p = nullptr;
        {
            lock_guard<mutex> lk(mtx_);
            auto &nur = manager_->getNurseryPlants();
            if (nur.empty()) continue;
            if (pos >= nur.size()) pos = 0;
            p = nur[pos];
            pos = (pos + 1) % (nur.size() ? nur.size() : 1);
        }

        if (!p) continue;

        WaterCommand waterCmd(p);
        waterCmd.execute();
        
        FertiliseCommand fertiliseCmd(p);
        fertiliseCmd.execute();
        
        PruneCommand pruneCmd(p);
        pruneCmd.execute();
        
        p->changeHealth();

        if (p->getState() == "ReadyForSale") {
            lock_guard<mutex> lk(mtx_);
            if (!manager_->isInSale(p) && manager_->isInNursery(p)) {
                manager_->addToSale(p);
            }
        }
    }
}
