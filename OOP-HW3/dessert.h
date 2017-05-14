//
//  dessert.h
//  OOP-HW3
//
//  Created by Doruk Gezici on 14/05/2017.
//  Copyright © 2017 Doruk Gezici. All rights reserved.
//

#ifndef dessert_h
#define dessert_h

#include <string>
#include <iostream>

class Dessert {
    std::string type;
public:
    Dessert() {};
    void setType(std::string type) {
        this->type = type;
    };
    std::string getType() const {
        return type;
    };
    virtual std::string getName() const = 0;
    virtual float getQuantity() const = 0;
    virtual float getPricePerQuantity() const = 0;
    virtual float getCost() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Dessert& dessert) {
        os << std::endl << "***************************" << std::endl;
        os << dessert.getName() << " #" << dessert.getQuantity() << " Cost: " << dessert.getCost() << std::endl;
        os << "***************************" << std::endl;
        return os;
    }
};

#endif /* dessert_h */
