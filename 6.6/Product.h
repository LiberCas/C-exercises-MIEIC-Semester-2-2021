#ifndef Product_h
#define Product_h

#include <string>
using namespace std;

class Product {
public:
	static int general_id;
	Product(string description, int qty);
	void setQty(int qty);
	void addQty(int qty);
	int getId();
	string getDescription();
	int getQty();
private:
	int id_;
	string description_;
	int qty_;
};

#endif
