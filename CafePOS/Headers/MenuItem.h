#pragma once

#include <string>
#include <iostream>

using namespace std;

class MenuItem {
private:
    string name;
    float price;
    
public:
    MenuItem(string n, float p);
    string getName() const;
    float getPrice() const;
};
