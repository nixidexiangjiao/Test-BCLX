/*
 * bclx111test.cpp
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

namespace bclx111 {
using std::sqrt;
using std::sin;
using std::cos;
using std::atan2;
using std::cout;

class Vector {
private:
	double x; // horizontal value
	double y; // vertical value
	double mag; // length of vector
	double ang; // direction of vector
	char mode; // 'r' = rectangular, 'p' = polar
	// private methods for setting values
	void set_mag();
	void set_ang();
	void set_x();
	void set_y();
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
		return mag;
	} // report magnitude
	double angval() const {
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

// private methods
// calculates magnitude from x and y
void Vector::set_mag() {
	mag = sqrt(x * x + y * y);
}

void Vector::set_ang() {
	if (x == 0.0 && y == 0.0)
		ang = 0.0;
	else
		ang = atan2(y, x);
}
// set x from polar coordinate
void Vector::set_x() {
	x = mag * cos(ang);
}

// set y from polar coordinate
void Vector::set_y() {
	y = mag * sin(ang);
}

// public methods
Vector::Vector() // default constructor
{
	x = y = mag = ang = 0.0;
	mode = 'r';
}

// construct vector from rectangular coordinates if form is r
// (the default) or else from polar coordinates if form is p
Vector::Vector(double n1, double n2, char form) {
	mode = form;
	if (form == 'r') {
		x = n1;
		y = n2;
		set_mag();
		set_ang();
	} else if (form == 'p') {
		mag = n1;
		ang = n2 / Rad_to_deg;
		set_x();
		set_y();
	} else {
		cout << "Incorrect 3rd argument to Vector() -- ";
		cout << "vector set to 0\n";
		x = y = mag = ang = 0.0;
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
		set_mag();
		set_ang();
	} else if (form == 'p') {
		mag = n1;
		ang = n2 / Rad_to_deg;
		set_x();
		set_y();
	} else {
		cout << "Incorrect 3rd argument to Vector() -- ";
		cout << "vector set to 0\n";
		x = y = mag = ang = 0.0;
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
		os << "(m,a) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
	} else
		os << "Vector object mode is invalid";
	return os;
}

} // end namespace VECTOR

void bclx111test() {
	using namespace std;
	using bclx111::Vector;
	srand(time(0)); // seed random-number generator
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";

	ofstream fout("bclx111test.txt", ios_base::out);

	if (!fout.is_open()) {
		cout << "Can't open the file.\n";
		exit(EXIT_FAILURE);
	}

	while (cin >> target) {
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		fout << "Target Distance: " << target << ", Step Size: " << dstep <<endl;
		while (result.magval() < target) {
			direction = rand() % 360;
			step.set(dstep, direction, 'p');
			step.rect_mode();
			fout << steps << ": ";
			fout << step << endl;

			result = result + step;
			steps++;
		}
		fout << "After " << steps << " steps, the subject "
				"has the following location:\n";
		fout << result << endl;
		result.polar_mode();
		fout << " or\n" << result << endl;
		fout << "Average outward distance per step = "
				<< result.magval() / steps << endl;
		steps = 0;
		result.set(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
}

