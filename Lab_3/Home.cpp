#include "Home.h"


#include <iostream>

// ============================ Home ============================
Home::Home(int floor) {
    this->floor = floor;
}
void Home::print() {
    if (floor % 10 == 1 && floor % 100 != 11) {
        std::cout << "Дом с " << floor << " этажом" << std::endl;
    } else {
        std::cout << "Дом с " << floor << " этажами" << std::endl;
    }

}
Home::~Home(){}