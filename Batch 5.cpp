//Exercise 5.1)
//a)

#include <iostream>
using namespace std;

char encryptChar(char c, int key) {
	int code = (int)toupper(c) + key;
	if (code > 90)
		key -= 26;
	else if (code < 65)
		key += 26;
	return (char)((int)c + key);
}

int main() {
	char letter;
	int key;
	cout << "What letter would you like to encrypt?\n";
	cin >> letter;
	cout << "What is the key to your Caesar cipher?\n";
	cin >> key;
	cout << encryptChar(letter, key);
	return 0;
}


//b)

#include <iostream>
#include <string>
using namespace std;

char encryptChar(char c, int key) {
	if ((int)c == 32)
		return c;
	int code = (int)toupper(c) + key;
	if (code > 90)
		key -= 26;
	else if (code < 65)
		key += 26;
	return (char)((int)c + key);
}

string encryptString(string s, int key) {
	string encrypted = {};
	for (int i = 0; i < s.size(); i++) {
		char temp = encryptChar(s[i], key);
		encrypted.push_back(temp);
	}
	return encrypted;
}

int main() {
	string str, answer;
	int key;
	cout << "What string would you like to encrypt?\n";
	getline(cin, str);
	cout << "What is the key to your Caesar cipher?\n";
	cin >> key;
	cout << encryptString(str, key);
	return 0;
}


//Exercise 5.2)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool ascending(int x, int y) {
	cout << "x: " << (char)x << " - ascii: " << x << "\n" << "y: " << (char)y << " - ascii: " << y << endl;
	if (y >= x)
		return true;
	else
		return false;
}

bool descending(int x, int y) {
	if (y <= x)
		return true;
	else
		return false;
}

void bubbleSort(vector<string>& v, bool f(int x, int y)) {
	for (int upper_index = v.size() - 1; upper_index > 0; upper_index--) {
		int swap_num = 0;
		for (int i = 0; i < upper_index; i++) {
			int size = v[i].size();
			if (v[i + 1].size() < size)
				size = v[i + 1].size();
			bool same = 1;
			for (int j = 0; j < size - 1; j++) {
				cout << v[i][j] << " , " << v[i + 1][j] << endl;
				if (toupper(v[i][j]) == toupper(v[i + 1][j]));
				else {
					if (!f((int)toupper(v[i][j]), (int)toupper(v[i + 1][j]))) {
						string temp = v[i];
						v[i] = v[i + 1];
						v[i + 1] = temp;
						swap_num++;
					}
					same = 0;
					break;
				}
			}
			if (same == 1) {
				if (v[i].size() == v[i + 1].size());
				else if (!f(v[i].size(), v[i + 1].size())) {
					cout << "Hello\n";
					string temp = v[i];
					v[i] = v[i + 1];
					v[i + 1] = temp;
					swap_num++;
				}
			}
		}
		if (swap_num == 0) {
			break;
		}
	}
}

int main() {
	char da;
	int i = 0, size;
	cout << "Please input the size of your vector:\n";
	cin >> size;
	cin.ignore(1000, '\n');
	vector<string> v(size);
	for (int j = 0; j < size; j++) {
		cout << "Please input the element of index " << j << " of your vector:\n";
		getline(cin, v[j]);
	}
	cout << "How would you like to sort your vector? (d for descending order/a for ascending order):\n";
	cin >> da;
	if (da == 'a')
		bubbleSort(v, ascending);
	else
		bubbleSort(v, descending);
	cout << "Here's the sorted vector: ";
	while (i < v.size() - 1) {
		cout << v.at(i) << " , ";
		i++;
	}
	cout << v.at(i);
	return 0;
}


//Exercise 5.3)

#include <iostream>
using namespace std;


int compare(const void* a, const void* b) {
	char* pointer_to_a;
	char* pointer_to_b;
	pointer_to_a = (char*)a;
	pointer_to_b = (char*)b;
	cout << pointer_to_a[0] << endl;
	for (int i = 0; i != '\0'; i++) {
		char letter_a = pointer_to_a[i];
		char letter_b = pointer_to_b[i];
		cout << "Comparing: " << letter_a << " to " << letter_b << endl;
		if (toupper(letter_a) == toupper(letter_b));
		else
			return ((int)toupper(letter_a) - (int)toupper(letter_b));
	}
	return 0;
}


int main()
{
	int nElem, n_char_per_string;
	cout << "Please input the number of elements in your array:\n";
	cin >> nElem;
	cout << "Please input the size of an element of your array in bytes:\n";
	cin >> n_char_per_string;
	cin.ignore(1000, '\n');
	char** char_pointer_array;
	char_pointer_array = (char**)malloc(nElem * sizeof(char*));
	for (int i = 0; i < nElem; i++) {
		char_pointer_array[i] = (char*)malloc((n_char_per_string + 1) * sizeof(char));
		cout << "Please input the element of index " << i << " of your array:(Max: " << n_char_per_string << " chars)\n";
		cin.getline(char_pointer_array[i], n_char_per_string, '\n');
	}
	qsort(char_pointer_array, nElem, sizeof(char*), compare);
	for (int i = 0; i < nElem; i++) {
		for (int j = 0; j < n_char_per_string; j++)
			cout << char_pointer_array[i][j];
		cout << endl;
	}
	return 0;
}


//Exercise 5.4)
//a)

#include <iostream>
#include <string>
using namespace std;

bool sequenceSearch(const string& s, int nc, char c) {
	int index = 0;
	while (index < s.size()) {
		if (s[index] == c && s[index - 1] != c) {
			int num = 1;
			for (int i = 1; i < nc; i++) {
				if (s[i + index] == c)
					num++;
			}
			if (num == nc)
				return 1;
		}
		index++;
	}
	return 0;
}

int main()
{
	string s = "abcddeedddf";
	int n = 3;
	char c = 'd';
	bool res = sequenceSearch(s, n, c);
	cout << res << endl;
	return 0;
}


//b)

#include <iostream>
#include <string>
using namespace std;

bool sequenceSearch(const string& s, int nc, char c) {
	string st(nc, c);
	if (s.find(st) == string::npos)
		return 0;
	else
		return 1;
}

int main()
{
	string s = "abcddeedddf";
	int n = 3;
	char c = 'd';
	bool res = sequenceSearch(s, n, c);
	cout << res << endl;
	return 0;
}


//Exercise 5.5)

#include <iostream>
#include <string>
using namespace std;

void remElIndex(string& ret, int index) {
	for (int j = index; j < ret.length() - 1; j++)
		ret[j] = ret[j + 1];
	ret.pop_back();
}

string remPart(const string& name) {
	string ret = name;
	while (ret.find(" E ") != string::npos) {
		int i = ret.find(" E ");
		remElIndex(ret, i);
		remElIndex(ret, i);
	}
	while (ret.find(" DE ") != string::npos) {
		int i = ret.find(" DE ");
		remElIndex(ret, i);
		remElIndex(ret, i);
		remElIndex(ret, i);
	}
	while (ret.find(" DA ") != string::npos) {
		int i = ret.find(" DA ");
		remElIndex(ret, i);
		remElIndex(ret, i);
		remElIndex(ret, i);
	}
	while (ret.find(" DO ") != string::npos) {
		int i = ret.find(" DO ");
		remElIndex(ret, i);
		remElIndex(ret, i);
		remElIndex(ret, i);
	}
	while (ret.find(" DOS ") != string::npos) {
		int i = ret.find(" DOS ");
		remElIndex(ret, i);
		remElIndex(ret, i);
		remElIndex(ret, i);
		remElIndex(ret, i);
	}
	while (ret.find(" DAS ") != string::npos) {
		int i = ret.find(" DAS ");
		remElIndex(ret, i);
		remElIndex(ret, i);
		remElIndex(ret, i);
		remElIndex(ret, i);
	}
	return ret;
}

string upp(const string& name) {
	string ret = name;
	for (int i = 0; i < ret.length(); i++)
		ret[i] = toupper(ret[i]);
	return ret;
}

string removeDSpaces(const string& name) {
	string ret = name;
	int i = 0;
	while (i < ret.length()) {
		if (ret[i] == ' ' && ret[i + 1] == ' ') {
			remElIndex(ret, i);
		}
		else
			i++;
	}
	return ret;
}

string removeIFSpaces(const string& name) {
	int i = 0;
	while (name[i] == ' ')
		i++;
	string ret(name.length() - i, ' ');
	for (int j = i; j < name.length(); j++) {
		ret[j - i] = name[j];
	}
	while (ret[ret.length() - 1] == ' ')
		ret.pop_back();
	return ret;
}

string normalizeName(const string& name) {
	string ret;
	ret = removeIFSpaces(name);
	ret = upp(ret);
	ret = remPart(ret);
	ret = removeDSpaces(ret);
	return ret;
}

int main()
{
	string name = "      Maria da Felicidade     dos Reis     e Passos    Dias de Aguiar ";
	string normal = normalizeName(name);
	for (int i = 0; i < normal.length(); i++)
		cout << normal[i];
	cout << endl;
	return 0;
}


//Exercise 5.6)

#include <iostream>
using namespace std;

struct Fraction {
	int numerator;
	int denominator;
};

void addition(Fraction& num1, Fraction& num2) {
	int temp = num1.denominator;
	num1.numerator *= num2.denominator;
	num1.denominator *= num2.denominator;
	num2.numerator *= temp;
	num2.denominator *= temp;
	num1.numerator += num2.numerator;
}

void subtraction(Fraction& num1, Fraction& num2) {
	int temp = num1.denominator;
	num1.numerator *= num2.denominator;
	num1.denominator *= num2.denominator;
	num2.numerator *= temp;
	num2.denominator *= temp;
	num1.numerator -= num2.numerator;
}

void multiplication(Fraction& num1, Fraction& num2) {
	num1.numerator *= num2.numerator;
	num1.denominator *= num2.denominator;
}

void division(Fraction& num1, Fraction& num2) {
	num1.numerator *= num1.denominator;
	num1.denominator *= num2.numerator;
}

int gcd(int num, int den) {
	if (num == den)
		return num;
	else if (num == 0 || den == 0)
		return (num + den);
	else if (num > den)
		return gcd(num - den, den);
	else
		return gcd(den - num, num);
}

void reduceFraction(Fraction& num1) {
	int factor;
	factor = gcd(num1.numerator, num1.denominator);
	num1.numerator /= factor;
	num1.denominator /= factor;
}


bool readFraction(Fraction& num) {
	bool isvalid = 0;
	char slash, peek;
	cin >> num.numerator >> slash;
	if (cin.fail()) {
		isvalid = 0;
		cin.clear();
	}
	else if ((int)slash != 47)
		isvalid = 0;
	else {
		cin >> num.denominator;
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
	Fraction num1 = { 0, 0 }, num2 = { 0, 0 };
	valid1 = readFraction(num1);
	cin >> operation;
	valid2 = readFraction(num2);
	if (valid1 != 1 || valid2 != 1)
		cout << "Error: fraction written in invalid format" << endl;
	else if (operation == '+')
		addition(num1, num2);
	else if (operation == '-')
		subtraction(num1, num2);
	else if (operation == 'x' || operation == '*')
		multiplication(num1, num2);
	else if (operation == '/')
		division(num1, num2);
	reduceFraction(num1);
	cout << " = " << num1.numerator << "/" << num1.denominator << endl;
	return 0;
}


//Exercise 5.7)