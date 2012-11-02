/*
 * BadDude.cpp
 *
 *  Created on: 2012-9-14
 *      Author: lzero
 */

#include "BadDude.h"

namespace bclx144 {

BadDude::BadDude(const char * fir, const char * sc, double st, int ni) :
		Person(fir, sc), Gunslinger(fir, sc, st, ni), PokerPlayer(fir, sc) {
	// TODO Auto-generated constructor stub

}

BadDude::~BadDude() {
	// TODO Auto-generated destructor stub
}

void BadDude::Show() const {
	Gunslinger::Show();
}
} /* namespace bclx144 */
