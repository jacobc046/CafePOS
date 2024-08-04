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
    OrderNode* current = head;
    
    while(current != nullptr) {
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
    OrderNode* nextNode = current->next;
    
    //traverse the list
    while (nextNode != nullptr) {
        
        //if the next node has the desired input name
        if (nextNode->order.getName() == customerName) {
            
            //get the order total of that node
            float orderTotal = nextNode->order.getTotalPrice();
                
            //connect the current and next nodes together
            current->next = nextNode->next;
            
            //delete the order that was cashed out
            delete nextNode;
            
            //display success to user
            cout << "Order closed with $" << orderTotal << " added to profits!" << endl << endl;
            
            return orderTotal;
        }
        current = current->next;
        nextNode = nextNode->next;
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
            return;
        }
        
        previous = current;
        current = current->next;
    }
}

ostream& operator<<(ostream& os, const OrderList& list) {
    OrderNode* current = list.head;
    
    while (current != nullptr) {
        current->getOrder().printOrder();
        current = current->getNext();
    }
    
    return os;
}
