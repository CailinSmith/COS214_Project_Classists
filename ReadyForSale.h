#ifndef READYFORSALE_H
#define READYFORSALE_H

#include "PlantState.h"
#include <string>
using namespace std;

class ReadyForSale : public PlantState {

public:
	void change();

	string print();
};

#endif
