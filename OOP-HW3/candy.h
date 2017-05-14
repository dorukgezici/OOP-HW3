//
//  candy.h
//  OOP-HW3
//
//  Created by Doruk Gezici on 12/05/2017.
//  Copyright © 2017 Doruk Gezici. All rights reserved.
//

#ifndef candy_h
#define candy_h

#include <string>
#include "dessert.h"

class Candy : public Dessert {
    std::string name;
    float weight;
    float pricePerKg;
public:
    Candy() { weight = 0; pricePerKg = 0; };
    Candy(std::string name, float weight, float pricePerKg);
    std::string getName() const;
    float getQuantity() const;
    float getPricePerQuantity() const;
    float getCost() const;
};

#endif /* candy_h */
