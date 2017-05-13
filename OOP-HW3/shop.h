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

template <class Type>
class Shop {
    Type *desserts;
    int count;
    int discount;
    const int TAX_RATE;
public:
    Shop(Type dessert);
    ~Shop();
    Type& operator[](int i) const;
    void add(Type dessert);
    void setDiscount(int discount);
    float getTotalCost() const;
    friend std::ostream& operator<<(std::ostream& os, const Shop<Type>& shop);
};

#endif /* shop_h */
