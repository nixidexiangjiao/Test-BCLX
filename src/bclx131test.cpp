/*
 * bclx131test.cpp
 *
 *  Created on: 2012-9-17
 *      Author: lzero
 */
#include "Test.h"
#include <iostream>
#include <string>

namespace bclx131 {
class Cd {
private:
	std::string performers;
	std::string label;
	int selections;
	double playtime;
public:
	Cd(std::string s1 = "None", std::string s2 = "None", int n = 0, double x =
			0.0) :
			performers(s1), label(s2), selections(n), playtime(x) {

	}
//	Cd(const Cd & d);
//	Cd();
	virtual ~Cd(){}
	virtual void Report() const {
		std::cout << performers << std::endl;
		std::cout << label << std::endl;
		std::cout << selections << std::endl;
		std::cout << playtime << std::endl;
	}
//	Cd & operator=(const Cd & d);
	friend std::ostream & operator<<(std::ostream & cout, const Cd & c) {
		c.Report();
		return cout;
	}
};

class Classic: public Cd {
private:
	std::string mainwork;
public:
	Classic(std::string s0 = "None", std::string s1 = "None", std::string s2 =
			"None", int n = 0, double x = 0.0) :
			mainwork(s0), Cd(s1, s2, n, x) {

	}

	virtual void Report() const {
		Cd::Report();
		std::cout << mainwork << std::endl;
	}
};

} // namespace bclx131

void bclx131test() {
	using namespace bclx131;
	Cd c1("test1", "test1", 10, 11.20);
	Classic c2("test2", "test2", "test2", 20, 20.10);
	std::cout << c1 << std::endl;
	std::cout << c2 << std::endl;
}

