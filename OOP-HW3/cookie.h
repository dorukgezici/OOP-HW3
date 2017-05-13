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

class Cookie {
    std::string name;
    int number;
    int pricePerDozen;
public:
    Cookie(std::string name, int pieces, int pricePerDozen);
    float getCost() const;
};

#endif /* cookie_h */
