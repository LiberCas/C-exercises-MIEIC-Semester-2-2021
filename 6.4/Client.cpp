#include "Client.h"

using namespace std;

Client::Client() {
	name = "";
	address = Address();
}

Client::Client(string name) {
	this->name = name;
	address = Address();
}

Client::Client(string name, Address address) {
	this->name = name;
	this->address = address;
}

Client::Client(string name, string street, string number, string code, string municipality) {
	this->name = name;
	address = Address(street, number, code, municipality);
}

Client::Client(string name, string street, string number, string code, string municipality, string additional) {
	this->name = name;
	address = Address(street, number, code, municipality, additional);
}

void Client::setName(string name) {
	this->name = name;
}

void Client::setAddress(Address address) {
	this->address = address;
}

string Client::getName() {
	return name;
}

Address Client::getAddress() {
	return address;
}

string Client::getFormatted() {
	return address.getInfo();
}