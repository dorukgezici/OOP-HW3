//
//  shop.cpp
//  OOP-HW3
//
//  Created by Doruk Gezici on 13/05/2017.
//  Copyright © 2017 Doruk Gezici. All rights reserved.
//

#include "shop.h"

template <class Type>
Shop<Type>::Shop() {
    desserts = new Type[1];
    type = "dessert";
    typeNo = 0;
    count = 0;
    discount = 0;
}

template <class Type>
Shop<Type>::Shop(Type dessert) {
    desserts = new Type[1];
    desserts[0] = dessert;
    type = dessert.getType();
    typeNo = dessert.getTypeNo();
    count = 1;
    discount = 0;
}

template <class Type>
Shop<Type>::~Shop() {
    delete[] desserts;
}

template <class Type>
Type& Shop<Type>::operator[](int i) const {
    if (i < count) {
        return desserts[i];
    } else {
        std::string error = "We don't have enough ";
        error.append(desserts[0].getType());
        error.append("!");
        throw error.c_str();
    }
}

template <class Type>
int Shop<Type>::getCount() const {
    return count;
}

template <class Type>
void Shop<Type>::add(Type dessert) {
    Type *tmp = new Type[count + 1];
    for (int i = 0; i < count; i++) {
        tmp[i] = desserts[i];
    }
    tmp[count] = dessert;
    desserts = tmp;
    type = dessert.getType();
    typeNo = dessert.getTypeNo();
    count++;
}

template <class Type>
int Shop<Type>::getDiscount() const {
    return discount;
}

template <class Type>
void Shop<Type>::setDiscount(int discount) {
    if (discount <= 30 && discount >= 0) {
        this->discount = discount;
    } else throw "Discount rate is out of range!";
}

template<class Type>
float Shop<Type>::getTotalRawCost() const {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += desserts[i].getCost();
    }
    total = total * (100 + TAX_RATE) / 100;
    return total;
}

template<class Type>
float Shop<Type>::getTotalCost() const {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += desserts[i].getCost();
    }
    total = total * (100 + TAX_RATE) / 100;
    total = total - (total * discount / 100);
    return total;
}

template <class Type>
Type& Shop<Type>::checkStock(std::string name, int type, int quantity) const {
    if (this->typeNo == type) {
        for (int i = 0; i < count; i++) {
            if (desserts[i].getName() == name && desserts[i].getQuantity() >= quantity) {
                return desserts[i];
            }
        }
    }
    std::string error = "!!! We don't have ";
    error.append(std::to_string(quantity));
    error.append(" (");
    error.append(name);
    error.append(")s.");
    throw error.c_str();
    
}

template class Shop<Dessert>;
template class Shop<Candy>;
template class Shop<Cookie>;
template class Shop<Icecream>;
