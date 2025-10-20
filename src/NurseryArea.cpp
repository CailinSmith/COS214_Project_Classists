#include "NurseryArea.h"

void NurseryArea::registerColleague(Staff* colleague) {
    if (colleague && colleague->getPosition() == "Nursery staff" || colleague->getPosition() == "Manager" || colleague->getPosition() == "Intern")
        colleagues.push_back(colleague);
}