//
//  OrderList.cpp
//  Cafe POS
//
//  Created by Jacob Croket on 8/2/24.
//

#include "OrderList.h"
#include "OrderHandlingFunctions.h"

OrderList::OrderList() {
    head = nullptr;
}

OrderList::~OrderList() {
    OrderNode* current = head;
    
    while (current != nullptr) {
        OrderNode* next = current->next;
        delete current;
        current = next;
    }
}

void OrderList::addOrder(const OrderNode& order) {
    if (head == nullptr) {
        head = new OrderNode(order);
        return;
    }
    
    OrderNode* current = head;
    
    while(current->next != nullptr) {
        current = current->next;
    }
    
    current->next = new OrderNode(order);
}

//close and cash out order
float OrderList::closeOrder() {
    
    //get name or order to cash out
    string customerName;
    cout << "Enter the name of the order you would like to close: ";
    getInput(customerName);
    
    OrderNode* current = head;
    OrderNode* previous = head;
    
    //traverse the list
    while (current != nullptr) {
        
        //if the current node has the desired input name
        if (current->order.getName() == customerName) {
            
            OrderNode* orderToClose = current;
            
            //get the order total of that node
            float orderTotal = current->order.getTotalPrice();
            
            if (current == head) {
                head = current->next;
                delete orderToClose;
            } else {
                //connect the current and next nodes together
                previous->next = current->next;
                
                //delete the order that was cashed out
                delete orderToClose;
            }
            
            //display success to user
            cout << "Order closed with $" << orderTotal << " added to profits!" << endl << endl;
            
            return orderTotal;
        }
        previous = current;
        current = current->next;
    }
    
    //because the loop did not return,
    //warn the user that no orders of that name exist
    cout << "There are no orders with this customer name." << endl << endl;
    
    return 0;
}

void OrderList::deleteOrder() {
    string name;
    cout << "Enter the name of the order you would like to delete: ";
    getInput(name);
    
    OrderNode* current = head;
    OrderNode* previous = head;
    
    while(current!= nullptr) {
        if (current->order.getName() == name) {
            OrderNode* temp = current;
            
            if (current == head) {
                head = head->next;
                delete temp;
                return;
            }
            
            previous->next = current->next;
            delete temp;
            cout << "Order deleted successfully." << endl << endl;
            return;
        }
        
        previous = current;
        current = current->next;
    }
    
    //if the loop finishes, alert the user it could not find the order they requested to delete
    cout << "There are no orders with this customer name." << endl << endl;
}

ostream& operator<<(ostream& os, const OrderList& list) {
    OrderNode* current = list.head;
    
    if (current == nullptr) {
        return os << "There are no orders to display." << endl;
    }
    
    while (current != nullptr) {
        current->getOrder().printOrder();
        current = current->getNext();
    }
    
    return os;
}
