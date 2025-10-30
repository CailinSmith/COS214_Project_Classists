#ifndef DECORATOR_H
#define DECORATOR_H

#include "Product.h"
#include "Plant.h"

class Decorator : public Product {

public: 
	Decorator (Product* plant);
	virtual ~Decorator();
	virtual float calculateCost(string currentSeason);
	virtual string summary();
	virtual string getName();
	Product* removeDecorator();
	Plant* getBasePlant() override;

private:
	Product* plant;
};

#endif
