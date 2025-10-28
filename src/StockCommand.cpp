#include "StockCommand.h"

StockCommand::StockCommand() : StaffCommand() {}

void StockCommand::execute() {
    Nursery* nursery = Nursery::getInstance();
    if (nursery) {
        nursery->stockNursery();
    }
}
