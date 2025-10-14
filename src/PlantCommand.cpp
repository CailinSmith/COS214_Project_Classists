#include "PlantCommand.h"
PlantCommand::PlantCommand(Plant *p, InventoryManager* im) : StaffCommand(p, im, nullptr) {}

void PlantCommand::execute()
{
    inventoryManager->addToNursery(plant);
}
