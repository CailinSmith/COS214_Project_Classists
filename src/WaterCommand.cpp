#include "WaterCommand.h"

WaterCommand::WaterCommand(Plant* plant) {
	this->plant = plant;
}

void WaterCommand::execute() {
	plant->water();
}
