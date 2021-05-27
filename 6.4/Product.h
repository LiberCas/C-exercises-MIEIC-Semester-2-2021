#ifndef Product_h
#define Product_h

#include <string>
using namespace std;

class Product {
public:
	Product();
	Product(string name, double price);
	void setName(string name);
	void setPrice(double price);
	string getName();
	double getPrice();
private:
	string name;
	double price;
};

#endif