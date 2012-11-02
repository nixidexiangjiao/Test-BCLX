/*
 * bclx112test.cpp
 *
 *  Created on: 2012-9-21
 *      Author: lzero
 */
#include <iostream>
#include "Test.h"
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>
#include <fstream>
#include <cmath>
#include <set>
#include <iterator>

namespace bclx112 {

using std::sqrt;
using std::sin;
using std::cos;
using std::atan2;
using std::cout;

class Vector {
private:
	double x; // horizontal value
	double y; // vertical value
	char mode; // 'r' = rectangular, 'p' = polar
	// private methods for setting values
	void set_x(double mag, double ang);
	void set_y(double mag, double ang);
public:
	Vector();
	Vector(double n1, double n2, char form = 'r');
	void set(double n1, double n2, char form = 'r');
	~Vector();
	double xval() const {
		return x;
	} // report x value
	double yval() const {
		return y;
	} // report y value
	double magval() const {
		double mag = sqrt(x * x + y * y);
		return mag;
	} // report magnitude
	double angval() const {
		double ang;
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
		return ang;
	} // report angle
	void polar_mode(); // set mode to 'p'
	void rect_mode(); // set mode to 'r'
	// operator overloading
	Vector operator+(const Vector & b) const;
	Vector operator-(const Vector & b) const;
	Vector operator-() const;
	Vector operator*(double n) const;
	// friends
	friend Vector operator*(double n, const Vector & a);
	friend std::ostream & operator<<(std::ostream & os, const Vector & v);
};
const double Rad_to_deg = 57.2957795130823;

// set x from polar coordinate
void Vector::set_x(double mag, double ang) {
	x = mag * cos(ang);
}

// set y from polar coordinate
void Vector::set_y(double mag, double ang) {
	y = mag * sin(ang);
}

// public methods
Vector::Vector() // default constructor
{
	x = y = 0.0;
	mode = 'r';
}

// construct vector from rectangular coordinates if form is r
// (the default) or else from polar coordinates if form is p
Vector::Vector(double n1, double n2, char form) {
	mode = form;
	if (form == 'r') {
		x = n1;
		y = n2;
	} else if (form == 'p') {
		set_x(n1, n2 / Rad_to_deg);
		set_y(n1, n2 / Rad_to_deg);
	} else {
		cout << "Incorrect 3rd argument to Vector() -- ";
		cout << "vector set to 0\n";
		x = y = 0.0;
		mode = 'r';
	}
}

// set vector from rectangular coordinates if form is r (the
// default) or else from polar coordinates if form is p
void Vector::set(double n1, double n2, char form) {
	mode = form;
	if (form == 'r') {
		x = n1;
		y = n2;
	} else if (form == 'p') {
		set_x(n1, n2 / Rad_to_deg);
		set_y(n1, n2 / Rad_to_deg);
	} else {
		cout << "Incorrect 3rd argument to Vector() -- ";
		cout << "vector set to 0\n";
		x = y = 0.0;
		mode = 'r';
	}
}

Vector::~Vector() // destructor
{
}

void Vector::polar_mode() // set to polar mode
{
	mode = 'p';
}

void Vector::rect_mode() // set to rectangular mode
{
	mode = 'r';
}

// operator overloading
// add two Vectors
Vector Vector::operator+(const Vector & b) const {
	return Vector(x + b.x, y + b.y);
}

// subtract Vector b from a
Vector Vector::operator-(const Vector & b) const {
	return Vector(x - b.x, y - b.y);
}

// reverse sign of Vector
Vector Vector::operator-() const {
	return Vector(-x, -y);
}

// multiple vector by n
Vector Vector::operator*(double n) const {
	return Vector(n * x, n * y);
}

// friend methods
// multiply n by Vector a
Vector operator*(double n, const Vector & a) {
	return a * n;
}

// display rectangular coordinates if mode is r,
// else display polar coordinates if mode is p
std::ostream & operator<<(std::ostream & os, const Vector & v) {
	if (v.mode == 'r')
		os << "(x,y) = (" << v.x << ", " << v.y << ")";
	else if (v.mode == 'p') {
		os << "(m,a) = (" << v.magval() << ", " << v.angval() * Rad_to_deg
				<< ")";
	} else
		os << "Vector object mode is invalid";
	return os;
}

} // namespace bclx112t

double caculateSum(std::set<double> & stepSet);

void bclx112test() {
	using namespace std;
	using bclx112::Vector;
	srand(time(0)); // seed random-number generator
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	double steps = 0;
	double target;
	double dstep;
	cout << "Enter you want test time:";
	int N;
	int time = 0;
	cin >> N;
	while (!cin) {
		cout << "Error input!!\n";
		cout << "Enter you want test time:";
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cin >> N;
	}
	set<double> stepSet;

	cout << "Enter target distance (q to quit): ";
	while (time < N && cin >> target) {
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		while (result.magval() < target) {
			direction = rand() % 360;
			step.set(dstep, direction, 'p');
			result = result + step;
			steps++;
		}
		stepSet.insert(steps);
//		cout << "After " << steps << " steps, the subject "
//				"has the following location:\n";
//		cout << result << endl;
		result.polar_mode();
//		cout << " or\n" << result << endl;
//		cout << "Average outward distance per step = "
//				<< result.magval() / steps << endl;
		steps = 0;
		result.set(0.0, 0.0);
		time++;
		if (time < N)
			cout << "Enter target distance (q to quit): ";
	}

	cout.setf(ios_base::floatfield, ios_base::fixed);
	cout.setf(ios_base::showpoint);
	cout.precision(1);
	cout << "最高步数：" << *(stepSet.rbegin()) << endl;
	cout << "最低步数：" << *(stepSet.begin()) << endl;
	cout << "平均步数：" << caculateSum(stepSet) / stepSet.size() << endl;
	cout << "Bye!\n";
}

double caculateSum(std::set<double> & stepSet) {
	long result = 0;
	for (std::set<double>::iterator it = stepSet.begin(); it != stepSet.end();
			it++) {
		result += *it;
	}
	return result;
}
