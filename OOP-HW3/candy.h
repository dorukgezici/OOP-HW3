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

class Candy {
    std::string name;
    float weight;
    int pricePerKg;
public:
    Candy(std::string name, float weight, int pricePerKg);
    float getCost() const;
};

#endif /* candy_h */
