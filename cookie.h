//
//  cookie.h
//  OOP-HW3
//
//  Created by Doruk Gezici on 12/05/2017.
//  Copyright © 2017 Doruk Gezici. All rights reserved.
//

#ifndef cookie_h
#define cookie_h

#include <string>
#include "dessert.h"

class Cookie : public Dessert {
    std::string name;
    int number;
    int pricePerDozen;
public:
    Cookie() { number = 0; pricePerDozen = 0; };
    Cookie(std::string name, int pieces, int pricePerDozen);
    std::string getName() const;
    float getQuantity() const;
    float getPricePerQuantity() const;
    float getCost() const;
};

#endif /* cookie_h */
