//Exercise 1.1

#include <iostream>

int main()
{
	char symbol;
	std::cout << "symbol ?" << std::endl;
	std::cin >> symbol;
	std::cout << (int)symbol << std::endl;
	return 0;
}


//Exercise 1.2

#include <iostream>

int main()
{
	int a, b, c;
	float mean, a_mean, b_mean, c_mean;
	std::cout << "Please, input 3 integer numbers" << std::endl;
	std::cin >> a >> b >> c;
	mean = (((float)a) + b + c) / 3;
	a_mean = a - mean;
	b_mean = b - mean;
	c_mean = c - mean;
	std::cout << mean << std::endl << a_mean << std::endl <<
		b_mean << std::endl << c_mean << std::endl;

	return 0;
}


//Exercise 1.3

#include <iostream> 

int main()
{
	float p, r, m, pi;
	pi = 3.1415926535;
	std::cout << "Please input the specific mass(p) of the material from which your sphere is made in kg/m^3: " << std::endl;
	std::cin >> p;
	std::cout << "Now, please input the radius(r) of your sphere in metres:" << std::endl;
	std::cin >> r;
	std::cout << "The mass(m) of your sphere in kg is:" << p * pi * pow(r, 3) << std::endl;
	return 0;
}


//Exercise 1.4

#include <iostream> 

int main()
{
	float a, b, c, d, e, f, x, y;
	std::cout << "Please input the values of a, b, c, d, e and f respectively for the system of linear equations : ax + by = c; dx + ey = f, to calculate its solution:" << std::endl;
	std::cin >> a >> b >> c >> d >> e >> f;
	if ((a * e) == (b * d))
		std::cout << "There is no solution to this system" << std::endl;
	else
	{
		x = (c * e - b * f) / (a * e - b * d);
		y = (a * f - c * d) / (a * e - b * d);
		if (x == y)
			std::cout << "x = y = " << x << std::endl;
		else
			std::cout << "x = " << x << " and y = " << y << std::endl;
	}
	return 0;
}


//Exercise 1.5
//a)

#include <iostream> 

int main()
{
	int h1, h2, m1, m2, s1, s2, h, m, s, d=0;
	std::cout << "Time1(hours minutes seconds) ?" << std::endl;
	std::cin >> h1 >> m1 >> s1;
	std::cout << "Time2(hours minutes seconds) ?" << std::endl;
	std::cin >> h2 >> m2 >> s2;
	s = s1 + s2;
	m = m1 + m2;
	h = h1 + h2;
	if (s >= 60) {
		s -= 60;
		m += 1;
	}
	if (m >= 60) {
		m -= 60;
		h += 1;
	}
	if (h >= 24) {
		h -= 24;
		d = 1;
	}
	std::cout << "Time1 + Time2 = ";
	if (d == 1)
		std::cout << d << " day ";
	if (h == 1)
		std::cout << h << " hour ";
	else
		std::cout << h << " hours ";
	if (m == 1)
		std::cout << m << " minute ";
	else
		std::cout << m << " minutes ";
	if (s == 1)
		std::cout << s << " second";
	else
		std::cout << s << " seconds";
	std::cout << std::endl;
	return 0;
}


//b)

#include <iostream> 

int main()
{
	int h1, h2, m1, m2, s1, s2, h, m, s, d = 0;
	std::cout << "Time1(hours minutes seconds) ?" << std::endl;
	std::cin >> h1 >> m1 >> s1;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();
		std::cin >> m1 >> s1;
	}
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();
		std::cin >> s1;
	}
	std::cout << "Time2(hours minutes seconds) ?" << std::endl;
	std::cin >> h2 >> m2 >> s2;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();
		std::cin >> m2 >> s2;
	}
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();
		std::cin >> s2;
	}
	s = s1 + s2;
	m = m1 + m2;
	h = h1 + h2;
	if (s >= 60) {
		s -= 60;
		m += 1;
	}
	if (m >= 60) {
		m -= 60;
		h += 1;
	}
	if (h >= 24) {
		h -= 24;
		d = 1;
	}
	std::cout << "Time1 + Time2 = ";
	if (d == 1)
		std::cout << d << " day ";
	if (h == 1)
		std::cout << h << " hour ";
	else
		std::cout << h << " hours ";
	if (m == 1)
		std::cout << m << " minute ";
	else
		std::cout << m << " minutes ";
	if (s == 1)
		std::cout << s << " second";
	else
		std::cout << s << " seconds";
	std::cout << std::endl;
	return 0;
}


//Exercise 1.6

#include <iostream> 

int main() {
	float x1, y1, x2, y2, x3, y3, a, b, c, s, area;
	std::cout << "Please input the coordinates of the first vertex of your triangle: " << std::endl;
	std::cin >> x1 >> y1;
	std::cout << "Please input the coordinates of the second vertex of your triangle: " << std::endl;
	std::cin >> x2 >> y2;
	std::cout << "Please input the coordinates of the third vertex of your triangle: " << std::endl;
	std::cin >> x3 >> y3;
	a = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	b = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
	c = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
	s = (a + b + c) / 2;
	area = sqrt(s * (s - a) * (s - b) * (s - c));
	std::cout << "Area of your triangle: " << area << std::endl;
	return 0;
}