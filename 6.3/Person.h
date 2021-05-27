#ifndef Person_h
#define Person_h

#include <string>
using namespace std;

#include "Date.h"

class Person {
public:
	Person();
	Person(string name, char gender, Date birth);
	Person(string name, char gender, int year, int month, int day);
	void setName(string name);
	void setGender(char gender);
	void setBirth(Date birth);
	void setBirthDate(unsigned int year, unsigned int month, unsigned int day);
	string getName();
	char getGender();
	Date getBirth();
	string getBirthstr();
private:
	string name;
	char gender;
	Date birth;
};

#endif