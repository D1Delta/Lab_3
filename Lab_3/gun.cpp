#include "gun.h"

#include <iostream>

Gun::Gun(int amm) {
    this->ammunition = amm;
}
Gun::Gun() {
    ammunition = 5;
}
void Gun::print() {
    if (ammunition != 0) {
        std::cout << "Бах!" << std::endl;
        ammunition = ammunition - 1;
    } else {
        std::cout << "клатс" << std::endl;
    }
}
Gun::~Gun() {}

