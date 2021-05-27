#include <iostream>
#include <string>
#include "Person.h"
#include "Date.h"

using namespace std;

int main() {
	Person raul;
	raul.setBirthDate(1945, 6, 28);
	raul.setName("Raul Seixas");
	raul.setGender('m');
	cout << raul.getName() << " - " << raul.getGender() << " - " << raul.getBirthstr() << endl;
	return 0;
}
