#include "StockCommand.h"

StockCommand::StockCommand(Nursery *n) : StaffCommand(nullptr, nullptr, n) {}

void StockCommand::execute() {
    if (nursery) nursery->stockNursery();
}
