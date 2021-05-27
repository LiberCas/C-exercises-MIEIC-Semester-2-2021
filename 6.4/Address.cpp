#include <string>
#include "Address.h"
using namespace std;

Address::Address() {
	street = "";
	number = "";
	code = "";
	municipality = "";
	additional = "";
}

Address::Address(string street, string number, string code, string municipality) {
	this->street = street;
	this->number = number;
	this->code = code;
	this->municipality = municipality;
	additional = "";
}

Address::Address(string street, string number, string code, string municipality, string additional) {
	this->street = street;
	this->number = number;
	this->code = code;
	this->municipality = municipality;
	this->additional = additional;
}

void Address::setStreet(string street) {
	this->street = street;
}

void Address::setNumber(string number) {
	this->number = number;
}

void Address::setCode(string code) {
	this->code = code;
}

void Address::setMunicipality(string municipality) {
	this->municipality = municipality;
}

void Address::setAdditional(string additional) {
	this->additional = additional;
}

void Address::setInfo1(string street, string number, string code, string municipality) {
	this->street = street;
	this->number = number;
	this->code = code;
	this->municipality = municipality;
	this->additional = "";
}

void Address::setInfo2(string street, string number, string code, string municipality, string additional) {
	this->street = street;
	this->number = number;
	this->code = code;
	this->municipality = municipality;
	this->additional = additional;
}

string Address::getStreet() {
	return street;
}

string Address::getNumber() {
	return number;
}

string Address::getCode() {
	return code;
}

string Address::getMunicipality() {
	return municipality;
}

string Address::getAdditional() {
	return additional;
}

string Address::getInfo() {
	string ret = "";
	if (additional != "")
		ret = ret + additional + "\n";
	ret = ret + street + ", " + number + "\n" + code + " " + municipality;
	return ret;
}
