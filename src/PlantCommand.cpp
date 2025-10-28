#include "PlantCommand.h"
PlantCommand::PlantCommand(Plant *p, InventoryManager* im) : StaffCommand() {
    plant = p;
    inventoryManager = im;
}

void PlantCommand::execute()
{
    if (inventoryManager != nullptr && plant != nullptr)
        inventoryManager->addToNursery(plant);
}
