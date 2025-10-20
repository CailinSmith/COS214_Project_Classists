#include "SalesArea.h"

void SalesArea::registerColleague(Staff* colleague) {
    if (colleague && colleague->getPosition() == "Sales staff" || colleague->getPosition() == "Manager")
        colleagues.push_back(colleague);
}