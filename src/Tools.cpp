//
// Created by Gaulthier Boggio on 03/08/2023.
//

#include "Tools.h"

Tools::Tools() {

}

Tools::~Tools() {

}

int Tools::getRandomNumber(int min, int max) {
    std::mt19937 eng(std::random_device{}());
    std::uniform_int_distribution<int> dist(min, max);
    int random_number = dist(eng);
    return random_number;
}
