#include "Summer.h"

void Summer::change(Nursery* nursery) {
    nursery->setFactory(new AutumnFactory());
    nursery->setSeason(new Autumn());
}

string Summer::print() {
    return "Summer";
}