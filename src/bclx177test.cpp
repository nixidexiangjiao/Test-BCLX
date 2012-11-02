/*
 * bclx177test.cpp
 *
 *  Created on: 2012-9-17
 *      Author: lzero
 */
#include "Test.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>

static void ShowStr(const std::string & s);
static void GetStrs(std::ifstream & fin, std::vector<std::string> & vistr);

namespace bclx177 {
class Store {
private:
	std::ofstream & fout;
public:
	Store(std::ofstream & f) :
			fout(f) {

	}
	void operator()(std::string & s) {
		std::size_t len = s.size();
		fout.write((char *) &len, sizeof(std::size_t));
		fout.write(s.data(), len);
	}
};
} // namespace bclx177

void bclx177test() {
	using namespace std;
	using namespace bclx177;
	vector<string> vostr;
	string temp;

	cout << "Enter strings(empty line to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0') {
		vostr.push_back(temp);
	}

	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);

	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open()) {
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);
}

static void ShowStr(const std::string & s) {
	std::cout << s << std::endl;
}

static void GetStrs(std::ifstream & fin, std::vector<std::string> & vistr) {
	std::size_t len;
	while (fin.read((char *) &len, sizeof(std::size_t)) && len > 0) {
//		char temp[len];
//		fin.read(temp, len);
//		if (fin) {
//			std::string stemp = "";
//			stemp += temp;
//			vistr.push_back(stemp);
//		}
		char ch;
		std::string temp = "";
		for (std::size_t j = 0; j < len; ++j) {
			if (fin.read(&ch, 1)) {
				temp += ch;
			} else {
				break;
			}
		}
		if(fin)
			vistr.push_back(temp);
	}
}
