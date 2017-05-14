//
//  cookie.cpp
//  OOP-HW3
//
//  Created by Doruk Gezici on 13/05/2017.
//  Copyright © 2017 Doruk Gezici. All rights reserved.
//

#include "cookie.h"

Cookie::Cookie(std::string name, int pieces, int pricePerDozen) {
    this->setType("cookies");
    this->name = name;
    number = pieces;
    this->pricePerDozen = pricePerDozen;
}

std::string Cookie::getName() const {
    return name;
}

float Cookie::getQuantity() const {
    return static_cast<float>(number);
}

float Cookie::getPricePerQuantity() const {
    return static_cast<float>(pricePerDozen);
}

float Cookie::getCost() const {
    return (number * pricePerDozen / 12.0);
}
