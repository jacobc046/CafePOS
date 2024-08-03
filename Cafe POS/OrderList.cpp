//
//  OrderList.cpp
//  Cafe POS
//
//  Created by Jacob Croket on 8/2/24.
//

#include "OrderList.h"

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

void OrderList::deleteOrder(const string name) {
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
