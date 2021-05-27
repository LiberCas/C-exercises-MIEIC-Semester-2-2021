#include <string>
using namespace std;

#include "Person.h"
#include "Date.h"

Person::Person(){
	name = "";
	gender = 'f';
	birth.setDate(2000, 1, 1);
}

Person::Person(string name, char gender, Date birth){
	this->name = name;
	this->gender = gender;
	this->birth = birth;
}

Person::Person(string name, char gender, int year, int month, int day) {
	this->name = name;
	this->gender = gender;
	birth.setDate(year, month, day);
}

void Person::setName(string name) {
	this->name = name;
}

void Person::setGender(char gender) {
	this->gender = gender;
}

void Person::setBirth(Date birth) {
	this->birth = birth;
}

void Person::setBirthDate(unsigned int year, unsigned int month, unsigned int day) {
	birth.setDate(year, month, day);
}

string Person::getName() {
	return name;
}

char Person::getGender() {
	return gender;
}

Date Person::getBirth() {
	return birth;
}

string Person::getBirthstr() {
	return birth.getDate();
}