#include "doctest.h"
#include <iostream>
#include <vector>
#include <string>
#include "../src/Customer.h"
#include "../src/SalesStaff.h"
#include "../src/NurseryStaff.h"
#include "../src/Rose.h"
#include "../src/Tomato.h"
#include "../src/Manager.h"
#include "../src/AskInfoCommand.h"
#include "../src/CheckStockCommand.h"
#include "../src/RefundCommand.h"
#include "../src/CheckoutCommand.h"
#include "../src/InventoryManager.h"
#include "../src/Nursery.h"

struct TestEnvironment {
    InventoryManager* manager;
    Nursery* nursery;
    TestEnvironment() {
        manager = new InventoryManager();
        nursery = Nursery::getInstance(manager);
    }
    ~TestEnvironment() {
        // Clean up test-created singletons and manager to avoid "still
        // reachable" allocations reported by Valgrind. We destroy the
        // Nursery singleton first (which deletes its season/factory),
        // then delete the InventoryManager.
        if (manager) {
            delete manager;
        }
        if (nursery) { //temporary dele
            Nursery::destroyInstance();
        }
        
    }
};

static TestEnvironment testEnv;


TEST_CASE("CoR + Command: AskInfo") {
    NurseryStaff nursery("Alice");
    Rose rose;
    AskInfoCommand cmd(&nursery, &rose);
    Customer customer("Bob");
    string result = customer.sendCommand(&cmd).first;
    CHECK(result.find("Rose") != string::npos);
}

TEST_CASE("CoR + Command: CheckStock") {
    NurseryStaff nursery("Alice");
    Tomato tomato;
    CheckStockCommand cmd(&nursery, &tomato);
    Customer customer("Bob");
    string result = customer.sendCommand(&cmd).first;
    CHECK(result.find("Tomato") != string::npos);
}

TEST_CASE("CoR + Command: Checkout") {
    SalesStaff sales("Alice");
    Customer customer("Bob");
    Rose rose;
    customer.addToCart(&rose);
    CheckoutCommand cmd(&sales, &customer.getOrder(), nullptr);
    pair<string, Receipt*> p = customer.sendCommand(&cmd);
    string result = p.first;
    Receipt* receipt = p.second;
    CHECK(result.find("Rose") != string::npos);
}

TEST_CASE("CoR + Command: Refund") {
    Manager manager("Alice");
    Customer customer("Bob");

    Rose* rose = new Rose();
    Tomato* tomato = new Tomato();

    customer.addToCart(rose);
    customer.addToCart(tomato);

    std::vector<bool> flags(2, true);
    RefundCommand cmd(&manager, &customer.getOrder(), &flags);
    auto result = customer.sendCommand(&cmd);

    CHECK(result.first.find("Rose") != string::npos);
    CHECK(result.first.find("Tomato") != string::npos);
    CHECK(customer.getOrder().empty());
}

TEST_CASE("CoR + Command: Full Chain Flow") {
    NurseryStaff nursery("Alice");
    SalesStaff sales("Bob");
    Manager manager("Charles");
    nursery.setNext(&sales);
    sales.setNext(&manager);

    Customer customer("Don");
    Rose rose;
    customer.addToCart(&rose);

    // AskInfo
    AskInfoCommand ask(&nursery, &rose);
    CHECK(customer.sendCommand(&ask).first.find("Rose") != string::npos);

    // Checkout
    CheckoutCommand checkout(&nursery, &customer.getOrder(), nullptr);
    CHECK(customer.sendCommand(&checkout).first.find("Rose") != string::npos);
}

TEST_CASE("CoR + Command: Refund - Partial refund (one item)") {
    Manager manager("Mike");
    Customer customer("Bob");

    Rose* rose = new Rose();
    Tomato* tomato = new Tomato();

    customer.addToCart(rose);
    customer.addToCart(tomato);

    std::vector<bool> flags = {true, false};  // Only refund Rose
    RefundCommand cmd(&manager, &customer.getOrder(), &flags);
    auto[result, refundReceipt] = customer.sendCommand(&cmd);

    CHECK(result.find("Rose") != std::string::npos);
    CHECK(result.find("Tomato") == std::string::npos);
    CHECK(customer.getOrder().size() == 1);
    CHECK(refundReceipt == nullptr);

    delete tomato; // no need to delete rose since it was refunded
}

TEST_CASE("CoR + Command: Empty Cart Checkout") {
    SalesStaff sales("Sam");
    Customer customer("Bob");

    CheckoutCommand cmd(&sales, &customer.getOrder(), nullptr);
    auto[result, receipt] = customer.sendCommand(&cmd);
    CHECK(result.find("Error generating receipt") != std::string::npos);
    CHECK(receipt == nullptr);
}

TEST_CASE("CoR + Command: Checkout - SalesStaff generates receipt") {
    SalesStaff sales("Sam");
    Customer customer("Bob");
    Rose rose;
    Tomato tomato;

    customer.addToCart(&rose);
    customer.addToCart(&tomato);

    CheckoutCommand cmd(&sales, &customer.getOrder(), nullptr);
    auto [result, receipt] = customer.sendCommand(&cmd);

    CHECK(result.find("Rose") != std::string::npos);
    CHECK(result.find("Tomato") != std::string::npos);
    CHECK(result.find("$310.00") != std::string::npos);
    CHECK(customer.getOrder().empty());
}
