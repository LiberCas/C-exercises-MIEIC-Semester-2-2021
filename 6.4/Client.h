#ifndef Client_h
#define Client_h

#include <string>
#include "Address.h"
using namespace std;

class Client {
public:
	Client();
	Client(string name);
	Client(string name, Address address);
	Client(string name, string street, string number, string code, string municipality);
	Client(string name, string street, string number, string code, string municipality, string additional);
	void setName(string name);
	void setAddress(Address address);
	string getName();
	Address getAddress();
	string getFormatted();
private:
	string name;
	Address address;
};

#endif