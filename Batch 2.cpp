//Exercise 2.1

#include <iostream> 
using namespace std;

int main()
{
	float a, b, c, d, e, f, x, y;
	cout << "Please input the values of a, b, c, d, e and f respectively for the system of linear equations : ax + by = c; dx + ey = f, to calculate its solution:" << endl;
	cin >> a >> b >> c >> d >> e >> f;
	if ((a * e) == (b * d))
		cout << "There are infinite solutions to this system" << endl;
	else
	{
		x = (c * e - b * f) / (a * e - b * d);
		y = (a * f - c * d) / (a * e - b * d);
		if (x == y)
			cout << "x = y = " << x << endl;
		else
			cout << "x = " << x << " and y = " << y << endl;
	}
	return 0;
}


//Exercise 2.2
//a)

#include <iostream> 
using namespace std;

int main() {
	float a, b, c, greatest, smallest;
	cout << "Please insert 3 numbers: " << endl;
	cin >> a >> b >> c;
	//check for the smallest
	if (a <= b && a <= c)
		smallest = a;
	else if (b <= a && b <= c)
		smallest = b;
	else if (c <= a && c <= b)
		smallest = c;
	//check for the greatest
	if (a >= b && a >= c)
		greatest = a;
	else if (b >= a && b >= c)
		greatest = b;
	else if (c >= a && c >= b)
		greatest = c;
	cout << "The smallest number is " << smallest << " and the greatest number is " << greatest << endl;
	return 0;
}


//b)

#include <iostream> 
using namespace std;

int main() {
	float a, b, c, greatest, smallest, middle;
	char op1 = '<', op2 = '<';
	cout << "Please insert 3 numbers: " << endl;
	cin >> a >> b >> c;
	if (a <= b && a <= c) {
		smallest = a;
		if (b >= c) {
			greatest = b;
			middle = c;
		}
		else if (b <= c) {
			greatest = c;
			middle = b;
		}
	}
	else if (b <= a && b <= c) {
		smallest = b;
		if (a >= c) {
			greatest = a;
			middle = c;
		}
		else if (a <= c) {
			greatest = c;
			middle = a;
		}
	}
	else if (c <= a && c <= b) {
		smallest = c;
		if (b >= a) {
			greatest = b;
			middle = a;
		}
		else if (b <= a) {
			greatest = a;
			middle = b;
		}
	}
	if (smallest == middle)
		op1 = '=';
	else if (greatest == middle)
		op2 = '=';
	cout << "The numbers are, in order: " << smallest << " " << op1 << " " << middle << " " << op2 << " " << greatest << endl;
	return 0;
}


//c)

#include <iostream> 
using namespace std;

int main() {
	float a, b, c, trig = 1;
	cout << "Please insert 3 numbers: " << endl;
	cin >> a >> b >> c;
	if ((a <= 0) || (b <= 0) || (c <= 0)) {
		cout << "Error, negative numbers have been inserted" << endl;
		return 0;
	}
	if (a >= b && a >= c) {
		if (a >= (b + c))
			trig = 0;
	}
	else if (b >= a && b >= c) {
		if (b >= (a + c))
			trig = 0;
	}
	else if (c >= b && c >= a) {
		if (c >= (b + a))
			trig = 0;
	}
	if (trig == 0)
		cout << "This combination of side lengths is not compatible with a triangle" << endl;
	else
		cout << "This combination of side lengths is compatible with a triangle" << endl;
	return 0;
}


//Exercise 2.3

#include <iostream> 
using namespace std;

int main() {
	int num1, num2;
	cout << "2 ints: \n";
	cin >> num1 >> num2;
	if (num2 > 0) {
		if (num1 > INT_MAX - num2)
			cout << "Error: Sum larger than INT_MAX" << endl;
		else
			cout << "Sum: " << num1 + num2 << endl;
	}
	else if (num2 < 0) {
		if (num1 < INT_MIN - num2)
			cout << "Error: Sum smaller than INT_MIN" << endl;
		else
			cout << "Sum: " << num1 + num2 << endl;
	}
	return 0;
}

//Exercise 2.4

#include <iostream> 
using namespace std;

int main() {
	float weight, cost = 5;
	cout << "What is the weight of your merchandise(in grams): " << endl;
	cin >> weight;
	if (weight > 500 && weight <= 1000) {
		while (weight > 500) {
			weight -= 100;
			cost += 1.5;
		}
	}
	else if (weight > 1000) {
		cost = 12.5;
		while (weight > 1000) {
			weight -= 250;
			cost += 5;
		}
	}
	cout << "Cost of transportation: " << cost << endl;
	return 0;
}


//Exercise 2.5

#include <iostream> 
using namespace std;

int main() {
	float a, b, c, disc;
	cout << "Solution of Ax ^ 2 + Bx + C = 0\nInsert the coefficients(A B C) : \n";
	cin >> a >> b >> c;
	disc = (b * b) - (4 * a * c);
	if (disc == 0)
		cout << "The system has got a single root, the point where x = " << -(b / (2 * a)) << endl;
	else if (disc < 0)
		cout << "The system has got two complex roots, the points where x = " << -(b / (2 * a)) << " + " << sqrt(-disc) / (2 * a) << "i and of x = " << -(b / (2 * a)) << " - " << sqrt(-disc) / (2 * a) << "i" << endl;
	else if (disc > 0)
		cout << "The system has got two real roots, the points where x = " << (-b + sqrt(disc)) / (2 * a) << " and of x = " << (-b - sqrt(disc)) / (2 * a) << endl;
	return 0;
}


//Exercise 2.6

#include <iostream> 
#include <cmath>
using namespace std;

int main() {
	float n, q, j;
	cout << "Please input n, q and j respectively that correspont to the variables in the problem: \"If you deposit <<q>> money in a bank with an anual interest rate of <<j>>%, how much money will you have in total after <<n>> years\": " << endl;
	cin >> n >> q >> j;
	cout << "The total amount accumulated over " << n << " years is: " << q * pow((1 + (j / 100)), n) << endl;
	return 0;
}


//Exercise 2.7
//a)

#include <iostream> 
#include <cmath>
using namespace std;

int main() {
	int n, prime = 1, final, divisor = 2;
	cout << "Please write in a whole number: " << endl;
	cin >> n;
	final = (int)sqrt(n);
	while (divisor <= final) {
		float temp;
		temp = ((float)n) / divisor;
		if (temp == (int)temp) {
			prime = 0;
			break;
		}
		divisor += 1;
	}
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

int main() {
	int limit = 1000, num = 1;
	while (num < limit) {
		int final, divisor = 2, prime = 1;
		final = (int)sqrt(num);
		while (divisor <= final) {
			float temp;
			temp = ((float)num) / divisor;
			if (temp == (int)temp) {
				prime = 0;
				break;
			}
			divisor += 1;
		}
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

int main() {
	int counter = 1, limit = 100, num = 1;
	while (counter <= limit) {
		int final, divisor = 2, prime = 1;
		final = (int)sqrt(num);
		while (divisor <= final) {
			float temp;
			temp = ((float)num) / divisor;
			if (temp == (int)temp) {
				prime = 0;
				break;
			}
			divisor += 1;
		}
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

int main() {
	unsigned long num = 4294967295;
	while (true) {
		unsigned long divisor;
		divisor = (int)sqrt(num);
		while (divisor > 1) {
			double temp;
			temp = ((double)num) / divisor;
			if (temp == (int)temp)
				break;
			divisor -= 1;
		}
		if (divisor == 1) {
			cout << num << endl;
			return 0;
		}
		num -= 1;
	}
	return 0;
}


//Exercise 2.8
//a)

#include <iostream> 
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	float angle = 0, pi = 3.1415;
	cout << "ang       sin       cos       tan\n";
	while (angle < 90) {
		cout << setfill(' ') << setw(2) << angle << setw(10) << sin(angle * pi / 180) << setw(10) << cos(angle * pi / 180) << setw(10) << tan(angle * pi / 180) << endl;
		angle += 15;
	}
	cout << setfill(' ') << setw(2) << angle << setw(10) << 1 << setw(10) << 0 << setw(10) << "infinite" << endl;
	return 0;
}


//b)

#include <iostream> 
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	double lower, angle, upper, increment, pi = 3.14159265;
	cout << "Please type in the lower bound of your range(in degrees): \n";
	cin >> lower;
	angle = lower;
	cout << "Please type in the upper bound of your range: \n";
	cin >> upper;
	cout << "Please type in the increment: \n";
	cin >> increment;
	cout << "\nang         sin         cos         tan\n";
	while (lower <= upper) {
		while (angle >= 360)
			angle -= 360;
		if (angle == 0)
			cout << setfill(' ') << setw(3) << lower << setw(12) << 0 << setw(12) << 1 << setw(12) << 0 << endl;
		else if (angle == 90)
			cout << setfill(' ') << setw(3) << lower << setw(12) << 1 << setw(12) << 0 << setw(12) << "infinite" << endl;
		else if (angle == 180)
			cout << setfill(' ') << setw(3) << lower << setw(12) << 0 << setw(12) << -1 << setw(12) << 0 << endl;
		else if (angle == 270)
			cout << setfill(' ') << setw(3) << lower << setw(12) << -1 << setw(12) << 0 << setw(12) << "infinite" << endl;
		else
			cout << setfill(' ') << setw(3) << lower << setw(12) << sin(angle * pi / 180) << setw(12) << cos(angle * pi / 180) << setw(12) << tan(angle * pi / 180) << endl;
		angle += increment;
		lower += increment;
	}
	return 0;
}


//Exercise 2.9
//a)

#include <iostream> 
using namespace std;

int main() {
	int num;
	cout << "Write a 3 number integer: \n";
	cin >> num;
	if (((int)num / 100) == (num % 10))
		cout << "Your number is a palindrome\n";
	else
		cout << "Your number is not a palindrome\n";
	return 0;
}


//b)

#include <iostream> 
using namespace std;

unsigned int getsize(unsigned int number) {
	unsigned int var = 1;
	while (number > var)
		var *= 10;
	var /= 10;
	return var;
}

int main() {
	unsigned int num, divisor, palindrome = 1;
	cout << "Write an unsigned integer: \n";
	cin >> num;
	while (num >= 10) {
		divisor = getsize(num);
		if ((unsigned int)(num / divisor) != (num % 10)) {
			palindrome = 0;
			break;
		}
		else
			num = (unsigned int)((num % divisor) / 10);
	}
	if (palindrome == 1)
		cout << "Your number is a palindrome\n";
	else
		cout << "Your number is not a palindrome\n";
	return 0;
}


//Exercise 2.10

#include <iostream> 
#include <cmath>
using namespace std;

int prime(int n) {
	int prime = 1, final, divisor = 2;
	final = (int)sqrt(n);
	while (divisor <= final) {
		float temp;
		temp = ((float)n) / divisor;
		if (temp == (int)temp) {
			prime = 0;
			break;
		}
		divisor += 1;
	}
	return prime;
}

int main() {
	int num, start = 2, end;
	cout << "Please write a number to factor: \n";
	cin >> num;
	end = (int)(sqrt(num));
	if (num == 1) {
		cout << 1;
		return 0;
	}
	while (num > 1) {
		while ((prime(start) == 1) && ((float)num / start == (int)num / start)) {
			num /= start;
			if (num > 1)
				cout << start << " x ";
			else
				cout << start << endl;
		}
		start += 1;

	}
	return 0;
}


//Exercise 2.11
//a)

#include <iostream>
using namespace std;

float pi(float n, float factor) {
	float piapp, nextfactor;
	if (n == 1) {
		piapp = 4 / factor;
	}
	else {
		nextfactor = factor + 2;
		piapp = 4 / factor - pi(n - 1, nextfactor);
	}
	return piapp;
}

int main() {
	float n, approx;
	cout << "Enter n: \n";
	cin >> n;
	approx = pi(n, 1);
	cout << approx << endl;
	return 0;
}


//b)

#include <iostream>
using namespace std;

float e(float n, float linear, float factorial) {
	float eapp;
	if (n == 0) {
		eapp = 1;
	}
	else {
		factorial *= linear;
		linear += 1;
		eapp = 1 / factorial + e(n - 1, linear, factorial);
	}
	return eapp;
}

int main() {
	float n, approx;
	cout << "Enter n: \n";
	cin >> n;
	approx = e(n, 1, 1);
	cout << approx << endl;
	return 0;
}


//c)

#include <iostream>
#include <cmath>
using namespace std;

float eminx(float n, float linear, float factorial, float x) {
	float eapp;
	if (n == 0) {
		eapp = pow(-1, linear);
	}
	else {
		linear += 1;
		factorial *= linear;
		cout << -pow(x, linear) / factorial << endl;
		eapp = -pow(x, linear) / factorial - eminx(n - 1, linear, factorial, x);
	}
	return eapp;
}

int main() {
	float n, approx, x;
	cout << "Enter n: \n";
	cin >> n;
	cout << "Enter x: \n";
	cin >> x;
	approx = eminx(n - 1, 0, 1, x);
	cout << approx << endl;
	return 0;
}


//Exercise 2.12


//Exercise 2.13


//Exercise 2.14
//a)


#include <iostream>
using namespace std;

float sqroot(float n, float delta, float iter, float estimate, int estimate_not_1) {
	if ((iter == 0) || (((estimate * estimate) - n) < delta && estimate_not_1 == 1))
		return estimate;
	else {
		estimate_not_1 = 1;
		iter -= 1;
		estimate = (estimate + (n / estimate)) / 2;
		return sqroot(n, delta, iter, estimate, 1);
	}
}

int main() {
	float n, delta, maxiter, estimate = 1;
	cout << "Please input the number(n) whose square root you would like to claculate: \n";
	cin >> n;
	cout << "Please input the maximum error(delta) between the estimate and the acctual square root of n: \n";
	cin >> delta;
	cout << "Please input the maximum number of iterations(maxiter) you would like to undertake: \n";
	cin >> maxiter;
	estimate = sqroot(n, delta, maxiter, estimate, 0);
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
double sqroot(double n, double delta, double iter, double estimate, int estimate_not_1) {
	if ((iter == 0) || (((estimate * estimate) - n) < delta && estimate_not_1 == 1))
		return estimate;
	else {
		estimate_not_1 = 1;
		iter -= 1;
		estimate = (estimate + (n / estimate)) / 2;
		return sqroot(n, delta, iter, estimate, 1);
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
	estimate = sqroot(n, delta, maxiter, estimate, 0);
	size_delta = pow(10, precision(delta));
	estimate = (round(estimate * size_delta) / size_delta);
	cout << "The square root of " << n << " as given by the sqrt() method is: " << sqrt(n) << endl;
	cout << "The square root of " << n << " as given by our algorithm is: " << estimate << endl;
	cout << "They differ by: " << abs(estimate - sqrt(n)) << endl;
	return 0;
}


//Exercise 2.15

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	double time_spent;
	int num1, num2, answer, LOWER = 2, UPPER = 9;
	srand((unsigned)time(NULL));
	num1 = LOWER + (rand() % (UPPER - LOWER + 1));
	num2 = LOWER + (rand() % (UPPER - LOWER + 1));
	clock_t begin = clock();
	cout << "What's " << num1 << " x " << num2 << " ?" << endl;
	cin >> answer;
	clock_t end = clock();
	time_spent = (double)(end - begin) / CLK_TCK;
	if (answer != num1 * num2)
		cout << "Very Bad\n";
	else if (time_spent < 5)
		cout << "Good\n";
	else if (time_spent <= 10)
		cout << "Satisfactory\n";
	else
		cout << "Insufficient\n";
	return 0;
}


//Exercise 2.16

#include <iostream>
#include <string>

using namespace std;

int main() {
	int exit = 0;
	double num1, num2, result, mem = 0;
	char op;
	string input;
	while (exit == 0) {
		printf("Please input an operation in the format(number operation number): \n");
		cin >> input;
		if (input == "M" || input == "m")
			mem = result;
		else if (input == "M+" || input == "m+")
			mem += result;
		else if (input == "M-" || input == "m-")
			mem -= result;
		else if (input == "MC" || input == "mc")
			mem = 0;
		else if (input == "MR" || input == "mr")
			cout << mem << endl;
		else if (input == "E" || input == "e")
			exit = 1;
		else if (input == "C" || input == "c")
			cout << string(100, '\n');
		else {
			num1 = stod(input);
			cin >> op;
			cin >> num2;
			switch (op) {
			case '+':
				result = (num1 + num2);
				break;
			case '-':
				result = (num1 - num2);
				break;
			case '*': case'x':
				result = (num1 * num2);
				break;
			case '/':
				result = (num1 / num2);
				break;
			}
			cout << result << endl;
		}
	}
	return 0;
}