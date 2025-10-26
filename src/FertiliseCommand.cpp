#include "FertiliseCommand.h"

FertiliseCommand::FertiliseCommand(Plant* plant) : StaffCommand() {
	this->plant = plant;
}

void FertiliseCommand::execute() {
	plant->fertilise();
}
