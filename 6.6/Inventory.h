#ifndef Inventory_h
#define Inventory_h

#include <list>
#include <vector>

#include "Product.h";

using namespace std;

class Inventory {
public:
	Inventory(vector <Product> inventory);
	void processOrder(int id);
	void processArrival(int arrival);
private:
	vector <Product> inventory_;
	list <Product> backlist_;
};

#endif
