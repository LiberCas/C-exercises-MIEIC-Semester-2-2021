//Exercise 4.1)
//a)

#include <iostream>
using namespace std;

void readArray(int a[], size_t nElem) {
	for (unsigned int i = 0; i < nElem; i++)
		cout << "\nElement of index " << i << ": " << a[i];
}

int main() {
	int a[7];
	for (unsigned int i = 0; i < 7; i++) {
		int temp;
		cout << "Please input the element of index " << i << " of your array:\n";
		cin >> temp;
		a[i] = temp;
	}
	readArray(a, 7);
	return 0;
}


//b)

#include <iostream>
using namespace std;

int findValueInArray(const int a[], size_t nElem, int value, size_t pos1, size_t pos2) {
	for (unsigned int i = pos1; (i <= pos2 && i < nElem); i++) {
		if (a[i] == value)
			return i;
	}
	return -1;

}

int main() {
	int a[7];
	int value, index;
	unsigned int pos1, pos2;
	for (unsigned int i = 0; i < 7; i++) {
		int temp;
		cout << "Please input the element of index " << i << " of your array:\n";
		cin >> temp;
		a[i] = temp;
	}
	cout << "What value would you like to find the first instance of in this array?\n";
	cin >> value;
	cout << "Between what positions(input in the format: pos1 pos2)?\n";
	cin >> pos1 >> pos2;
	index = findValueInArray(a, 7, value, pos1, pos2);
	if (index == -1)
		cout << "The value " << value << " cannot be found in the array between the positions inputted\n";
	else
		cout << "The value " << value << " is first found in the array in the position of index " << index << endl;
	return 0;
}


//d)

#include <iostream>
using namespace std;

int findValueInArray(const int a[], size_t nElem, int value, size_t pos1 = 0, size_t pos2 = 10000) {
	if (pos2 > nElem)
		pos2 = nElem;
	for (unsigned int i = pos1; (i <= pos2 && i < nElem); i++) {
		if (a[i] == value)
			return i;
	}
	return -1;

}

int main() {
	int a[7];
	int value, index;
	for (unsigned int i = 0; i < 7; i++) {
		int temp;
		cout << "Please input the element of index " << i << " of your array:\n";
		cin >> temp;
		a[i] = temp;
	}
	cout << "What value would you like to find the first instance of in this array?\n";
	cin >> value;
	index = findValueInArray(a, 7, value);
	if (index == -1)
		cout << "The value " << value << " cannot be found in the array\n";
	else
		cout << "The value " << value << " is first found in the array in the position of index " << index << endl;
	return 0;
}


//e)

#include <iostream>
using namespace std;

size_t findMultValuesInArray(const int a[], size_t nElem, int value, size_t pos1, size_t pos2, int index[]) {
	int counter = 0;
	for (unsigned int i = pos1; (i <= pos2 && i < nElem); i++) {
		if (a[i] == value) {
			index[counter] = i;
			counter++;
		}
	}
	return counter;
}

int main() {
	int a[7], indexes[7];
	int value, counter, i = 0;
	unsigned int pos1, pos2;
	for (unsigned int i = 0; i < 7; i++) {
		int temp;
		cout << "Please input the element of index " << i << " of your array:\n";
		cin >> temp;
		a[i] = temp;
	}
	cout << "What value would you like to find instances of in this array?\n";
	cin >> value;
	cout << "Between what positions(input in the format: pos1 pos2)?\n";
	cin >> pos1 >> pos2;
	counter = findMultValuesInArray(a, 7, value, pos1, pos2, indexes);
	cout << "The value " << value << " can be found " << counter << " times in the array";
	if (counter > 0) {
		cout << ", in the postitions: ";
		while (i < counter - 1) {
			cout << indexes[i] << ", ";
			i++;
		}
		cout << indexes[i] << endl;
	}
	return 0;
}


//Exercise 4.2)
//a)

#include <iostream>
#include <vector>
using namespace std;

void readVector(vector<int>& v) {
	for (unsigned int i = 0; i < v.size(); i++)
		cout << "\nElement of index " << i << ": " << v.at(i);
}

int main() {
	int size;
	cout << "What's the size of your vector(in elements):\n";
	cin >> size;
	vector <int> myvector(size);
	for (unsigned int i = 0; i < size; i++) {
		int temp;
		cout << "Please input the element of index " << i << " of your vector:\n";
		cin >> temp;
		myvector.at(i) = temp;
	}
	readVector(myvector);
	return 0;
}


//b)

#include <iostream>
#include <vector>
using namespace std;

size_t findValueInVector(const vector<int>& v, int value, size_t pos1, size_t pos2) {
	for (unsigned int i = pos1; (i <= pos2 && i < v.size()); i++) {
		if (v.at(i) == value)
			return i;
	}
	return -1;
}

int main() {
	int size, pos1, pos2, value, index;
	cout << "What's the size of your vector(in elements):\n";
	cin >> size;
	vector <int> myvector(size);
	for (unsigned int i = 0; i < size; i++) {
		int temp;
		cout << "Please input the element of index " << i << " of your vector:\n";
		cin >> temp;
		myvector.at(i) = temp;
	}
	cout << "What value would you like to find the first instance of in this vector?\n";
	cin >> value;
	cout << "Between what positions(input in the format: pos1 pos2)?\n";
	cin >> pos1 >> pos2;
	index = findValueInVector(myvector, value, pos1, pos2);
	if (index == -1)
		cout << "The value " << value << " cannot be found in the vector between the positions inputted\n";
	else
		cout << "The value " << value << " is first found in the vector in the position of index " << index << endl;
	return 0;
}


//c)

#include <iostream>
#include <vector>
using namespace std;

int findMultValuesInVector(const vector<int>& v, int value, size_t pos1, size_t pos2, vector<size_t>& index) {
	int counter = 0;
	index.resize(counter);
	for (unsigned int i = pos1; (i <= pos2 && i < v.size()); i++) {
		if (v.at(i) == value) {
			index.resize(counter + 1);
			index.at(counter) = i;
			counter++;
		}
	}
	return counter;
}

int main() {
	int size, pos1, pos2, value, counter, i = 0;
	cout << "What's the size of your vector(in elements):\n";
	cin >> size;
	vector <int> myvector(size);
	vector <size_t> indexes;
	for (unsigned int i = 0; i < size; i++) {
		int temp;
		cout << "Please input the element of index " << i << " of your vector:\n";
		cin >> temp;
		myvector.at(i) = temp;
	}
	cout << "What value would you like to find instances of in this vector?\n";
	cin >> value;
	cout << "Between what positions(input in the format: pos1 pos2)?\n";
	cin >> pos1 >> pos2;
	counter = findMultValuesInVector(myvector, value, pos1, pos2, indexes);
	cout << "The value " << value << " can be found " << counter << " times in the vector";
	if (counter > 0) {
		cout << ", in the postitions: ";
		while (i < counter - 1) {
			cout << indexes.at(i) << ", ";
			i++;
		}
		cout << indexes.at(i) << endl;
	}
	return 0;
}


//d)

#include <iostream>
#include <vector>
using namespace std;

vector<size_t> findMultValuesInVector(const vector<int>& v, int value, size_t pos1, size_t pos2) {
	int counter = 0;
	vector<size_t> index(0);
	for (unsigned int i = pos1; (i <= pos2 && i < v.size()); i++) {
		if (v.at(i) == value) {
			index.resize(counter + 1);
			index.at(counter) = i;
			counter++;
		}
	}
	return index;
}

int main() {
	int size, pos1, pos2, value, i = 0;
	cout << "What's the size of your vector(in elements):\n";
	cin >> size;
	vector <int> myvector(size);
	vector <size_t> indexes;
	for (unsigned int i = 0; i < size; i++) {
		int temp;
		cout << "Please input the element of index " << i << " of your vector:\n";
		cin >> temp;
		myvector.at(i) = temp;
	}
	cout << "What value would you like to find instances of in this vector?\n";
	cin >> value;
	cout << "Between what positions(input in the format: pos1 pos2)?\n";
	cin >> pos1 >> pos2;
	indexes = findMultValuesInVector(myvector, value, pos1, pos2);
	cout << "The value " << value << " can be found " << indexes.size() << " times in the vector";
	if (indexes.size() > 0) {
		cout << ", in the postitions: ";
		while (i < indexes.size() - 1) {
			cout << indexes.at(i) << ", ";
			i++;
		}
		cout << indexes.at(i) << endl;
	}
	return 0;
}


