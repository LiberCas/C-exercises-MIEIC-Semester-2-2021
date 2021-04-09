//Exercise 3.1

#include <iostream>
#include <cmath>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
	double s, a, b, c;
	a = distance(x1, y1, x2, y2);
	b = distance(x2, y2, x3, y3);
	c = distance(x3, y3, x1, y1);
	s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
	double x1, y1, x2, y2, x3, y3;
	cout << "Please input the coordinates of the first vertex of your triangle: " << endl;
	cin >> x1 >> y1;
	cout << "Please input the coordinates of the second vertex of your triangle: " << endl;
	cin >> x2 >> y2;
	cout << "Please input the coordinates of the third vertex of your triangle: " << endl;
	cin >> x3 >> y3;
	cout << "Area of your triangle: " << area(x1, y1, x2, y2, x3, y3) << endl;
	return 0;
}


//Exercise 3.2
//a)

#include <iostream> 
#include <cmath>
using namespace std;

int isPrime(int n) {
	int final = (int)sqrt(n), divisor=2;
	while (divisor <= final) {
		float temp;
		temp = ((float)n) / divisor;
		if (temp == (int)temp) {
			return 0;
		}
		divisor += 1;
	}
	return 1;
}

int main() {
	int n, prime;
	cout << "Please write in a whole number: " << endl;
	cin >> n;
	prime = isPrime(n);
	if (prime == 0)
		cout << "The number in question is not a prime\n";
	else
		cout << "The number in question is a prime\n";
	return 0;
}


//b)

#include <iostream> 
#include <cmath>
using namespace std;

int isPrime(int n) {
	int final = (int)sqrt(n), divisor = 2;
	while (divisor <= final) {
		float temp;
		temp = ((float)n) / divisor;
		if (temp == (int)temp) {
			return 0;
		}
		divisor += 1;
	}
	return 1;
}

int main() {
	int limit = 1000, num = 1;
	while (num < limit) {
		int prime;
		prime = isPrime(num);
		if (prime == 1)
			cout << num << " ";
		num += 1;
	}
	return 0;
}


//c)

#include <iostream> 
#include <cmath>
using namespace std;

int isPrime(int n) {
	int final = (int)sqrt(n), divisor = 2;
	while (divisor <= final) {
		float temp;
		temp = ((float)n) / divisor;
		if (temp == (int)temp) {
			return 0;
		}
		divisor += 1;
	}
	return 1;
}

int main() {
	int counter = 1, limit = 100, num = 1;
	while (counter <= limit) {
		int prime;
		prime = isPrime(num);
		if (prime == 1) {
			cout << num << " ";
			counter += 1;
		}
		num += 1;
	}
	return 0;
}


//d)
#include <iostream> 
#include <cmath>
using namespace std;

int isPrime(unsigned long n) {
	unsigned long final = (unsigned long)sqrt(n), divisor = 2;
	while (divisor <= final) {
		unsigned long temp;
		temp = n / divisor;
		if (temp * divisor == n) {
			return 0;
		}
		divisor += 1;
	}
	return 1;
}

int main() {
	unsigned long biggest = 4294967295, num;
	num = biggest;
	while (true) {
		int prime;
		prime = isPrime(num);
		if (prime == 1) {
			cout << num << endl;
			break;
		}
		else
			num -= 1;
	}
	return 0;
}


//Exercise 3.3
//a)

#include <iostream> 
#include <cmath>
using namespace std;

double sqroot(double n, double delta, double iter) {
	double estimate = 1;
	int estimate_not_1 = 0;
	while (true) {
		if ((iter == 0) || abs((estimate * estimate) - n) < delta)
			return estimate;
		else {
			estimate_not_1 = 1;
			iter -= 1;
			estimate = (estimate + (n / estimate)) / 2;
		}
	}
}

int main() {
	double n, delta, maxiter, estimate = 1;
	cout << "Please input the number(n) whose square root you would like to calculate: \n";
	cin >> n;
	cout << "Please input the maximum error(delta) between the estimate and the acctual square root of n: \n";
	cin >> delta;
	cout << "Please input the maximum number of iterations(maxiter) you would like to undertake: \n";
	cin >> maxiter;
	estimate = sqroot(n, delta, maxiter);
	cout << estimate << endl;
	return 0;
}


//b)

#include <iostream> 
#include <cmath>
using namespace std;

int precision(double number) {
	int size = 0;
	while (number != (int)number) {
		size += 1;
		number *= 10;
	}
	return size;
}

double sqroot(double n, double delta, double iter) {
	double estimate = 1;
	int estimate_not_1 = 0;
	while (true) {
		if ((iter == 0) || abs((estimate * estimate) - n) < delta)
			return estimate;
		else {
			estimate_not_1 = 1;
			iter -= 1;
			estimate = (estimate + (n / estimate)) / 2;
		}
	}
}

int main() {
	double n, delta, maxiter, estimate = 1, size_delta;
	cout << "Please input the number(n) whose square root you would like to calculate: \n";
	cin >> n;
	cout << "Please input the maximum error(delta) between the estimate and the acctual square root of n: \n";
	cin >> delta;
	cout << "Please input the maximum number of iterations(maxiter) you would like to undertake: \n";
	cin >> maxiter;
	estimate = sqroot(n, delta, maxiter);
	size_delta = pow(10, precision(delta));
	estimate = (round(estimate * size_delta) / size_delta);
	cout << "The square root of " << n << " as given by the sqrt() method is: " << sqrt(n) << endl;
	cout << "The square root of " << n << " as given by our algorithm is: " << estimate << endl;
	cout << "They differ by: " << abs(estimate - sqrt(n)) << endl;
	return 0;
}


//Exercise 3.4)

#include <iostream>
#include <cmath>
using namespace std;

double round(double x, unsigned n) {
	int power;
	power = pow(10, n);
	return floor(x * power + 0.5) / power;
}

int main() {
	double x;
	unsigned n;
	cout << "Please write the number(x) you'd like to round: \n";
	cin >> x;
	cout << "To how many decimal places(n) would you like to round x: \n";
	cin >> n;
	cout << "round(x, n) = " << round(x, n) << endl;
	return 0;
}


//Exercise 3.5)

#include <iostream>
using namespace std;

int gcd(int num1, int num2) {
	if (num1 == num2)
		return num1;
	else if (num1 == 0 || num2 == 0)
		return (num1 + num2);
	else if (num1 > num2)
		return gcd(num1 - num2, num2);
	else
		return gcd(num2 - num1, num1);
}

int main() {
	int num1, num2;
	cout << "Write two numbers with a space separating them: \n";
	cin >> num1 >> num2;
	cout << gcd(num1, num2);
	return 0;
}


//b)

#include <iostream>
using namespace std;

void gcd(int& num1, int& num2, int& result) {
	while (true) {
		if (num1 == num2) {
			result = num1;
			break;
		}
		else if (num1 == 0 || num2 == 0) {
			result = num1 + num2;
			break;
		}
		else if (num1 > num2)
			num1 -= num2;
		else
			num2 -= num1;
	}
}

int main() {
	int num1, num2, result = 0;
	cout << "Write two numbers with a space separating them: \n";
	cin >> num1 >> num2;
	gcd(num1, num2, result);
	cout << result;
	return 0;
}


//Exercise 3.6)

#include <iostream>
#include <cstdlib>
#include <ctime>
#include<windows.h>
using namespace std;

clock_t timeElapsed() {
	static clock_t begin = clock();
	return (clock() - begin) / CLK_TCK;
}

int main() {
	cout << timeElapsed() << endl;
	Sleep(3000);
	cout << timeElapsed() << endl;
	return 0;
}


//Exercise 3.7)

#include <iostream>
using namespace std;

bool readInt(int& x) {
	bool isvalid;
	int temp;
	char peek;
	cin >> temp;
	if (cin.fail()) {
		isvalid = false;
		cin.clear();
	}
	else {
		peek = cin.peek();
		if ((int)peek == 10) {
			isvalid = true;
		}
		else
			isvalid = false;
	}
	cin.ignore(1000, '\n');
	x = temp;
	return isvalid;
}

int main() {
	bool valid = false;
	int x = 0;
	valid = readInt(x);
	cout << valid << endl << x << endl;
	return 0;
}


//Exercise 3.8)
//a)

#include <iostream>
using namespace std;

bool readFraction(int& numerator, int& denominator) {
	bool isvalid = 0;
	char slash, peek;
	cin >> numerator >> slash;
	if (cin.fail()) {
		isvalid = 0;
		cin.clear();
	}
	else if ((int)slash != 47)
		isvalid = 0;
	else {
		cin >> denominator;
		if (cin.fail()) {
			isvalid = 0;
			cin.clear();
		}
		else {
			peek = cin.peek();
			if ((int)peek != 10)
				isvalid = 0;
			else
				isvalid = 1;
		}
	}
	cin.ignore(1000, '\n');
	return isvalid;
}

int main() {
	bool valid = 0;
	int num = 0, den = 0;
	valid = readFraction(num, den);
	cout << valid << endl;
	return 0;
}


//b)

#include <iostream>
using namespace std;

int gcd(int num1, int num2) {
	if (num1 == num2)
		return num1;
	else if (num1 == 0 || num2 == 0)
		return (num1 + num2);
	else if (num1 > num2)
		return gcd(num1 - num2, num2);
	else
		return gcd(num2 - num1, num1);
}

void reduceFraction(int& numerator, int& denominator) {
	int factor;
	factor = gcd(numerator, denominator);
	numerator /= factor;
	denominator /= factor;
}


bool readFraction(int& numerator, int& denominator) {
	bool isvalid = 0;
	char slash, peek;
	cin >> numerator >> slash;
	if (cin.fail()) {
		isvalid = 0;
		cin.clear();
	}
	else if ((int)slash != 47)
		isvalid = 0;
	else {
		cin >> denominator;
		if (cin.fail()) {
			isvalid = 0;
			cin.clear();
		}
		else {
			peek = cin.peek();
			if ((int)peek != 10)
				isvalid = 0;
			else
				isvalid = 1;
		}
	}
	cin.ignore(1000, '\n');
	return isvalid;
}

int main() {
	bool valid = 0;
	int num = 0, den = 0;
	valid = readFraction(num, den);
	cout << num << "/" << den << " = ";
	if (valid == 1)
		reduceFraction(num, den);
	cout << num << "/" << den << endl;
	return 0;
}


//c)

#include <iostream>
using namespace std;

void addition(int& num1, int& den1, int& num2, int& den2) {
	int temp = den1;
	num1 *= den2;
	den1 *= den2;
	num2 *= temp;
	den2 *= temp;
	num1 += num2;
}

void subtraction(int& num1, int& den1, int& num2, int& den2) {
	int temp = den1;
	num1 *= den2;
	den1 *= den2;
	num2 *= temp;
	den2 *= temp;
	num1 -= num2;
}

void multiplication(int& num1, int& den1, int& num2, int& den2) {
	num1 *= num2;
	den1 *= den2;
}

void division(int& num1, int& den1, int& num2, int& den2) {
	num1 *= den2;
	den1 *= num2;
}

int gcd(int num1, int num2) {
	if (num1 == num2)
		return num1;
	else if (num1 == 0 || num2 == 0)
		return (num1 + num2);
	else if (num1 > num2)
		return gcd(num1 - num2, num2);
	else
		return gcd(num2 - num1, num1);
}

void reduceFraction(int& numerator, int& denominator) {
	int factor;
	factor = gcd(numerator, denominator);
	numerator /= factor;
	denominator /= factor;
}


bool readFraction(int& numerator, int& denominator) {
	bool isvalid = 0;
	char slash, peek;
	cin >> numerator >> slash;
	if (cin.fail()) {
		isvalid = 0;
		cin.clear();
	}
	else if ((int)slash != 47)
		isvalid = 0;
	else {
		cin >> denominator;
		if (cin.fail()) {
			isvalid = 0;
			cin.clear();
		}
		else {
			peek = cin.peek();
			if ((int)peek != 10 && (int)peek != 32)
				isvalid = 0;
			else
				isvalid = 1;
		}
	}
	return isvalid;
}

int main() {
	char operation;
	bool valid1 = 0, valid2 = 0;
	int num1 = 0, den1 = 0, num2 = 0, den2 = 0;
	valid1 = readFraction(num1, den1);
	cin >> operation;
	valid2 = readFraction(num2, den2);
	if (valid1 != 1 || valid2 != 1)
		cout << "Error: fraction written in invalid format" << endl;
	else if (operation == '+')
		addition(num1, den1, num2, den2);
	else if (operation == '-')
		subtraction(num1, den1, num2, den2);
	else if (operation == 'x' || operation == '*')
		multiplication(num1, den1, num2, den2);
	else if (operation == '/')
		division(num1, den1, num2, den2);
	reduceFraction(num1, den1);
	cout << " = " << num1 << "/" << den1 << endl;
	return 0;
}


//Exercise 3.9)
//a)

#include <iostream>
using namespace std;

bool isLeap(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	else
		return false;
}

int main() {
	bool leap;
	int year;
	cout << "Please write a year: \n";
	cin >> year;
	leap = isLeap(year);
	if (leap == 1)
		cout << "It is a leap year\n";
	else
		cout << "It is not a leap year\n";
	return 0;
}


//b)

#include <iostream>
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

int main() {
	int year, month, days;
	cout << "Please write a month and a year: \n";
	cin >> month >> year;
	cout << daysInMonth(month, year) << endl;
	return 0;
}


//c)

#include <iostream>
using namespace std;

bool isLeap(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	else
		return false;
}

int dayOfTheWeek(int year, int month, int day) {
	int s = year / 100, a = year % 100, c;
	if (month == 1 || month == 2) {
		int leap = isLeap(year);
		if (leap == 1 && month == 1)
			c = 6;
		else if (leap == 1 && month == 2)
			c = 2;
		else if (leap == 0 && month == 1)
			c = 0;
		else if (leap == 0 && month == 2)
			c = 3;
	}
	else if (month == 10)
		c = 0;
	else if (month == 5)
		c = 1;
	else if (month == 8)
		c = 2;
	else if (month == 3 || month == 11)
		c = 3;
	else if (month == 6)
		c = 4;
	else if (month == 9 || month == 12)
		c = 5;
	else
		c = 6;
	return ((((int)(5 * a / 4)) + c + day + 7 - (2 * (s % 4))) % 7);
}

int main() {
	int year, month, day;
	cout << "Please write a date in the format \"year month day\": \n";
	cin >> year >> month >> day;
	cout << dayOfTheWeek(year, month, day) << endl;
	return 0;
}


//d)

#include <iostream>
#include <iomanip>
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

int dayOfTheWeek(int year, int month, int day) {
	int s = year / 100, a = year % 100, c;
	if (month == 1 || month == 2) {
		int leap = isLeap(year);
		if (leap == 1 && month == 1)
			c = 6;
		else if (leap == 1 && month == 2)
			c = 2;
		else if (leap == 0 && month == 1)
			c = 0;
		else if (leap == 0 && month == 2)
			c = 3;
	}
	else if (month == 10)
		c = 0;
	else if (month == 5)
		c = 1;
	else if (month == 8)
		c = 2;
	else if (month == 3 || month == 11)
		c = 3;
	else if (month == 6)
		c = 4;
	else if (month == 9 || month == 12)
		c = 5;
	else
		c = 6;
	return ((((int)(5 * a / 4)) + c + day + 7 - (2 * (s % 4))) % 7);
}

void showMonth(int year, int month) {
	int days_in_month = daysInMonth(month, year),
		first_day = dayOfTheWeek(year, month, 1), temp, day_num = 1;
	cout << "\n  " << setfill('0') << setw(2) << month << "/" << year << endl;
	cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
	//First line
	if (first_day == 0)
		first_day += 7;
	temp = first_day;
	while (temp != 1) {
		cout << "     ";
		temp--;
	}
	//Following lines
	temp = first_day;
	while (day_num <= days_in_month) {
		while (temp <= 7 && day_num <= days_in_month) {
			cout << setfill(' ') << setw(5) << day_num;
			day_num++;
			temp++;
		}
		cout << endl;
		temp = 1;
	}
}

int main() {
	int year, month;
	cout << "Please write a year and a month, respectively: \n";
	cin >> year >> month;
	showMonth(year, month);
	return 0;
}


//e)

#include <iostream>
#include <iomanip>
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

int dayOfTheWeek(int year, int month, int day) {
	int s = year / 100, a = year % 100, c;
	if (month == 1 || month == 2) {
		int leap = isLeap(year);
		if (leap == 1 && month == 1)
			c = 6;
		else if (leap == 1 && month == 2)
			c = 2;
		else if (leap == 0 && month == 1)
			c = 0;
		else if (leap == 0 && month == 2)
			c = 3;
	}
	else if (month == 10)
		c = 0;
	else if (month == 5)
		c = 1;
	else if (month == 8)
		c = 2;
	else if (month == 3 || month == 11)
		c = 3;
	else if (month == 6)
		c = 4;
	else if (month == 9 || month == 12)
		c = 5;
	else
		c = 6;
	return ((((int)(5 * a / 4)) + c + day + 7 - (2 * (s % 4))) % 7);
}

void showMonth(int year, int month) {
	int days_in_month = daysInMonth(month, year),
		first_day = dayOfTheWeek(year, month, 1), temp, day_num = 1;
	cout << "\n  " << setfill('0') << setw(2) << month << "/" << year << endl;
	cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
	//First line
	if (first_day == 0)
		first_day += 7;
	temp = first_day;
	while (temp != 1) {
		cout << "     ";
		temp--;
	}
	//Following lines
	temp = first_day;
	while (day_num <= days_in_month) {
		while (temp <= 7 && day_num <= days_in_month) {
			cout << setfill(' ') << setw(5) << day_num;
			day_num++;
			temp++;
		}
		cout << endl;
		temp = 1;
	}
}

void showYear(int year) {
	for (int month = 1; month <= 12; month++)
		showMonth(year, month);
}


int main() {
	int year;
	cout << "Please write a year: \n";
	cin >> year;
	showYear(year);
	return 0;
}


//3.10)
//a)

#include <iostream>
#include <climits>
using namespace std;

unsigned int biggest_fac(unsigned long long limit) {
	unsigned int answer = 1;
	while (limit >= answer + 1) {
		answer++;
		limit /= answer;
	}
	return answer;
}

unsigned long long factorial_ite(unsigned int n) {
	unsigned int limit_fac = biggest_fac(ULLONG_MAX), next_mult = 2;
	unsigned long long n_fac = 1;
	if (n > limit_fac) {
		cout << "Error: Cannot calculate factorials larger than " << limit_fac << "!\n";
		n_fac = 0;
	}
	else {
		while (next_mult <= n) {
			n_fac *= next_mult;
			next_mult++;
		}
	}
	return n_fac;

}

int main() {
	int n;
	unsigned long long n_fac;
	cout << "Please write in a number to calculate its factorial: " << endl;
	cin >> n;
	n_fac = factorial_ite(n);
	if (n_fac != 0)
		cout << n << "! = " << n_fac << endl;
	return 0;
}


//b)

#include <iostream>
#include <climits>
using namespace std;

unsigned int biggest_fac(unsigned long long limit) {
	unsigned int answer = 1;
	while (limit >= answer + 1) {
		answer++;
		limit /= answer;
	}
	return answer;
}

unsigned long long do_fac_rec(unsigned int n, unsigned int next_mult) {
	if (next_mult >= n)
		return next_mult;
	else
		return next_mult * do_fac_rec(n, next_mult + 1);
}


unsigned long long factorial_rec(unsigned int n) {
	unsigned int limit_fac = biggest_fac(ULLONG_MAX), next_mult = 1;
	if (n > limit_fac) {
		cout << "Error: Cannot calculate factorials larger than " << limit_fac << "!\n";
		return 0;
	}
	else
		return do_fac_rec(n, next_mult);
}

int main() {
	int n;
	unsigned long long n_fac;
	cout << "Please write in a number to calculate its factorial: " << endl;
	cin >> n;
	n_fac = factorial_rec(n);
	if (n_fac != 0)
		cout << n << "! = " << n_fac << endl;
	return 0;
}


//Exercise 3.11)

#include <iostream>
using namespace std;

int gcd_rec(int m, int n) {
	if (n > m) {
		int temp = n;
		n = m;
		m = temp;
	}
	if (m % n == 0)
		return n;
	else
		return gcd_rec(n, m % n);
}

int main() {
	int m, n;
	cout << "Please write two numbers in the format(m n): " << endl;
	cin >> m >> n;
	cout << "GCD(" << m << ", " << n << ") = " << gcd_rec(m, n);
	return 0;
}


//Exercise 3.12)

#include <iostream>
#include <cmath>
using namespace std;

double PI = 3.1415;

double distance(double x1, double y1, double x2, double y2) {
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
	double s, a, b, c;
	a = distance(x1, y1, x2, y2);
	b = distance(x2, y2, x3, y3);
	c = distance(x3, y3, x1, y1);
	s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

double area(double radius) {
	return (PI * pow(radius, 2));
}

double area(double x1, double y1, double x2, double y2) {
	return abs((x1 - x2) * (y1 - y2));
}

int main() {
	double area_of_shape;
	int selection;
	cout << "Which do you want to calculate? \n1) The area of a circle\n2) The area of a rectangle whose vertices are parallel to the x and y axes\n3) The area of a triangle\n\nPlease input 1, 2 or 3 to select circle, rectangle or triangle respectively:\n";
	cin >> selection;
	switch (selection) {
	case 1:
		double radius;
		cout << "Please input the radius of the circle:\n";
		cin >> radius;
		area_of_shape = area(radius);
		break;
	case 2:
		double x1r, y1r, x2r, y2r;
		cout << "Please input the coordinates of two opposite vertices of the rectangle in the format(x1 y1 x2 y2):\n";
		cin >> x1r >> y1r >> x2r >> y2r;
		area_of_shape = area(x1r, y1r, x2r, y2r);
		break;
	case 3:
		double x1, y1, x2, y2, x3, y3;
		cout << "Pleasse input the coordinates of the three vertices of the triangle in the format(x1 y1 x2 y2 x3 y3):\n";
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		area_of_shape = area(x1, y1, x2, y2, x3, y3);
		break;
	}
	cout << "The area of the shape is: " << area_of_shape << endl;
	return 0;
}


//Exercise 3.13)
/*a)The function outputs a single randomly generated value between 
"low" and "high". The assert() statement makes sure that "high" is more than 
or equal to "low", if that is not the case, an exception is thrown*/

/*b)The function can recieve no parameters, having the signature "rollDie()"
, a single parameter of type "int", having the signature "rollDie(int limit)"
, or two parameters of type "int", having the signature "rollDie(int low, int high)"*/

/*c)No it isn't. Becasue the signature of the function "int rollDie()"
is the same as one of the possible  signatures of the original function*/


//Exercise 3.14)

#include <iostream>
#include <cmath>
using namespace std;

double integrateTR(double f(double), double a, double b, int n) {
	double h = (b - a) / n, integral = 0;
	for (int i = 1; i <= n; i++)
		integral += (h / 2) * (f(a + (i - 1) * h) + f(a + (i * h)));
	return integral;
}

double g(double x) {
	return pow(x, 2);
}

double h(double x) {
	return sqrt(4 - pow(x, 2));
}

int main() {
	int ag = 0, bg = 10, ah = -2, bh = 2, n;
	cout << "Please input the number of partitions(n) for the integrals of g(x) and h(x):\n";
	cin >> n;
	cout << "Approximation of the integral of g(x) in " << n << " partitions = " << integrateTR(g, ag, bg, n) << endl;
	cout << "\nApproximation of the integral of h(x) in " << n << " partitions = " << integrateTR(h, ah, bh, n) << endl;
	return 0;
}
