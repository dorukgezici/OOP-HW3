//
//  icecream.cpp
//  OOP-HW3
//
//  Created by Doruk Gezici on 13/05/2017.
//  Copyright © 2017 Doruk Gezici. All rights reserved.
//

#include "icecream.h"

Icecream::Icecream(std::string name, float litre, int pricePerLitre) {
    this->setType("icecream");
    this->name = name;
    this->litre = litre;
    this->pricePerLitre = pricePerLitre;
}

std::string Icecream::getName() const {
    return name;
}

float Icecream::getQuantity() const {
    return litre;
}

float Icecream::getPricePerQuantity() const {
    return static_cast<float>(pricePerLitre);
}

float Icecream::getCost() const {
    return static_cast<float>(litre * pricePerLitre);
}
