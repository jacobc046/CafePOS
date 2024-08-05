//
//  MenuIO.cpp
//  Cafe POS
//
//  Created by Jacob Croket on 8/3/24.
//

#include "MenuIOFunctions.h"
#include "OrderHandlingFunctions.h"

//read the menu items and prices from their respective files
void getMenuItems(vector<MenuItem>& menuItems) {
    ifstream menu;
    ifstream prices;
    
    menu.open("menu.txt");
    prices.open("prices.txt");
    
    string itemName;
    float itemPrice;
    
    //read each menu item name and price
    while (getline(menu, itemName) and prices >> itemPrice) {
        
        //create a new menu item object
        MenuItem newItem(itemName, itemPrice);
        
        //add the object to the vector of menu item objects
        menuItems.push_back(newItem);
    }
    
    menu.close();
    prices.close();
}


//create a new item that can be used when creating orders
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


//write and save the menu item name and price data to their files
void writeMenuItems(const vector<MenuItem>& menuItems) {
    ofstream menu;
    ofstream prices;
    
    menu.open("menu.txt");
    prices.open("prices.txt");
    
    //write data
    for (MenuItem item : menuItems) {
        menu << item.getName() << endl;
        prices << item.getPrice() << endl;
    }
    
    menu.close();
    prices.close();
}
