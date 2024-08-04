//
//  OrderNode.cpp
//  Cafe POS
//
//  Created by Jacob Croket on 8/2/24.
//

#include "OrderNode.h"

OrderNode::OrderNode(const Order& order) : order(order.getName()) {
    next = nullptr;
}

Order OrderNode::getOrder() { return order; }

OrderNode* OrderNode::getNext() { return next; }
