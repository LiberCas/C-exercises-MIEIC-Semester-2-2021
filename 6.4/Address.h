#ifndef Address_h
#define Address_h

#include <string>

using namespace std;

class Address {
public:
	Address();
	Address(string street, string number, string code, string municipality);
	Address(string street, string number, string code, string municipality, string additional);
	void setStreet(string street);
	void setNumber(string number);
	void setCode(string code);
	void setMunicipality(string municipality);
	void setAdditional(string additional);
	void setInfo1(string street, string number, string code, string municipality);
	void setInfo2(string street, string number, string code, string municipality, string additional);
	string getStreet();
	string getNumber();
	string getCode();
	string getMunicipality();
	string getAdditional();
	string getInfo();
private:
	string street;
	string number;
	string code;
	string municipality;
	string additional;
};

#endif