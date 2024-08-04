#include "MenuItem.h"

using namespace std;

MenuItem::MenuItem(string n, float p) {
    name = n;
    price = p;
}

//return the name of the menu item
string MenuItem::getName() const {
    return name;
}

//return the price of tthe menu item 
float MenuItem::getPrice() const {
    return price;
}
