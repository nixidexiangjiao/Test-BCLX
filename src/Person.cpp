/*
 * Person.cpp
 *
 *  Created on: 2012-9-14
 *      Author: lzero
 */

#include "Person.h"
#include <cstring>

namespace bclx144 {

Person::Person(const char * fir, const char * sc) {
	// TODO Auto-generated constructor stub
	int len1 = std::strlen(fir);
	int len2 = std::strlen(sc);
	firstname = new char[len1 + 1];
	secondname = new char[len2 + 1];
	std::strcpy(firstname, fir);
	std::strcpy(secondname, sc);
}

Person::Person(const Person & p) {
	int len1 = std::strlen(p.firstname);
	int len2 = std::strlen(p.secondname);
	firstname = new char[len1 + 1];
	secondname = new char[len2 + 1];
	std::strcpy(firstname, p.firstname);
	std::strcpy(secondname, p.secondname);
}

Person & Person::operator=(const Person & p) {
	int len1 = std::strlen(p.firstname);
	int len2 = std::strlen(p.secondname);
	firstname = new char[len1 + 1];
	secondname = new char[len2 + 1];
	std::strcpy(firstname, p.firstname);
	std::strcpy(secondname, p.secondname);
	firstname[len1] = '\0';
	secondname[len2] = '\0';
	return *this;
}

Person::~Person() {
	// TODO Auto-generated destructor stub
	delete[] firstname;
	delete[] secondname;
}

void Person::Show() const {
	using std::cout;
	using std::endl;
	cout << "firstname:" << firstname << endl;
	cout << "secondname:" << secondname << endl;
}

} /* namespace bclx144 */
