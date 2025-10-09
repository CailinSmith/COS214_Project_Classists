#ifndef DECORATOR_H
#define DECORATOR_H

#include "Product.h"

class Decorator : public Product {

private:
	Product* plant;
};

#endif
