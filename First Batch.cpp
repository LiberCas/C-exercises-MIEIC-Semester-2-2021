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

