#include "Item.h"

using namespace std;

Item::Item() {
	product = Product();
	quantity = 0;
	prodTotal = 0;
}

Item::Item(Product product, int quantity) {
	this->product = product;
	this->quantity = quantity;
	prodTotal = (double)quantity * product.getPrice();
}

void Item::setProduct(Product product) {
	this->product = product;
	prodTotal = (double)quantity * product.getPrice();
}

void Item::setQuantity(int quantity) {
	this->quantity = quantity;
	prodTotal = (double)quantity * product.getPrice();
}

void Item::setItem(Product product, int quantity) {
	this->product = product;
	this->quantity = quantity;
	prodTotal = (double)quantity * product.getPrice();
}

Product Item::getProduct() {
	return product;
}

int Item::getQuantity() {
	return quantity;
}

double Item::getProdTotal() {
	return prodTotal;
}
