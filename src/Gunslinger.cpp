/*
 * Gunslinger.cpp
 *
 *  Created on: 2012-9-14
 *      Author: lzero
 */

#include "Gunslinger.h"

namespace bclx144 {

Gunslinger::Gunslinger(const char * fir, const char * sc, double st, int ni) :
		Person(fir, sc), shuttime(st), nicks(ni) {
	// TODO Auto-generated constructor stub

}

Gunslinger::~Gunslinger() {
	// TODO Auto-generated destructor stub
}
const double Gunslinger::Draw() {
	return shuttime;
}

void Gunslinger::Show() const {
	using std::cout;
	using std::endl;
	Person::Show();
	cout << "shuttime: " << shuttime << endl;
	cout << "nicks: " << nicks << endl;
}
} /* namespace bclx144 */
