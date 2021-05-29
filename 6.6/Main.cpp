#include "Inventory.h"

using namespace std;

int main(){
	vector <Product> prods = { Product("Computer", 2), Product("iPhone", 0), Product("Batteries", 5), Product("Sweets", 12) };
	Inventory inventory(prods);
	inventory.processOrder(1);
	inventory.processOrder(1);
	inventory.processOrder(2);
	inventory.processArrival(2);
	inventory.processOrder(1);
	inventory.processArrival(2);
	inventory.processOrder(4);
	inventory.processArrival(1);
	return 0;
}