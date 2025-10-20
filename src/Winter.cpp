#include "Winter.h"

void Winter::change(Nursery* nursery) {
    nursery->setFactory(new SpringFactory());
    nursery->setSeason(new Spring());
}

string Winter::print() {
    return "Winter";
}