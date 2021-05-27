#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Date.h"

Date::Date() {
    year = 2000;
    month = 1;
    day = 1;
}

Date::Date(unsigned int year, unsigned int month, unsigned int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

Date::Date(string yearMonthDay) {
    stringstream stream(yearMonthDay);
    char trash;
    stream >> year >> trash >> month >> trash >> day;
}

void Date::setYear(unsigned int year) {
    this->year = year;
}

void Date::setMonth(unsigned int month) {
    this->month = month;
}

void Date::setDay(unsigned int day) {
    this->day = day;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

unsigned int Date::getYear() const {
    return year;
}

unsigned int Date::getMonth() const {
    return month;
}

unsigned int Date::getDay() const {
    return day;
}

string Date::getDate() const {// returns the date in format "yyyy/mm/dd"
    stringstream stream1;
    string temp;
    stream1 << year << '/' << month << '/' << day;
    stream1 >> temp;
    return temp;
}

void Date::show() const {
    cout << year << "/" << month << "/" << day << endl;
}
