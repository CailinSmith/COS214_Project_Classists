#include "PruneCommand.h"

PruneCommand::PruneCommand(Plant* plant) : StaffCommand() {
	this->plant = plant;
}

void PruneCommand::execute() {
	plant->prune();
}
