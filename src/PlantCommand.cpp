#include "PlantCommand.h"
PlantCommand::PlantCommand(Plant *p, InventoryManager* im) : StaffCommand() {
    plant = p;
    inventoryManager = im;
}

void PlantCommand::execute()
{
    inventoryManager->addToNursery(plant);
}
