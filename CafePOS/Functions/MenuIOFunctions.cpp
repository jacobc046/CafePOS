//
//  MenuIO.cpp
//  Cafe POS
//
//  Created by Jacob Croket on 8/3/24.
//

#include "MenuIOFunctions.h"
#include "OrderHandlingFunctions.h"

void getMenuItems(vector<MenuItem>& menuItems) {
    
    ifstream menu;
    ifstream prices;
    
    menu.open("menu.txt");
    prices.open("prices.txt");
    
    string itemName;
    float itemPrice;
    
    //read the name of the menu item then the price until there are no more inputs
    //each menu item is of the format:
    //ITEM_NAME
    //ITEM_PRICE
    while (getline(menu, itemName) and prices >> itemPrice) {
        
        //create a new menu item object
        MenuItem newItem(itemName, itemPrice);
        
        //add the object to the vector of menu item objects
        menuItems.push_back(newItem);
    }
    
    menu.close();
    prices.close();
}


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
    
    //save the menu items to the menu items file
    writeMenuItems(menuItems);
    
    return;
}


void writeMenuItems(const vector<MenuItem>& menuItems) {
    ofstream menu;
    ofstream prices;
    
    menu.open("menu.txt");
    prices.open("prices.txt");
    
    for (MenuItem item : menuItems) {
        menu << item.getName() << endl;
        prices << item.getPrice() << endl;
    }
    
    menu.close();
    prices.close();
}
