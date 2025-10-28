#include "Autumn.h"

void Autumn::change(Nursery* nursery) {
    nursery->setFactory(new WinterFactory());
    nursery->setSeason(new Winter());
}

string Autumn::print() {
    return "Autumn";
}