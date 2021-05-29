#include "Inventory.h"
#include <iostream>

using namespace std;

Inventory::Inventory(vector <Product> inventory) {
	inventory_ = inventory;
}

void Inventory::processOrder(int id) {
	int i = 0;
	while (i < inventory_.size()) {
		if (inventory_[i].getId() == id)
			break;
		i++;
	}
	if (i >= inventory_.size()) {
		cout << "This product does not exist\n";
		return;
	}
	if (inventory_[i].getQty() > 0) {
		inventory_[i].addQty(-1);
		cout << "Your order has been succesfully processed, the desired product will commence shipping\n";
		return;
	}
	backlist_.push_back(inventory_[i]);
	cout << "The product is currently unavaliable, your order has successfully been placed on the backlist\n";
	return;
}

void Inventory::processArrival(int arrival) {
	for (list <Product> :: iterator it = backlist_.begin(); it != backlist_.end(); ++it)
		if (it->getId() == arrival) {
			cout << "An order has been successfully finished and the arriven product will be shipped to a customer immediately\n";
			backlist_.erase(it);
			return;
		}
	int i = 0;
	while (i < inventory_.size()) {
		if (inventory_[i].getId() == arrival) {
			cout << "The arrival has been successfully processed\n";
			inventory_[i].addQty(1);
			return;
		}
		i++;
	}
}
