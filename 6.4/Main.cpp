#include "Invoice.h"
#include <iostream>
using namespace std;

int main() {
	Client alex("Alex", Address("Bleecker Street", "65", "10012", "New York, NY", "Restaurant"));
	vector <Product> products = { Product("iPhone", 200), Product("Computer", 1000), Product("Battery", 2.5), Product("Sweets", 0.1) };
	vector <Item> purchase23 = { Item(products[0], 2), Item(products[1], 1) , Item(products[2], 5), Item(products[3], 13)};
	cout << Invoice(purchase23, alex).getInvoice();
	return 0;
}
