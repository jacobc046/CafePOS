//
//  OrderNode.h
//  Cafe POS
//
//  Created by Jacob Croket on 8/2/24.
//

#pragma once

#include "Order.h"

using namespace std;

class OrderNode {
private:
    Order order;
    OrderNode* next;
    
public:
    OrderNode(const Order& order);
    Order getOrder();
    OrderNode* getNext();
    friend class OrderList;
};
