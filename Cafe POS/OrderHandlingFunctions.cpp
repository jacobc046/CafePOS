//
//  OrderHandlingFunctions.cpp
//  Cafe POS
//
//  Created by Jacob Croket on 8/3/24.
//

#include "OrderHandlingFunctions.h"

void createNewMenuItem(vector<MenuItem>& menuItems) {
    string itemName;
    float itemPrice;
    
    //get menu item name, allow spaces in input
    cout << "Enter the name of the menu item: ";
    cin.ignore();
    getline(cin, itemName);
    
    //get the item's price and check for input validity
    cout << "Enter the item's price: $";
    getInput(itemPrice);
    cout << endl;
    
    //create a new menu item object and add it to the vector of menu items
    MenuItem newItem(itemName, itemPrice);
    menuItems.push_back(newItem);
    
    return;
}
