//
//  OrderList.h
//  Cafe POS
//
//  Created by Jacob Croket on 8/2/24.
//

#pragma once

#include <string>
#include "OrderNode.h"

class OrderList {
private:
    OrderNode* head;
    
public:
    OrderList();
    ~OrderList();
    void addOrder(const OrderNode& order);
    float closeOrder();
    void deleteOrder();
    friend ostream& operator<<(ostream& os, const OrderList& list);
};
