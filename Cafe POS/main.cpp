//
//  main.cpp
//  Cafe POS
//
//  Created by Jacob Croket on 8/3/24.
//

#include "MenuItem.h"
#include "OrderList.h"
#include "MenuIOFunctions.h"
#include "OrderHandlingFunctions.h"

int main() {
    
    //define empty objects for menu items and the orders linked list
    vector<MenuItem> menuItems;
    OrderList orders;

    //read the menu items from the file
    getMenuItems(menuItems);
    
    cout << "Welcome to The Coffee Shop!" << endl << endl;
    
    int choice;
    float totalProfits = 0;
    
    while (true) {
        //display options to user
        cout << "Please choose from the following" << endl;
        cout << "1: Create a new order" << endl;
        cout << "2: Display open orders" << endl;
        cout << "3: Cash out/close an order" << endl;
        cout << "4: Delete an order" << endl;
        cout << "5: Create a new menu item" << endl;
        cout << "0: Quit program" << endl;
        cout << "Enter your choice: ";
        
        getInput(choice);
        
        //execute the appropriate command based on user input
        switch (choice) {
            case 0:
                cout << "Based on the orders you cashed out, your total profits today were $" << totalProfits << "!" << endl;
                cout << "Thanks for shopping!" << endl;
                break;
                
            case 1:
                createNewOrder(menuItems, orders);
                break;
            
            case 2:
                orders.displayOrders();
                break;
                
            case 3:
                totalProfits += orders.closeOrder();
                break;
                
            case 4:
                orders.deleteOrder();
                break;
                
            case 5:
                createNewMenuItem(menuItems);
                break;
                
            default:
                cout << "That is not a valid option." << endl;
                break;
        }
        
        //if the user does not wish to continue,
        //break the loop
        if (choice == 0) {
            break;
        }
    }
    
    //save the menu items to the menu items file
    writeMenuItems(menuItems);
    
    return 0;
}

