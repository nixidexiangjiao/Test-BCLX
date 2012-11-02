/*
 * bclx121test.cpp
 *
 *  Created on: 2012-9-19
 *      Author: lzero
 */
#include "Test.h"
#include <iostream>
#include <cstring>

namespace bclx121 {

class Cow {
private:
	char name[20];
	char * hobby;
	double weight;
public:
	Cow() {
		name[0] = '\0';
		hobby = new char[1];
		hobby[0] = '\0';
		weight = 0.0;
	}
	Cow(const char * nm, const char * ho, double wt) :
			weight(wt) {
		std::strncpy(name, nm, 19);
		name[19] = '\0';
		hobby = new char[std::strlen(ho) + 1];
		std::strcpy(hobby, ho);
	}
	Cow(const Cow & c) :
			weight(c.weight) {
		std::strncpy(name, c.name, 19);
		name[19] = '\0';
		hobby = new char[std::strlen(c.hobby) + 1];
		std::strcpy(hobby, c.hobby);
	}
	virtual ~Cow() {
		delete[] hobby;
	}
	Cow & operator=(const Cow & c) {
		if (this == &c)
			return *this;
		delete[] hobby;
		std::strncpy(name, c.name, 19);
		name[19] = '\0';
		hobby = new char[std::strlen(c.hobby) + 1];
		std::strcpy(hobby, c.hobby);
		weight = c.weight;
		return *this;
	}
	void ShowCow() const {
		std::cout << "Cow Name:" << name << std::endl;
		std::cout << "Cow Hobby:" << hobby << std::endl;
		std::cout << "Cow Weight:" << weight << std::endl;
	}
};

} // namespace bclx121

void bclx121test() {
	using namespace bclx121;
	Cow co("Good", "Delecious", 50.2);
	co.ShowCow();

	Cow co1;
	co1.ShowCow();
}

