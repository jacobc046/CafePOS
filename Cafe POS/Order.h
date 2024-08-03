#include <string>
#include <vector>
#include "MenuItem.h"

using namespace std;

class Order {
private:
    vector<MenuItem> items;
    string customerName;
    float totalPrice;
    
public:
    Order(string n);
    void addToOrder(MenuItem item);
    float getTotalPrice();
    string getName() const;
    void printOrder() const;
};
