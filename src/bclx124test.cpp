/*
 * bclx124test.cpp
 *
 *  Created on: 2012-9-20
 *      Author: lzero
 */
#include <iostream>
#include "Test.h"

namespace bclx124 {

typedef unsigned long Item;

class Stack {
private:
	enum {
		MAX = 10
	}; // constant specific to class
	Item * pitems; // holds stack items
	int size;
	int top; // index for top stack item
public:
	Stack(int n = MAX);
	Stack(const Stack & st);
	virtual ~Stack();
	bool isempty() const;
	bool isfull() const;
	// push() returns false if stack already is full, true otherwise
	bool push(const Item & item); // add item to stack
	// pop() returns false if stack already is empty, true otherwise
	bool pop(Item & item); // pop top into item
	Stack & operator=(const Stack & st);
};

Stack::Stack(int n) {
	size = n;
	pitems = new Item[size];
	top = 0;
}

Stack::Stack(const Stack & st) {
	size = st.size;
	pitems = new Item[size];
	top = st.top;
	for (int i = 0; i < top; i++) {
		pitems[i] = st.pitems[i];
	}
}

Stack::~Stack() {
	delete[] pitems;
}

bool Stack::isempty() const {
	return top == 0;
}

bool Stack::isfull() const {
	return top == size;
}

bool Stack::push(const Item & item) {
	if (top < MAX) {
		pitems[top++] = item;
		return true;
	} else
		return false;
}

bool Stack::pop(Item & item) {
	if (top > 0) {
		item = pitems[--top];
		return true;
	} else
		return false;
}

Stack & Stack::operator=(const Stack & st) {
	if (this == &st)
		return *this;
	delete[] pitems;
	size = st.size;
	pitems = new Item[size];
	top = st.top;
	for (int i = 0; i < top; i++) {
		pitems[i] = st.pitems[i];
	}
	return *this;
}
} // namespace bclx124

void bclx124test() {
	using namespace std;
	using namespace bclx124;

	Stack st(3);
	unsigned long temp;
	char c;

	cout << "Please enter A to add a PO,\n"
			<< "P to process a PO, and Q to Quit.\n";
	while (cin >> c && (c = toupper(c)) != 'Q') {
		while (cin.get() != '\n')
			continue;
		if (c != 'A' && c != 'P') {
			cout << "Please respond with A,P,or Q: ";
			continue;
		}
		switch (c) {
		case 'A':
			if (st.isfull()) {
				cout << "stack already full\n";
			} else {
				cout << "Enter PO number: ";
				cin >> temp;
				st.push(temp);
			}
			break;
		case 'P':
			if (st.isempty()) {
				cout << "stack already empty\n";
			} else {
				st.pop(temp);
				cout << "Processing PO " << temp << endl;
			}
			break;
		default:
			cout << "Whoops! Programming error!\n";
			break;
		}
		cout << "Please enter A to add a customer,\n"
				<< "P to process a customer,and Q to quit.\n";
	}
	cout << "Done!\n";
}

