#include "FertiliseCommand.h"

FertiliseCommand::FertiliseCommand(Plant* plant) : StaffCommand() {
	this->plant = plant;
}

void FertiliseCommand::execute() {
	if (plant != nullptr)
		plant->fertilise();
}
