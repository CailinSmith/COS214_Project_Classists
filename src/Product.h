#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;

// Forward declaration
class Plant;

class Product {
public:
    virtual ~Product() {}
    virtual float calculateCost(string currentSeason){
        (void)currentSeason; // Temporary solution to problem of unused parameter warning
        return 0.0;
    };
    virtual string summary(){
        return "";
    };
    virtual string getName(){
        return "DefaultName";
    };
    virtual string getInfo(){
        return "DefaultInfo";
    };
    virtual float getCost(){
        return calculateCost("");
    };
    virtual Plant* getBasePlant(){
        return nullptr;
    }

    //We might need to make them pv later on, just made them virtual 
    //so all the plant subclasses don't need to implement them
};

#endif