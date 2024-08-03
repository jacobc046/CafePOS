//
//  MenuIO.h
//  Cafe POS
//
//  Created by Jacob Croket on 8/3/24.
//

#include <fstream>
#include <vector>
#include "MenuItem.h"

//read the menu items from the file of menu items
void getMenuItems(vector<MenuItem>& menuItems);

//create a new menu item that can be added to orders
void createNewMenuItem(vector<MenuItem>& menuItems);

//write the contents of the menu items vector to a file
void writeMenuItems(const vector<MenuItem>& menuItems);
