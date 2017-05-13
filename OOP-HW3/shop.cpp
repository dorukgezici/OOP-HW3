//
//  shop.cpp
//  OOP-HW3
//
//  Created by Doruk Gezici on 13/05/2017.
//  Copyright © 2017 Doruk Gezici. All rights reserved.
//

#include "shop.h"

template <class Type>
Shop<Type>::Shop(Type dessert) {
    desserts = new Type[1];
    desserts[0] = dessert;
    count = 1;
    discount = 0;
    TAX_RATE = 8;
}

template <class Type>
Shop<Type>::~Shop() {
    delete[] desserts;
}

template <class Type>
Type& Shop<Type>::operator[](int i) const {
    return desserts[i];
}

template <class Type>
void Shop<Type>::add(Type dessert) {
    
}

template <class Type>
void Shop<Type>::setDiscount(int discount) {
    this->discount = discount;
}

template <class Type>
float Shop<Type>::getTotalCost() const {
    
}

template <class Type>
std::ostream& operator<<(std::ostream& os, const Shop<Type>& shop) {
    os << "***************************" << std::endl << "Number of items:" << shop.count << std::endl;
    for (int i = 0; i < shop.count; i++) {
        os << i + 1 << ": " << shop[i].name << " #" << shop[i].number << " Cost: " << shop[i].getCost() << std::endl;
    }
    return os;
}
