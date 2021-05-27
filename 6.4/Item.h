#ifndef Item_h
#define Item_h

#include "Product.h"

using namespace std;

class Item {
public:
	Item();
	Item(Product product, int quantity);
	void setProduct(Product product);
	void setQuantity(int quantity);
	void setItem(Product product, int quantity);
	Product getProduct();
	int getQuantity();
	double getProdTotal();
private:
	Product product;
	int quantity;
	double prodTotal;
};

#endif