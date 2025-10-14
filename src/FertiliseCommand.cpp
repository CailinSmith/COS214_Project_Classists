#include "FertiliseCommand.h"

FertiliseCommand::FertiliseCommand(Plant* plant) : StaffCommand(plant, nullptr, nullptr) {}

void FertiliseCommand::execute() {
	plant->fertilise();
}
