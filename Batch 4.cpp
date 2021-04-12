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


//Exercise 4.3)
//a)

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& v) {
	for (int upper_index = v.size() - 1; upper_index > 0; upper_index--) {
		for (int i = 0; i < upper_index; i++) {
			if (v.at(i) > v.at(i + 1))
				swap(v.at(i), v.at(i + 1));
		}
	}
}

int main() {
	int i = 0, size;
	cout << "Please input the size of your vector:\n";
	cin >> size;
	vector<int> v(size);
	for (int j = 0; j < size; j++) {
		int temp;
		cout << "Please input the element of index " << j << " of your vector:\n";
		cin >> temp;
		v.at(j) = temp;
	}
	bubbleSort(v);
	cout << "Here's the sorted vector: ";
	while (i < v.size() - 1) {
		cout << v.at(i) << " < ";
		i++;
	}
	cout << v.at(i);
	return 0;
}


//b)

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& v) {
	for (int upper_index = v.size() - 1; upper_index > 0; upper_index--) {
		int swap_num = 0;
		for (int i = 0; i < upper_index; i++) {
			if (v.at(i) > v.at(i + 1)) {
				swap(v.at(i), v.at(i + 1));
				swap_num++;
			}
		}
		if (swap_num == 0) {
			break;
		}
	}
}

int main() {
	int i = 0, size;
	cout << "Please input the size of your vector:\n";
	cin >> size;
	vector<int> v(size);
	for (int j = 0; j < size; j++) {
		int temp;
		cout << "Please input the element of index " << j << " of your vector:\n";
		cin >> temp;
		v.at(j) = temp;
	}
	bubbleSort(v);
	cout << "Here's the sorted vector: ";
	while (i < v.size() - 1) {
		cout << v.at(i) << " < ";
		i++;
	}
	cout << v.at(i);
	return 0;
}


//c)

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& v, char da) {
	if (da == 'a') {
		for (int upper_index = v.size() - 1; upper_index > 0; upper_index--) {
			int swap_num = 0;
			for (int i = 0; i < upper_index; i++) {
				if (v.at(i) > v.at(i + 1)) {
					swap(v.at(i), v.at(i + 1));
					swap_num++;
				}
			}
			if (swap_num == 0) {
				break;
			}
		}
	}
	else {
		for (int upper_index = v.size() - 1; upper_index > 0; upper_index--) {
			int swap_num = 0;
			for (int i = 0; i < upper_index; i++) {
				if (v.at(i) < v.at(i + 1)) {
					swap(v.at(i), v.at(i + 1));
					swap_num++;
				}
			}
			if (swap_num == 0) {
				break;
			}
		}
	}
}

int main() {
	int i = 0, size;
	char da;
	cout << "Please input the size of your vector:\n";
	cin >> size;
	vector<int> v(size);
	for (int j = 0; j < size; j++) {
		int temp;
		cout << "Please input the element of index " << j << " of your vector:\n";
		cin >> temp;
		v.at(j) = temp;
	}
	cout << "How would you like to sort your vector? (d for descending order/a for ascending order):\n";
	cin >> da;
	bubbleSort(v, da);
	cout << "Here's the sorted vector: ";
	if (da == 'a')
		da = '<';
	else
		da = '>';
	while (i < v.size() - 1) {
		cout << v.at(i) << " " << da << " ";
		i++;
	}
	cout << v.at(i);
	return 0;
}


//d)

#include <iostream>
#include <vector>
using namespace std;

bool ascending(int x, int y) {
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

void bubbleSort(vector<int>& v, bool f(int x, int y)) {
	for (int upper_index = v.size() - 1; upper_index > 0; upper_index--) {
		int swap_num = 0;
		for (int i = 0; i < upper_index; i++) {
			if (!f(v.at(i), v.at(i + 1))) {
				swap(v.at(i), v.at(i + 1));
				swap_num++;
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
	vector<int> v(size);
	for (int j = 0; j < size; j++) {
		int temp;
		cout << "Please input the element of index " << j << " of your vector:\n";
		cin >> temp;
		v.at(j) = temp;
	}
	cout << "How would you like to sort your vector? (d for descending order/a for ascending order):\n";
	cin >> da;
	if (da == 'a')
		bubbleSort(v, ascending);
	else
		bubbleSort(v, descending);
	cout << "Here's the sorted vector: ";
	if (da == 'a')
		da = '<';
	else
		da = '>';
	while (i < v.size() - 1) {
		cout << v.at(i) << " " << da << " ";
		i++;
	}
	cout << v.at(i);
	return 0;
}


//Exercise 4.4)

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& v, int value) {
	int first = 0, last = v.size() - 1, middle;
	bool found = 0;
	while (found == 0 && first <= last) {
		middle = floor((first + last) / 2);
		if (v.at(middle) == value)
			found = 1;
		else if (value > v.at(middle))
			first = middle + 1;
		else
			last = middle - 1;
	}
	if (found == 0)
		return -1;
	else
		return middle;
}

int main() {
	int size, value, index;
	cout << "Please input the size of your vector:\n";
	cin >> size;
	vector<int> v(size);
	for (int j = 0; j < size; j++) {
		int temp;
		cout << "Please input the element of index " << j << " of your vector(sorted in ascending order):\n";
		cin >> temp;
		v.at(j) = temp;
	}
	cout << "Which value would you like to find in the vector:\n";
	cin >> value;
	index = binarySearch(v, value);
	if (index == -1)
		cout << "The value cannot be found in the vector";
	else
		cout << "The value can be found in the position of index " << index << endl;
	return 0;
}


//Exercise 4.5)

#include <iostream>
#include <vector>
using namespace std;

void removeDuplicates(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		int value = v.at(i);
		for (int j = i + 1; j < v.size(); j++) {
			if (v.at(j) == value) {
				for (int k = j; k < v.size() - 1; k++)
					v.at(k) = v.at(k + 1);
				v.resize(v.size() - 1);
				j--;
			}
		}
	}
}

int main() {
	int size, i = 0;
	cout << "Please input the size of your vector:\n";
	cin >> size;
	vector<int> v(size);
	for (int j = 0; j < size; j++) {
		cout << "Please input the element of index " << j << " of your vector:\n";
		cin >> v.at(j);
	}
	removeDuplicates(v);
	cout << "Here's your vector with all duplicates removed:\n";
	while (i < v.size() - 1) {
		cout << v.at(i) << ", ";
		i++;
	}
	cout << v.at(i) << endl;
	return 0;
}


//Exercise 4.6)

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& v, int value) {
	int first = 0, last = v.size() - 1, middle;
	bool found = 0;
	while (found == 0 && first <= last) {
		middle = floor((first + last) / 2);
		if (v.at(middle) == value)
			found = 1;
		else if (value > v.at(middle))
			first = middle + 1;
		else
			last = middle - 1;
	}
	if (found == 0)
		return -1;
	else
		return middle;
}

void bubbleSortAscending(vector<int>& v) {
	for (int upper_index = v.size() - 1; upper_index > 0; upper_index--) {
		int swap_num = 0;
		for (int i = 0; i < upper_index; i++) {
			if (v.at(i) > v.at(i + 1)) {
				swap(v.at(i), v.at(i + 1));
				swap_num++;
			}
		}
		if (swap_num == 0) {
			break;
		}
	}
}

void removeDuplicates(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		int value = v.at(i);
		for (int j = i + 1; j < v.size(); j++) {
			if (v.at(j) == value) {
				for (int k = j; k < v.size() - 1; k++)
					v.at(k) = v.at(k + 1);
				v.resize(v.size() - 1);
				j--;
			}
		}
	}
}

void vectorUnion(const vector<int>& v1, const vector<int>& v2, vector<int>& v3) {
	for (int i = 0; i < v1.size(); i++) {
		v3.push_back(1);
		v3.at(i) = v1.at(i);
	}
	for (int i = 0; i < v2.size(); i++) {
		v3.push_back(1);
		v3.at(v1.size() + i) = v2.at(i);
	}
	removeDuplicates(v3);
	bubbleSortAscending(v3);
}
void vectorIntersection(vector<int>& v1, vector<int>& v2, vector<int>& v3) {
	int v3_index = 0;
	removeDuplicates(v1);
	bubbleSortAscending(v1);
	bubbleSortAscending(v2);
	for (int i = 0; i < v1.size(); i++) {
		if (binarySearch(v2, v1.at(i)) != -1) {
			v3.push_back(1);
			v3.at(v3_index) = v1.at(i);
			v3_index++;
		}
	}
}

int main() {
	vector <int> v3_union(0), v3_intersection(0);
	int size1, size2, i = 0, k = 0;
	cout << "Please input the size of your first vector:\n";
	cin >> size1;
	vector<int> v1(size1);
	for (int j = 0; j < size1; j++) {
		cout << "Please input the element of index " << j << " of your first vector:\n";
		cin >> v1.at(j);
	}
	cout << "Please input the size of your second vector:\n";
	cin >> size2;
	vector<int> v2(size2);
	for (int j = 0; j < size2; j++) {
		cout << "Please input the element of index " << j << " of your second vector:\n";
		cin >> v2.at(j);
	}
	vectorUnion(v1, v2, v3_union);
	vectorIntersection(v1, v2, v3_intersection);
	cout << "Here's the union of the two vectors: ";
	while (i < v3_union.size() - 1) {
		cout << v3_union.at(i) << ", ";
		i++;
	}
	cout << v3_union.at(i) << endl;
	cout << "\nHere's the intersection of the two vectors: ";
	while (k < v3_intersection.size() - 1) {
		cout << v3_intersection.at(k) << ", ";
		k++;
	}
	cout << v3_intersection.at(k) << endl;
	return 0;
}


//Exercise 4.7)
//a)

#include <iostream>
using namespace std;

const int NE = 5;

void localMax(const int a[][NE]) {
	for (int i = 0; i < NE; i++) {
		for (int j = 0; j < NE; j++) {
			if (i != 0 && j != 0 && i != NE - 1 && j != NE - 1) {
				if (a[i][j] > a[i - 1][j - 1] && a[i][j] > a[i - 1][j] &&
					a[i][j] > a[i - 1][j + 1] && a[i][j] > a[i][j - 1] &&
					a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j - 1] &&
					a[i][j] > a[i + 1][j] && a[i][j] > a[i + 1][j + 1])
					cout << "Local maximum found at location i = " << i <<
					", j = " << j << " . Value = " << a[i][j] << endl;
			}
		}
	}
}

int main() {
	int example_array[][NE] = { {7, 3, 4, 1, 3}, {2, 9, 6, 2, 1}, {1, 3, 5, 1, 4},{6, 5, 2, 7, 5}, {4, 2, 1, 3, 6} };
	localMax(example_array);
	return 0;
}


//b)

#include <iostream>
#include <vector>
using namespace std;

const int NE = 5;

void localMax(vector< vector<int> >& a, bool full) {
	if (full) {
		for (int i = 0; i < NE; i++) {
			for (int j = 0; j < NE; j++) {
				if (i != 0 && j != 0 && i != NE - 1 && j != NE - 1) {
					if (a[i][j] > a[i - 1][j - 1] &&
						a[i][j] > a[i - 1][j] &&
						a[i][j] > a[i - 1][j + 1] &&
						a[i][j] > a[i][j - 1] &&
						a[i][j] > a[i][j + 1] &&
						a[i][j] > a[i + 1][j - 1] &&
						a[i][j] > a[i + 1][j] &&
						a[i][j] > a[i + 1][j + 1])
						cout << "Local maximum found at location i = " << i <<
						", j = " << j << " . Value = " << a[i][j] << endl;
				}
			}
		}
	}
	else {
		for (int i = 0; i < NE; i++) {
			for (int j = 0; j < NE; j++) {
				if ((i == 0 || j == 0 || a[i][j] > a[i - 1][j - 1]) &&
					(i == 0 || a[i][j] > a[i - 1][j]) &&
					(i == 0 || j == NE - 1 || a[i][j] > a[i - 1][j + 1]) &&
					(j == 0 || a[i][j] > a[i][j - 1]) &&
					(j == NE - 1 || a[i][j] > a[i][j + 1]) &&
					(i == NE - 1 || j == 0 || a[i][j] > a[i + 1][j - 1]) &&
					(i == NE - 1 || a[i][j] > a[i + 1][j]) &&
					(i == NE - 1 || j == NE - 1 || a[i][j] > a[i + 1][j + 1]))
					cout << "Local maximum found at location i = " << i <<
					", j = " << j << " . Value = " << a[i][j] << endl;
			}
		}
	}
}

int main() {
	vector <vector <int>> example_vector = { {7, 3, 4, 1, 3}, {2, 9, 6, 2, 1}, {1, 3, 5, 1, 4},{6, 5, 2, 7, 5}, {4, 2, 1, 3, 6} };
	cout << "All the full maxima:\n\n";
	localMax(example_vector, 1);
	cout << "\nAll the partial maxima:\n\n";
	localMax(example_vector, 0);
	return 0;
}
