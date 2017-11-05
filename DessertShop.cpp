#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include "shop.h"
#include "dessert.h"
#include "candy.h"
#include "cookie.h"
#include "icecream.h"

using namespace std;


int main() {
    
    Shop<Cookie> cookieStock;
    Shop<Candy> candyStock;
    Shop<Icecream> icecreamStock;
    
    ifstream fileStock("stock.txt");
    string lineStock;
    struct Stock {
        string name;
        int type;
        int itemCount;
        int price;
    };
    int i = 0;
    while (getline(fileStock, lineStock)) {
        stringstream ss(lineStock);
        Stock stock;
        while (getline(ss, lineStock, '\t')) {
            if (i > 3) {
                if (i % 4 == 0) stock.name = lineStock;
                else if (i % 4 == 1) stock.type = stoi(lineStock);
                else if (i % 4 == 2) stock.itemCount = stoi(lineStock);
                else if (i % 4 == 3) {
                    stock.price = stoi(lineStock);
                    switch (stock.type) {
                        case 1:
                        {
                            Cookie cookie(stock.name, stock.itemCount, stock.price);
                            cookieStock.add(cookie);
                            break;
                        }
                        case 2:
                        {
                            Candy candy(stock.name, stock.itemCount, stock.price);
                            candyStock.add(candy);
                            break;
                        }
                        case 3:
                        {
                            Icecream icecream(stock.name, stock.itemCount, stock.price);
                            icecreamStock.add(icecream);
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
            i++;
        }
    }
    
    cout << "~~~~~STOCK~~~~~" << cookieStock << candyStock << icecreamStock << endl << endl;
    
    cout << endl << endl << "~~~~~~~EXPECTED OUTPUT FOR CHECKOUT~~~~~~~" << endl;
    
    Shop<Dessert> checkout;
    checkout.setDiscount(10);
    
    ifstream fileOrder("order.txt");
    ofstream fileCheckout("checkout1.txt");
    string lineOrder;
    struct Order {
        string name;
        int type;
        int quantity;
    };
    int j = 0;
    while(getline(fileOrder, lineOrder)) {
        stringstream ss(lineOrder);
        Order order;
        while(getline(ss, lineOrder, '\t')) {
            if (j % 3 == 0) order.name = lineOrder;
            else if (j % 3 == 1) order.type = stoi(lineOrder);
            else if (j % 3 == 2) {
                order.quantity = stoi(lineOrder);
                Dessert dessert;
                switch (order.type) {
                    case 1:
                    {
                        try {
                            int pricePer = cookieStock.checkStock(order.name, order.type, order.quantity).getPricePerQuantity();
                            dessert = Dessert(order.name, order.quantity, pricePer);
                        } catch (const char *error) {
                            cout << error << endl;
                            fileCheckout << error << endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        try {
                            int pricePer = candyStock.checkStock(order.name, order.type, order.quantity).getPricePerQuantity();
                            dessert = Dessert(order.name, order.quantity, pricePer);
                        } catch (const char *error) {
                            cout << error << endl;
                            fileCheckout << error << endl;
                        }
                        break;
                    }
                    case 3:
                    {
                        try {
                            int pricePer = icecreamStock.checkStock(order.name, order.type, order.quantity).getPricePerQuantity();
                            dessert = Dessert(order.name, order.quantity, pricePer);
                        } catch (const char *error) {
                            cout << error << endl;
                            fileCheckout << error << endl;
                        }
                        break;
                    }
                    default:
                        break;
                }
                checkout.add(dessert);
            }
            j++;
        }
    }
    
    cout << checkout << endl << endl;
    
    cout << endl << endl << "~~~~~~~OUTPUT OF TEST~~~~~~~";
    
    Cookie cookie1("Chocolate Chip Cookies",10, 180); //(name, pieces, priceperdozen)
	Cookie cookie2("Cake Mix Cookies", 16, 210);

	Shop<Cookie> cookieShop(cookie1);
	cookieShop.add(cookie2);
	cout<<cookieShop<<endl;

    //Catch an exception here while trying to access the element at(2)
    try {
        cout << cookieShop[2] << endl;
    } catch (const char *error) {
        cout << "***************************" << endl << error << endl;
    }

	Icecream icecream1("Chocolate ice cream",1.5, 170); //(name, litre, priceperlitre)
	Shop<Icecream> icecreamShop(icecream1);
	cout<<icecreamShop<<endl;

	//Catch an exception here while trying to set the discount to(50)       
    try {
        icecreamShop.setDiscount(50);
    } catch (const char *error) {
        cout << "***************************" << endl << error << endl;
    }

	Candy candy2("Gummi bears",12,89); //(name, weight, priceperkg)
	Candy candy3("Hanukkah gelt",8,110);

	Shop<Candy> candyShop(candy2);
	candyShop.add(candy3);

    candyShop.setDiscount(15);
    cout<<candyShop<<endl;
    
}
	
/*You will also
1) Read dessert stock and customer order from "stock.txt" and "order.txt", respectively.
2) Write the total cost with 10% discount to "checkout.txt".
Expected output for checkout:
!!! We don't have 7 (Orange Jelly Candy)s.
!!! We don't have 11 (Chocolate ice cream)s.
-----------------------
Number of items:4
1: Chocolate Chip Cookies #2 Cost: 100
2: Orange Jelly Candy #5 Cost: 750
3: Chocolate ice cream #2 Cost: 480
4: Cake Mix Cookies #10 Cost: 150
**********************
Total cost: 1598.40
Discount: %10
Discount amount: -159.84
Discounted cost: 1438.56
**********************
*/
