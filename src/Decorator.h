#ifndef DECORATOR_H
#define DECORATOR_H

#include "Product.h"

class Decorator : public Product {

public: 
	Decorator (Product* plant);
	virtual ~Decorator();
	virtual float calculateCost(string currentSeason);
	virtual string getSummary();
	virtual string getName();
	Product* removeDecorator();

private:
	Product* plant;
};

#endif
