#include "Product.h"

using namespace std;

int Product::general_id = 0;

Product::Product(string description, int qty) {
	general_id++;
	id_ = general_id;
	description_ = description;
	qty_ = qty;
}

void Product::setQty(int qty) {
	qty_ = qty;
}

void Product::addQty(int qty) {
	qty_ += qty;
}

int Product::getId() {
	return id_;
}

string Product::getDescription() {
	return description_;
}

int Product::getQty() {
	return qty_;
}
