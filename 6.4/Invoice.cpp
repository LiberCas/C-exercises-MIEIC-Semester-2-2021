#include "Invoice.h"

string doubleToString(double num) {
	string ret = "", numstr = to_string(num);
	int counter = 0, addToCounter = 0;
	for (int i = 0; i < numstr.size(); i++) {
		char elem = numstr[i];
		if (counter == 2)
			break;
		if (addToCounter == 1)
			counter++;
		ret += elem;
		if (elem == '.')
			addToCounter = 1;
	}
	return ret;
}

Invoice::Invoice() {
	purchase = vector<Item>(0);
	total = 0;
}

Invoice::Invoice(vector<Item> purchase, Client client) {
	this->purchase = purchase;
	this->client = client;
	double t=0;
	for (int i=0; i < purchase.size(); i++)
		t += purchase[i].getProdTotal();
	total = t;
}

void Invoice::setPurchase(vector<Item> purchase) {
	this->purchase = purchase;
	double t = 0;
	for (int i=0; i < purchase.size(); i++)
		t += purchase[i].getProdTotal();
	total = t;
}

void Invoice::setClient(Client client) {
	this->client = client;
}

vector <Item> Invoice::getPurchase() {
	return purchase;
}

Client Invoice::getClient() {
	return client;
}

double Invoice::getTotal() {
	return total;
}

string Invoice::getInvoice() {
	string ret = "";
	ret = ret + client.getFormatted() + "\n\n" + "Description          Price  Qty   Total   \n-------------------- ------ ----- --------\n";
	for (int i=0; i < purchase.size(); i++) {
		string tempName = "                    ", tempPrice = "      ", tempQuantity = "     ", tempTotal = "        ";
		string tempName1 = purchase[i].getProduct().getName(), tempPrice1 = doubleToString(purchase[i].getProduct().getPrice()), tempQuantity1 = doubleToString(purchase[i].getQuantity()), tempTotal1 = doubleToString(purchase[i].getProdTotal());
		for (int j = 0; j < tempName1.size(); j++)
			tempName[j] = tempName1[j];
		for (int j=0; j < tempPrice1.size(); j++)
			tempPrice[j] = tempPrice1[j];
		for (int j=0; j < tempQuantity1.size(); j++)
			tempQuantity[j] = tempQuantity1[j];
		for (int j=0; j < tempTotal1.size(); j++)
			tempTotal[j] = tempTotal1[j];
		ret = ret + tempName + " " + tempPrice + " " + tempQuantity + " " + tempTotal + "\n";
	}
	ret = ret + "\nAmount due: " + doubleToString(total) + " euro\n";
	return ret;
}
