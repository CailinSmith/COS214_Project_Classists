#include "WaterCommand.h"

WaterCommand::WaterCommand(Plant* plant) : StaffCommand() {
	this->plant = plant;
}

void WaterCommand::execute() {
	if (plant != nullptr)
		plant->water();
}
