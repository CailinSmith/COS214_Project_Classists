#include <iostream>
#include "NurseryFacade.h"

int main() {
    NurseryFacade facade;
    //tick interval (milliseconds)
    facade.setTickInterval(std::chrono::milliseconds(5000));
    facade.start();
    return 0;
}
