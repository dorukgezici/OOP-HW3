//
//  icecream.h
//  OOP-HW3
//
//  Created by Doruk Gezici on 12/05/2017.
//  Copyright © 2017 Doruk Gezici. All rights reserved.
//

#ifndef icecream_h
#define icecream_h

#include <string>

class Icecream {
    std::string name;
    float litre;
    int pricePerLitre;
public:
    Icecream(std::string name, float litre, int pricePerLitre);
    float getCost() const;
};

#endif /* icecream_h */
