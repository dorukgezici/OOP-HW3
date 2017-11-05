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
    std::string name;
    int quantity;
    int pricePerQuantity;
public:
    Dessert() {};
    Dessert(std::string name, int quantity, int pricePerQuantity) {
        this->name = name;
        this->quantity = quantity;
        this->pricePerQuantity = pricePerQuantity;
    };
    void setType(std::string type) {
        this->type = type;
    };
    std::string getType() const {
        return type;
    };
    int getTypeNo() const {
        if (type == "cookies") return 1;
        else if (type == "candies") return 2;
        else if (type == "icecream") return 3;
        else return 0;
    };
    virtual std::string getName() const { return name; };
    virtual float getQuantity() const { return quantity; };
    virtual float getPricePerQuantity() const { return pricePerQuantity; };
    virtual float getCost() const { return quantity * pricePerQuantity; };
    friend std::ostream& operator<<(std::ostream& os, const Dessert& dessert) {
        os << std::endl << "***************************" << std::endl;
        os << dessert.getName() << " #" << dessert.getQuantity() << " Cost: " << dessert.getCost() << std::endl;
        os << "***************************" << std::endl;
        return os;
    }
};

#endif /* dessert_h */
