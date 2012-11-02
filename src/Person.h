/*
 * Person.h
 *
 *  Created on: 2012-9-14
 *      Author: lzero
 */

#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>

namespace bclx144 {

class Person {
private:
	char *firstname;
	char *secondname;
public:
	Person(const char * fir = "NONE", const char * sc = "NONE");
	Person(const Person & p);
	Person & operator=(const Person & p);
	virtual ~Person();
	virtual void Show() const;
};

} /* namespace bclx144 */
#endif /* PERSON_H_ */
