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


//check validity of an input
template<typename Type>
void getInput(Type& input) {
    cin.exceptions(ios::failbit);
    
    //if the input fails, alert the user and
    //display the error message passed in
    while (true) {
        try {
            cin >> input;
        }
        catch (ios_base::failure &err) {
            cout << "That is not a valid input, try again: ";
            cin.clear();
            string garbage;
            cin >> garbage;
            continue;
        }
        return;
    }
}
