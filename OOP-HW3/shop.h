//
//  shop.h
//  OOP-HW3
//
//  Created by Doruk Gezici on 12/05/2017.
//  Copyright © 2017 Doruk Gezici. All rights reserved.
//

#ifndef shop_h
#define shop_h

#include <string>
#include <iostream>
#include "dessert.h"
#include "candy.h"
#include "cookie.h"
#include "icecream.h"

template <class Type>
class Shop {
    Type *desserts;
    std::string type;
    int typeNo;
    int count;
    int discount;
public:
    Shop();
    Shop(Type dessert);
    ~Shop();
    Type& operator[](int i) const;
    const int TAX_RATE = 8;
    int getCount() const;
    void add(Type dessert);
    int getDiscount() const;
    void setDiscount(int discount);
    float getTotalRawCost() const;
    float getTotalCost() const;
    Type& checkStock(std::string name, int type, int quantity) const;
    friend std::ostream& operator<<(std::ostream& os, const Shop<Type>& shop) {
        os << std::endl << "***************************" << std::endl << "Number of items:" << shop.count << std::endl;
        for (int i = 0; i < shop.getCount(); i++) {
            os << i + 1 << ": " << shop[i].getName() << " #" << shop[i].getQuantity() << " Cost: " << shop[i].getCost() << std::endl;
        }
        os << "***************************" << std::endl << "Total cost: " << shop.getTotalRawCost();
        if (shop.getDiscount() > 0) {
            os << std::endl << "Discount: " << shop.getDiscount() << "%" << std::endl;
            os << "Discount amount: -" << shop.getTotalRawCost() * shop.getDiscount() / 100 << std::endl;
            os << "Discounted cost: " << shop.getTotalCost() << std::endl;
            os << "***************************" << std::endl;
        }
        return os;
    }
};

#endif /* shop_h */
