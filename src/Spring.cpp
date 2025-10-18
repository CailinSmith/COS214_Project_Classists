#include "Spring.h"

void Spring::change(Nursery* nursery) {
    nursery->setFactory(new SummerFactory());
    nursery->setSeason(new Summer());
}

string Spring::print() {
    return "Spring";
}