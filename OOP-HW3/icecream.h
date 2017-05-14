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
#include "dessert.h"

class Icecream : public Dessert {
    std::string name;
    float litre;
    int pricePerLitre;
public:
    Icecream() { litre = 0; pricePerLitre = 0; };
    Icecream(std::string name, float litre, int pricePerLitre);
    std::string getName() const;
    float getQuantity() const;
    float getPricePerQuantity() const;
    float getCost() const;
};

#endif /* icecream_h */
