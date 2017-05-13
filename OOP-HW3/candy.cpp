//
//  candy.cpp
//  OOP-HW3
//
//  Created by Doruk Gezici on 13/05/2017.
//  Copyright © 2017 Doruk Gezici. All rights reserved.
//

#include "candy.h"

Candy::Candy(std::string name, float weight, int pricePerKg) {
    this->name = name;
    this->weight = weight;
    this->pricePerKg = pricePerKg;
}

float Candy::getCost() const {
    return static_cast<float>(weight * pricePerKg);
}
