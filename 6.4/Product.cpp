#include "Product.h"

using namespace std;

Product::Product() {
	name = "";
	price = 0;
}

Product::Product(string name, double price) {
	this->name = name;
	this->price = price;
}

void Product::setName(string name) {
	this->name = name;
}

void Product::setPrice(double price) {
	this->price = price;
}

string Product::getName() {
	return name;
}

double Product::getPrice() {
	return price;
}
