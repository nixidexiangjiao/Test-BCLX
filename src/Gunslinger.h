/*
 * Gunslinger.h
 *
 *  Created on: 2012-9-14
 *      Author: lzero
 */

#ifndef GUNSLINGER_H_
#define GUNSLINGER_H_

#include "Person.h"

namespace bclx144 {

class Gunslinger: public virtual bclx144::Person {
private:
	double shuttime;
	int nicks;
public:
	Gunslinger(const char * fir = "NONE", const char * sc = "NONE", double st =
			0.0, int ni = 0);
	Gunslinger(const Person & p, double st = 0.0, int ni = 0) :
			Person(p), shuttime(st), nicks(ni) {
	}
	Gunslinger(const Gunslinger & p) :
			Person(p), shuttime(p.shuttime), nicks(p.nicks) {
	}
	virtual ~Gunslinger();
	const double Draw();
	virtual void Show() const;
};

} /* namespace bclx144 */
#endif /* GUNSLINGER_H_ */
