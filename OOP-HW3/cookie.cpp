//
//  cookie.cpp
//  OOP-HW3
//
//  Created by Doruk Gezici on 13/05/2017.
//  Copyright © 2017 Doruk Gezici. All rights reserved.
//

#include "cookie.h"

Cookie::Cookie(std::string name, int pieces, int pricePerDozen) {
    this->name = name;
    number = pieces;
    this->pricePerDozen = pricePerDozen;
}

float Cookie::getCost() const {
    return number * pricePerDozen / 12.0;
}
