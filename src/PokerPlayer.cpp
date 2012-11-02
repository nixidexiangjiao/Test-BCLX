/*
 * PokerPlayer.cpp
 *
 *  Created on: 2012-9-14
 *      Author: lzero
 */

#include "PokerPlayer.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

namespace bclx144 {

PokerPlayer::PokerPlayer(const char * fir, const char * sc) :
		Person(fir, sc) {
	// TODO Auto-generated constructor stub

}

PokerPlayer::~PokerPlayer() {
	// TODO Auto-generated destructor stub
}

const int PokerPlayer::Draw() {
	int r = std::rand() % 53;
	if(r < 0)
		r = 1;
	return r;
}

} /* namespace bclx144 */
