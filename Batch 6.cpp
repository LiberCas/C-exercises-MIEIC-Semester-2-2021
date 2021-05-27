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


//b)

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

int daysInMonth(int month, int year) {
    if ((month < 8 && month % 2 != 0) || (month >= 8 && month % 2 == 0))
        return 31;
    else if (month == 2) {
        int leap = isLeap(year);
        if (leap == 1)
            return 29;
        else
            return 28;
    }
    else
        return 30;
}

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
    bool isValid() const;
    bool isEqualTo(const Date& date);
    bool isNotEqualTo(const Date& date);
    bool isAfter(const Date& date);
    bool isBefore(const Date& date);
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

bool Date::isValid() const {
    if (daysInMonth(month, year) < day) {
        return 0;
    }
    return 1;
}

bool Date::isEqualTo(const Date& date) {
    if (year != date.getYear())
        return 0;
    else if (month != date.getMonth())
        return 0;
    else if (day != date.getDay())
        return 0;
    return 1;
}

bool Date::isNotEqualTo(const Date& date) {
    if (year != date.getYear())
        return 1;
    else if (month != date.getMonth())
        return 1;
    else if (day != date.getDay())
        return 1;
    return 0;
}

bool Date::isAfter(const Date& date) {
    if (year > date.getYear())
        return 1;
    else if (year < date.getYear())
        return 0;
    else if (month > date.getMonth())
        return 1;
    else if (month < date.getMonth())
        return 0;
    else if (day > date.getDay())
        return 1;
    return 0;
}

bool Date::isBefore(const Date& date) {
    if (year > date.getYear())
        return 0;
    else if (year < date.getYear())
        return 1;
    else if (month > date.getMonth())
        return 0;
    else if (month < date.getMonth())
        return 1;
    else if (day < date.getDay())
        return 1;
    return 0;
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
    cout << "Date3, valid? " << date3.isValid() << endl;
    cout << "2001/02/29, valid? " << Date(2001, 02, 29).isValid() << endl;
    cout << "Date2 == Date3? " << date3.isEqualTo(date2) << endl;
    cout << "Date3 == 2002/04/01? " << date3.isEqualTo(Date(2002, 04, 01)) << endl;
    cout << "Date3 != 2002/04/01? " << date3.isNotEqualTo(Date(2002, 04, 01)) << endl;
    cout << "2002/04/07 > Date3? " << Date(2002, 04, 07).isAfter(date3) << endl;
    cout << "2002/02/21 > Date3? " << date3.isBefore(Date(2002, 02, 21)) << endl;
    return 0;
}


//c)Because the class Date has no default constructor

//d)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;

bool isLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

int daysInMonth(int month, int year) {
    if ((month < 8 && month % 2 != 0) || (month >= 8 && month % 2 == 0))
        return 31;
    else if (month == 2) {
        int leap = isLeap(year);
        if (leap == 1)
            return 29;
        else
            return 28;
    }
    else
        return 30;
}

class Date
{
public:
    Date(unsigned int year, unsigned int month, unsigned int day);
    Date(string yearMonthDay); // yearMonthDay must be in format "yyyy/mm/dd"
    Date();
    void setYear(unsigned int year);
    void setMonth(unsigned int month);
    void setDay(unsigned int day);
    void setDate(unsigned int year, unsigned int month, unsigned int day);
    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;
    string getDate() const; // returns the date in format "yyyy/mm/dd"
    void show() const; // shows the date on the screen in format "yyyy/mm/dd"
    bool isValid() const;
    bool isEqualTo(const Date& date);
    bool isNotEqualTo(const Date& date);
    bool isAfter(const Date& date);
    bool isBefore(const Date& date);
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

Date::Date() {
    time_t theTime = time(NULL);
    struct tm* aTime = localtime(&theTime);
    day = aTime->tm_mday;
    month = aTime->tm_mon + 1;
    year = aTime->tm_year + 1900;
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

bool Date::isValid() const {
    if (daysInMonth(month, year) < day) {
        return 0;
    }
    return 1;
}

bool Date::isEqualTo(const Date& date) {
    if (year != date.getYear())
        return 0;
    else if (month != date.getMonth())
        return 0;
    else if (day != date.getDay())
        return 0;
    return 1;
}

bool Date::isNotEqualTo(const Date& date) {
    if (year != date.getYear())
        return 1;
    else if (month != date.getMonth())
        return 1;
    else if (day != date.getDay())
        return 1;
    return 0;
}

bool Date::isAfter(const Date& date) {
    if (year > date.getYear())
        return 1;
    else if (year < date.getYear())
        return 0;
    else if (month > date.getMonth())
        return 1;
    else if (month < date.getMonth())
        return 0;
    else if (day > date.getDay())
        return 1;
    return 0;
}

bool Date::isBefore(const Date& date) {
    if (year > date.getYear())
        return 0;
    else if (year < date.getYear())
        return 1;
    else if (month > date.getMonth())
        return 0;
    else if (month < date.getMonth())
        return 1;
    else if (day < date.getDay())
        return 1;
    return 0;
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
    cout << "Date3, valid? " << date3.isValid() << endl;
    cout << "2001/02/29, valid? " << Date(2001, 02, 29).isValid() << endl;
    cout << "Date2 == Date3? " << date3.isEqualTo(date2) << endl;
    cout << "Date3 == 2002/04/01? " << date3.isEqualTo(Date(2002, 04, 01)) << endl;
    cout << "Date3 != 2002/04/01? " << date3.isNotEqualTo(Date(2002, 04, 01)) << endl;
    cout << "2002/04/07 > Date3? " << Date(2002, 04, 07).isAfter(date3) << endl;
    cout << "2002/02/21 > Date3? " << date3.isBefore(Date(2002, 02, 21)) << endl;
    Date date4;
    date4.show();
    return 0;
}


//e)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;

bool isLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

int daysInMonth(int month, int year) {
    if ((month < 8 && month % 2 != 0) || (month >= 8 && month % 2 == 0))
        return 31;
    else if (month == 2) {
        int leap = isLeap(year);
        if (leap == 1)
            return 29;
        else
            return 28;
    }
    else
        return 30;
}

class Date
{
public:
    Date(unsigned int year, unsigned int month, unsigned int day);
    Date(string yearMonthDay); // yearMonthDay must be in format "yyyy/mm/dd"
    Date();
    void setYear(unsigned int year);
    void setMonth(unsigned int month);
    void setDay(unsigned int day);
    void setDate(unsigned int year, unsigned int month, unsigned int day);
    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;
    string getDate() const; // returns the date in format "yyyy/mm/dd"
    void show() const; // shows the date on the screen in format "yyyy/mm/dd"
    bool isValid() const;
    bool isEqualTo(const Date& date);
    bool isNotEqualTo(const Date& date);
    bool isAfter(const Date& date);
    bool isBefore(const Date& date);
private:
    string date;
};

Date::Date(unsigned int year, unsigned int month, unsigned int day) {
    stringstream stream;
    stream.fill('0');
    stream.width(4);
    stream << year;
    stream.width(2);
    stream << month;
    stream.width(2);
    stream << day;
    date = stream.str();
}

Date::Date(string yearMonthDay) {
    stringstream stream;
    stream << yearMonthDay.substr(0, 4) << yearMonthDay.substr(5, 2) << yearMonthDay.substr(8, 2);
    date = stream.str();
}

Date::Date() {
    stringstream stream;
    time_t theTime = time(NULL);
    struct tm* aTime = localtime(&theTime);
    stream.fill('0');
    stream.width(4);
    stream << aTime->tm_year + 1900;
    stream.width(2);
    stream << aTime->tm_mon + 1;
    stream.width(2);
    stream << aTime->tm_mday;
    date = stream.str();
}

void Date::setYear(unsigned int year) {
    stringstream stream;
    stream.fill('0');
    stream.width(4);
    stream << year;
    date.replace(0, 4, stream.str());
}

void Date::setMonth(unsigned int month) {
    stringstream stream;
    stream.fill('0');
    stream.width(2);
    stream << month;
    date.replace(4, 2, stream.str());
}

void Date::setDay(unsigned int day) {
    stringstream stream;
    stream.fill('0');
    stream.width(2);
    stream << day;
    date.replace(6, 2, stream.str());
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day) {
    stringstream stream;
    stream.fill('0');
    stream.width(4);
    stream << year;
    stream.width(2);
    stream << month;
    stream.width(2);
    stream << day;
    date = stream.str();
}

unsigned int Date::getYear() const {
    stringstream stream;
    stream << date.substr(0, 4);
    int year;
    stream >> year;
    return year;
}

unsigned int Date::getMonth() const {
    stringstream stream;
    stream << date.substr(4, 2);
    int month;
    stream >> month;
    return month;
}

unsigned int Date::getDay() const {
    stringstream stream;
    stream << date.substr(6, 2);
    int day;
    stream >> day;
    return day;
}

string Date::getDate() const {// returns the date in format "yyyy/mm/dd"
    stringstream stream1;
    string temp;
    stream1 << date.substr(0, 4) << '/' << date.substr(4, 2) << '/' << date.substr(6, 2);
    stream1 >> temp;
    return temp;
}

void Date::show() const {
    cout << date.substr(0, 4) << '/' << date.substr(4, 2) << '/' << date.substr(6, 2) << endl;
}

bool Date::isValid() const {
    stringstream stream;
    stream << date.substr(0, 4) << ' ' << date.substr(4, 2) << ' ' << date.substr(6, 2);
    int year, month, day;
    stream >> year;
    stream >> month;
    stream >> day;
    if (daysInMonth(month, year) < day) {
        return 0;
    }
    return 1;
}

bool Date::isEqualTo(const Date& date) {
    stringstream stream;
    stream << this->date.substr(0, 4) << ' ' << this->date.substr(4, 2) << ' ' << this->date.substr(6, 2);
    int year, month, day;
    stream >> year;
    stream >> month;
    stream >> day;
    if (year != date.getYear())
        return 0;
    else if (month != date.getMonth())
        return 0;
    else if (day != date.getDay())
        return 0;
    return 1;
}

bool Date::isNotEqualTo(const Date& date) {
    stringstream stream;
    stream << this->date.substr(0, 4) << ' ' << this->date.substr(4, 2) << ' ' << this->date.substr(6, 2);
    int year, month, day;
    stream >> year;
    stream >> month;
    stream >> day;
    if (year != date.getYear())
        return 1;
    else if (month != date.getMonth())
        return 1;
    else if (day != date.getDay())
        return 1;
    return 0;
}

bool Date::isAfter(const Date& date) {
    stringstream stream;
    stream << this->date.substr(0, 4) << ' ' << this->date.substr(4, 2) << ' ' << this->date.substr(6, 2);
    int year, month, day;
    stream >> year;
    stream >> month;
    stream >> day;
    if (year > date.getYear())
        return 1;
    else if (year < date.getYear())
        return 0;
    else if (month > date.getMonth())
        return 1;
    else if (month < date.getMonth())
        return 0;
    else if (day > date.getDay())
        return 1;
    return 0;
}

bool Date::isBefore(const Date& date) {
    stringstream stream;
    stream << this->date.substr(0, 4) << ' ' << this->date.substr(4, 2) << ' ' << this->date.substr(6, 2);
    int year, month, day;
    stream >> year;
    stream >> month;
    stream >> day;
    if (year > date.getYear())
        return 0;
    else if (year < date.getYear())
        return 1;
    else if (month > date.getMonth())
        return 0;
    else if (month < date.getMonth())
        return 1;
    else if (day < date.getDay())
        return 1;
    return 0;
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
    cout << "Date3, valid? " << date3.isValid() << endl;
    cout << "2001/02/29, valid? " << Date(2001, 02, 29).isValid() << endl;
    cout << "Date2 == Date3? " << date3.isEqualTo(date2) << endl;
    cout << "Date3 == 2002/04/01? " << date3.isEqualTo(Date(2002, 04, 01)) << endl;
    cout << "Date3 != 2002/04/01? " << date3.isNotEqualTo(Date(2002, 04, 01)) << endl;
    cout << "2002/04/07 > Date3? " << Date(2002, 04, 07).isAfter(date3) << endl;
    cout << "2002/02/21 > Date3? " << date3.isBefore(Date(2002, 02, 21)) << endl;
    Date date4;
    date4.show();
    return 0;
}


//Exercise 6.2)
//a)

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;

class Student {
public:
    Student();
    Student(const string& code, const string& name);
    void setGrades(double shortExam, double project, double exam);
    string getCode() const;
    string getName() const;
    int getFinalGrade() const;
    // other get and set methods
    bool isApproved() const; // is the student approved or not ?
    static int weightShortExam, weightProject, weightExam; // weights in percentage (ex:20,30,50)
private:
    string code; // student code
    string name; // student complete name
    double shortExam, project, exam; // grades obtained by the student in the different components
    int finalGrade;
};

int Student::weightShortExam = 20;
int Student::weightProject = 30;
int Student::weightExam = 50;


Student::Student() {
    code = "";
    name = "";
    shortExam = 0;
    project = 0;
    exam = 0;
    finalGrade = 0;
}

Student::Student(const string& code, const string& name) {
    this->code = code;
    this->name = name;
    shortExam = 0;
    project = 0;
    exam = 0;
    finalGrade = 0;
}

void Student::setGrades(double shortExam, double project, double exam) {
    this->shortExam = shortExam;
    this->project = project;
    this->exam = exam;
    double temp = ((weightShortExam * shortExam) + (weightProject * project) + (weightExam * exam)) / 100;
    if (temp - (int)temp > 0.49999999)
        temp += 0.6;
    finalGrade = (int)temp;
}

int Student::getFinalGrade() const {
    return finalGrade;
}

bool Student::isApproved() const {
    if (finalGrade >= 10)
        return 1;
    return 0;
}

int main()
{
    Student stu("up202000000", "Student");
    stu.setGrades(13, 5, 14.8);
    cout << "Final grade: " << stu.getFinalGrade() << " - Status: " << stu.isApproved() << endl;
    return 0;
}
//The static qualifier ensures that the 3 weight attributes are shared between all objects of class Student


//b)

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;

class Student {
public:
    Student();
    Student(const string& code, const string& name);
    void setGrades(double shortExam, double project, double exam);
    string getCode() const;
    string getName() const;
    int getFinalGrade() const;
    // other get and set methods
    bool isApproved() const; // is the student approved or not ?
    static int weightShortExam, weightProject, weightExam; // weights in percentage (ex:20,30,50)
private:
    string code; // student code
    string name; // student complete name
    double shortExam, project, exam; // grades obtained by the student in the different components
    int finalGrade;
};

int Student::weightShortExam = 20;
int Student::weightProject = 30;
int Student::weightExam = 50;


Student::Student() {
    code = "";
    name = "";
    shortExam = 0;
    project = 0;
    exam = 0;
    finalGrade = 0;
}

Student::Student(const string& code, const string& name) {
    this->code = code;
    this->name = name;
    shortExam = 0;
    project = 0;
    exam = 0;
    finalGrade = 0;
}

void Student::setGrades(double shortExam, double project, double exam) {
    this->shortExam = shortExam;
    this->project = project;
    this->exam = exam;
    double temp = ((weightShortExam * shortExam) + (weightProject * project) + (weightExam * exam)) / 100;
    if (temp - (int)temp > 0.49999999)
        temp += 0.6;
    finalGrade = (int)temp;
}

int Student::getFinalGrade() const {
    return finalGrade;
}

bool Student::isApproved() const {
    if (finalGrade >= 10)
        return 1;
    return 0;
}

Student readStudentData() {
    char trash;
    string  code, name;
    double shortExam, project, exam;
    cout << "Student Code?\n";
    cin >> code;
    cout << "Student Name?\n";
    cin.clear();
    cin.ignore(1000, '\n');
    getline(cin, name);
    Student temp(code, name);
    cout << "Short exam grade?\n";
    cin >> shortExam;
    cout << "Project grade ?\n";
    cin >> project;
    cout << "Exam grade ?\n";
    cin >> exam;
    temp.setGrades(shortExam, project, exam);
    return temp;
}

int main()
{
    Student stu1("up202000000", "Student"), stu2;
    stu1.setGrades(13, 5, 14.8);
    cout << "Final grade: " << stu1.getFinalGrade() << " - Status: " << stu1.isApproved() << endl;
    stu2 = readStudentData();
    cout << "Final grade: " << stu2.getFinalGrade() << " - Status: " << stu2.isApproved() << endl;
    return 0;
}


//c)

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Student {
public:
    Student();
    Student(const string& code, const string& name);
    Student(const string& code, const string& name, double shortExam, double project, double exam);
    void setGrades(double shortExam, double project, double exam);
    string getCode() const;
    string getName() const;
    int getFinalGrade() const;
    // other get and set methods
    bool isApproved() const; // is the student approved or not ?
    static int weightShortExam, weightProject, weightExam; // weights in percentage (ex:20,30,50)
private:
    string code; // student code
    string name; // student complete name
    double shortExam, project, exam; // grades obtained by the student in the different components
    int finalGrade;
};

int Student::weightShortExam = 20;
int Student::weightProject = 30;
int Student::weightExam = 50;


Student::Student() {
    code = "";
    name = "";
    shortExam = 0;
    project = 0;
    exam = 0;
    finalGrade = 0;
}

Student::Student(const string& code, const string& name) {
    this->code = code;
    this->name = name;
    shortExam = 0;
    project = 0;
    exam = 0;
    finalGrade = 0;
}

Student::Student(const string& code, const string& name, double shortExam, double project, double exam) {
    this->code = code;
    this->name = name;
    setGrades(shortExam, project, exam);
}

void Student::setGrades(double shortExam, double project, double exam) {
    this->shortExam = shortExam;
    this->project = project;
    this->exam = exam;
    double temp = ((weightShortExam * shortExam) + (weightProject * project) + (weightExam * exam)) / 100;
    if (temp - (int)temp > 0.49999999)
        temp += 0.6;
    finalGrade = (int)temp;
}

string Student::getCode() const {
    return code;
}

string Student::getName() const {
    return name;
}

int Student::getFinalGrade() const {
    return finalGrade;
}

bool Student::isApproved() const {
    if (finalGrade >= 10)
        return 1;
    return 0;
}

double getGradeAverage(vector<Student> vec) {
    double finalGradeAverage = 0;
    for (int i = 0; i < vec.size(); i++) {
        finalGradeAverage += vec[i].getFinalGrade();
    }
    finalGradeAverage /= vec.size();
    return finalGradeAverage;
}

void showAboveAverageStudents(ostream& stream, vector<Student> vec) {
    double finalGradeAverage = getGradeAverage(vec);
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].getFinalGrade() > finalGradeAverage) {
            stream << vec[i].getName() << " - " << vec[i].getCode() << " - " << vec[i].getFinalGrade() << endl;
        }
    }

}

int main()
{
    Student stu1("1", "I L", 18, 17, 7);
    Student stu2("2", "M B", 3, 11, 1);
    Student stu3("3", "L L", 3, 5, 13);
    Student stu4("4", "S L", 12, 10, 7);
    Student stu5("5", "J C", 13, 19, 5);
    Student stu6("6", "M E B", 19, 2, 1);
    Student stu7("7", "R C", 9, 13, 13);
    Student stu8("8", "L G", 17, 14, 13);
    Student stu9("9", "Y L", 15, 10, 17);
    Student stu10("10", "E L", 1, 8, 15);
    vector<Student> stu_vec = { stu1, stu2, stu3, stu4, stu5, stu6, stu7, stu8, stu9, stu10 };
    showAboveAverageStudents(cout, stu_vec);
    return 0;
}


//d)

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Student {
public:
    Student();
    Student(const string& code, const string& name);
    Student(const string& code, const string& name, double shortExam, double project, double exam);
    void setGrades(double shortExam, double project, double exam);
    string getCode() const;
    string getName() const;
    int getFinalGrade() const;
    // other get and set methods
    bool isApproved() const; // is the student approved or not ?
    static int weightShortExam, weightProject, weightExam; // weights in percentage (ex:20,30,50)
private:
    string code; // student code
    string name; // student complete name
    double shortExam, project, exam; // grades obtained by the student in the different components
    int finalGrade;
};

int Student::weightShortExam = 20;
int Student::weightProject = 30;
int Student::weightExam = 50;


Student::Student() {
    code = "";
    name = "";
    shortExam = 0;
    project = 0;
    exam = 0;
    finalGrade = 0;
}

Student::Student(const string& code, const string& name) {
    this->code = code;
    this->name = name;
    shortExam = 0;
    project = 0;
    exam = 0;
    finalGrade = 0;
}

Student::Student(const string& code, const string& name, double shortExam, double project, double exam) {
    this->code = code;
    this->name = name;
    setGrades(shortExam, project, exam);
}

void Student::setGrades(double shortExam, double project, double exam) {
    this->shortExam = shortExam;
    this->project = project;
    this->exam = exam;
    double temp = ((weightShortExam * shortExam) + (weightProject * project) + (weightExam * exam)) / 100;
    if (temp - (int)temp > 0.49999999)
        temp += 0.6;
    finalGrade = (int)temp;
}

string Student::getCode() const {
    return code;
}

string Student::getName() const {
    return name;
}

int Student::getFinalGrade() const {
    return finalGrade;
}

bool Student::isApproved() const {
    if (finalGrade >= 10)
        return 1;
    return 0;
}

double getGradeAverage(vector<Student> vec) {
    double finalGradeAverage = 0;
    for (int i = 0; i < vec.size(); i++) {
        finalGradeAverage += vec[i].getFinalGrade();
    }
    finalGradeAverage /= vec.size();
    return finalGradeAverage;
}

void showAboveAverageStudents(ostream& stream, vector<Student> vec) {
    double finalGradeAverage = getGradeAverage(vec);
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].getFinalGrade() > finalGradeAverage) {
            stream << vec[i].getName() << " - " << vec[i].getCode() << " - " << vec[i].getFinalGrade() << endl;
        }
    }

}

Student readStudentData() {
    string  code, name;
    double shortExam, project, exam;
    cout << "Student Code?\n";
    cin >> code;
    cout << "Student Name?\n";
    cin.clear();
    cin.ignore(1000, '\n');
    getline(cin, name);
    cout << "Short exam grade?\n";
    cin >> shortExam;
    cout << "Project grade ?\n";
    cin >> project;
    cout << "Exam grade ?\n";
    cin >> exam;
    return Student(code, name, shortExam, project, exam);
}

int main()
{
    vector<Student> stu_vec;
    while (true) {
        char selection;
        stu_vec.push_back(readStudentData());
        cout << "Press '0' to exit. Press any other key to enter another student.\n";
        cin >> selection;
        if (selection == '0')
            break;
    }
    showAboveAverageStudents(cout, stu_vec);
    return 0;
}


//e)

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

class Student {
public:
    Student();
    Student(const string& code, const string& name);
    Student(const string& code, const string& name, double shortExam, double project, double exam);
    void setGrades(double shortExam, double project, double exam);
    string getCode() const;
    string getName() const;
    int getFinalGrade() const;
    // other get and set methods
    bool isApproved() const; // is the student approved or not ?
    static int weightShortExam, weightProject, weightExam; // weights in percentage (ex:20,30,50)
private:
    string code; // student code
    string name; // student complete name
    double shortExam, project, exam; // grades obtained by the student in the different components
    int finalGrade;
};

int Student::weightShortExam = 20;
int Student::weightProject = 30;
int Student::weightExam = 50;


Student::Student() {
    code = "";
    name = "";
    shortExam = 0;
    project = 0;
    exam = 0;
    finalGrade = 0;
}

Student::Student(const string& code, const string& name) {
    this->code = code;
    this->name = name;
    shortExam = 0;
    project = 0;
    exam = 0;
    finalGrade = 0;
}

Student::Student(const string& code, const string& name, double shortExam, double project, double exam) {
    this->code = code;
    this->name = name;
    setGrades(shortExam, project, exam);
}

void Student::setGrades(double shortExam, double project, double exam) {
    this->shortExam = shortExam;
    this->project = project;
    this->exam = exam;
    double temp = ((weightShortExam * shortExam) + (weightProject * project) + (weightExam * exam)) / 100;
    if (temp - (int)temp > 0.49999999)
        temp += 0.6;
    finalGrade = (int)temp;
}

string Student::getCode() const {
    return code;
}

string Student::getName() const {
    return name;
}

int Student::getFinalGrade() const {
    return finalGrade;
}

bool Student::isApproved() const {
    if (finalGrade >= 10)
        return 1;
    return 0;
}

double getGradeAverage(vector<Student> vec) {
    double finalGradeAverage = 0;
    for (int i = 0; i < vec.size(); i++) {
        finalGradeAverage += vec[i].getFinalGrade();
    }
    finalGradeAverage /= vec.size();
    return finalGradeAverage;
}

void showAboveAverageStudents(ostream& stream, vector<Student> vec) {
    double finalGradeAverage = getGradeAverage(vec);
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].getFinalGrade() > finalGradeAverage) {
            stream << vec[i].getName() << " - " << vec[i].getCode() << " - " << vec[i].getFinalGrade() << endl;
        }
    }

}

Student readStudentData(istream& allstudents) {
    string code, name, shortExam, project, exam;
    getline(allstudents, code, ';');
    if (code == "")
        return Student();
    getline(allstudents, name, ';');
    getline(allstudents, shortExam, ';');
    getline(allstudents, project, ';');
    getline(allstudents, exam, ';');
    return Student(code, name, stod(shortExam), stod(project), stod(exam));
}

int main()
{
    ofstream file("file.txt");
    ifstream allstudents("6.2e.txt");
    vector<Student> stu_vec;
    while (allstudents.is_open()) {
        Student stu = readStudentData(allstudents);
        if (stu.getCode() == "")
            break;
        stu_vec.push_back(stu);
    }
    showAboveAverageStudents(file, stu_vec);
    return 0;
}


//Exercise 6.3)

