//Exercise 6.1)
//a)

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Date
{
public:
    Date(unsigned int year, unsigned int month, unsigned int day);
    Date(string yearMonthDay); // yearMonthDay must be in format "yyyy/mm/dd"
    void setYear(unsigned int year);
    void setMonth(unsigned int month);
    void setDay(unsigned int day);
    void setDate(unsigned int year, unsigned int month, unsigned int day);
    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;
    string getDate() const; // returns the date in format "yyyy/mm/dd"
    void show() const; // shows the date on the screen in format "yyyy/mm/dd"
private:
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

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

int main()
{
    Date date1("2001/05/19");
    cout << "Date1: " << date1.getDate() << endl;
    Date date2 = date1;
    date2.setDay(04);
    cout << "Date2, Day: " << date2.getDay() << endl;
    date2.setMonth(07);
    cout << "Date2, Month: " << date2.getMonth() << endl;
    date2.setYear(2000);
    cout << "Date2, Year: " << date2.getYear() << endl;
    Date date3(2002, 04, 01);
    date3.show();
    return 0;
}