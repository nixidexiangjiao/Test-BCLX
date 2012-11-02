/*
 * bclx144.cpp
 *
 *  Created on: 2012-9-14
 *      Author: lzero
 */
#include <iostream>
#include <cstring>
#include "Person.h"
#include "Gunslinger.h"
#include "PokerPlayer.h"
#include "BadDude.h"
#include "Test.h"

const int SIZE = 5;

void bclx144test() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	using namespace bclx144;

	Person * lolas[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++) {
		char choice;
		cout << "Enter the employee category:\n" << "g: Gunslinger  p: PokerPlayer  "
				<< "b: BadDude  q: quit\n";
		cin >> choice;
		while (strchr("gpbq", choice) == NULL) {
			cout << "Please enter a g, p, b, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice) {
		case 'g':
			lolas[ct] = new Person("test1", "test1");
			break;
		case 'p':
			lolas[ct] = new Gunslinger("test2", "test2", 12, 20);
			break;
		case 'b':
			lolas[ct] = new BadDude("test3", "test3");
			break;
		}
		cin.get();
	}

	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++) {
		cout << endl;
		lolas[i]->Show();
	}
	for (i = 0; i < ct; i++)
		delete lolas[i];
	cout << "Bye.\n";
}

