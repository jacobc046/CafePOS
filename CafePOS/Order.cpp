#include <iostream>
#include "Order.h"

Order::Order(string n) {
    customerName = n;
    totalPrice = 0;
}

//add an item to the order
void Order::addToOrder(MenuItem item) {
    items.push_back(item);
}

//calculate the cost of the order
float Order::getTotalPrice() {
    for (MenuItem i : items) {
        this->totalPrice += i.getPrice();
    }
    return totalPrice;
}

//return the name of the order
string Order::getName() const {
    return customerName;
}

//display the name and items of the order
void Order::printOrder() const {
    cout << customerName << " has ordered: " << endl;
    for (MenuItem item : items) {
        cout << item.getName() << endl;
    }
    cout << endl;
}
