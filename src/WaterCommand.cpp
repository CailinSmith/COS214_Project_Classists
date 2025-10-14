#include "WaterCommand.h"

WaterCommand::WaterCommand(Plant* plant) : StaffCommand(plant, nullptr, nullptr) {}

void WaterCommand::execute() {
	plant->water();
}
