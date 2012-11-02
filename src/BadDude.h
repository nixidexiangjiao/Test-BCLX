/*
 * BadDude.h
 *
 *  Created on: 2012-9-14
 *      Author: lzero
 */

#ifndef BADDUDE_H_
#define BADDUDE_H_

#include "Gunslinger.h"
#include "PokerPlayer.h"

namespace bclx144 {

class BadDude: public bclx144::Gunslinger, public bclx144::PokerPlayer {
public:
	BadDude(const char * fir = "NONE", const char * sc = "NONE",
			double st = 0.0, int ni = 0);
	BadDude(const BadDude & b) :
			Person(b), Gunslinger(b), PokerPlayer(b) {

	}
	virtual ~BadDude();
	double Gdraw() {
		return Gunslinger::Draw();
	}
	const int Cdraw() {
		return PokerPlayer::Draw();
	}
	void Show() const;
};

} /* namespace bclx144 */
#endif /* BADDUDE_H_ */
