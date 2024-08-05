//
//  OrderHandlingFunctions.h
//  Cafe POS
//
//  Created by Jacob Croket on 8/3/24.
//

#pragma once

#include <vector>
#include "OrderList.h"

//create a new order using a vector of MenuItems and the list of orders
void createNewOrder(vector<MenuItem>& menuItems, OrderList& orders);

template<typename Type>
void getInput(Type& input);
