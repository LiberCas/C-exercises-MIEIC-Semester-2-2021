#ifndef Invoice_h
#define Invoice_h
#include <vector>
#include "Client.h"
#include "Item.h"

using namespace std;

class Invoice {
public:
	Invoice();
	Invoice(vector<Item> purchase, Client client);
	void setPurchase(vector<Item> purchas);
	void setClient(Client client);
	vector <Item> getPurchase();
	Client getClient();
	double getTotal();
	string getInvoice();
private:
	vector<Item> purchase;
	Client client;
	double total;
};

#endif