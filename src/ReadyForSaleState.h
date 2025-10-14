#ifndef READYFORSALE_H
#define READYFORSALE_H

#include "PlantState.h"
#include "Plant.h"

#include <string>

using namespace std;

class ReadyForSaleState : public PlantState {
public:
	virtual void change(Plant* plant) override;
	virtual string print() override;
};

#endif