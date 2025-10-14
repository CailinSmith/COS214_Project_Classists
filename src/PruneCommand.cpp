#include "PruneCommand.h"

PruneCommand::PruneCommand(Plant* plant) : StaffCommand(plant, nullptr, nullptr) {}

void PruneCommand::execute() {
	plant->prune();
}
