//
//  OrderHandlingFunctions.cpp
//  Cafe POS
//
//  Created by Jacob Croket on 8/3/24.
//

#include "OrderHandlingFunctions.h"
#include "OrderList.h"

void createNewOrder(vector<MenuItem>& menuItems, OrderList& orders) {
    //if no menu items have been created
    if (!menuItems.size()) {
        cout << "No menu items have been created." << endl << endl;
        return;
    }
    
    //get customer name
    string customerName;
    cout << "Enter the customer's name: ";
    cin.ignore();
    getline(cin, customerName);
    cout << endl;
    
    //create a new order object with the customer name
    Order order(customerName);
    
    int itemNum;
    
    //add menu items to the order
    while (true) {
        cout << "Enter the item number you wish to add to the order." << endl;
        
        //output menu options to user
        for (int i = 0; i < menuItems.size(); ++i) {
            cout << i + 1 << ": " << menuItems.at(i).getName() << " - $" << menuItems.at(i).getPrice() << endl;
        }
        cout << "0: Complete order" << endl;
        cout << "Enter your choice: " << endl;
        getInput(itemNum);
        
        //if the user completes the order,
        //display the order to the user
        //add the order to the open orders list
        if (itemNum == 0) {
            order.printOrder();
            orders.addOrder(order);
            return;
        }
        
        /* if the number entered is not in range of the options given,
         an out of range exception will be thrown as the vector of menu
         items will attepmt to get an item that does not exist. */
        
        try {
            order.addToOrder(menuItems.at(itemNum-1));
        }
        catch(...) {
            cout << "That is not a valid option" << endl;
            continue; //restart at the top of the loop
        }
    }
}


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
