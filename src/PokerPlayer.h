/*
 * PokerPlayer.h
 *
 *  Created on: 2012-9-14
 *      Author: lzero
 */

#ifndef POKERPLAYER_H_
#define POKERPLAYER_H_

#include "Person.h"

namespace bclx144 {

class PokerPlayer: public virtual bclx144::Person {
public:
	PokerPlayer(const char * fir = "NONE", const char * sc = "NONE");
	PokerPlayer(const Person & p) :
			Person(p) {
	}
	PokerPlayer(const PokerPlayer & p) :
			Person(p) {
	}
	virtual ~PokerPlayer();
	const int Draw();
	void Show() const {
		Person::Show();
	}
};

} /* namespace bclx144 */
#endif /* POKERPLAYER_H_ */
