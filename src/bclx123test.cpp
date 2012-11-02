/*
 * bclx122test.cpp
 *
 *  Created on: 2012-9-19
 *      Author: lzero
 */
#include "Test.h"
#include <iostream>
#include <cstring>

namespace bclx123 {

class Stock {
private:
	char * company;
	int shares;
	double share_val;
	double total_val;
	void set_tot() {
		total_val = shares * share_val;
	}
public:
	Stock(); // default constructor
	Stock(const char * co, int n = 0, double pr = 0.0);
	Stock(const Stock & st);
	virtual ~Stock(); // do-nothing destructor
	Stock & operator=(const Stock & st);
	void buy(int num, double price);
	void sell(int num, double price);
	void update(double price);
//	void show() const;
	const Stock & topval(const Stock & s) const;
	friend std::ostream & operator<<(std::ostream & out, const Stock & st);
};

Stock::Stock() // default constructor
{
	company = new char[8];
	std::strcpy(company, "no name");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char * co, int n, double pr) {
	company = new char[std::strlen(co) + 1];
	std::strcpy(company, co);

	if (n < 0) {
		std::cerr << "Number of shares can't be negative; " << company
				<< " shares set to 0.\n";
		shares = 0;
	} else
		shares = n;
	share_val = pr;
	set_tot();
}

Stock::Stock(const Stock & st) {
	company = new char[std::strlen(st.company) + 1];
	std::strcpy(company, st.company);

	shares = st.shares;
	share_val = st.share_val;
	set_tot();
}

// class destructor
Stock::~Stock() // quiet class destructor
{
	delete[] company;
}

Stock & Stock::operator=(const Stock & st) {
	if (this == &st)
		return *this;
	delete[] company;
	company = new char[std::strlen(st.company) + 1];
	std::strcpy(company, st.company);

	shares = st.shares;
	share_val = st.share_val;
	set_tot();
	return *this;
}

// other methods
void Stock::buy(int num, double price) {
	if (num < 0) {
		std::cerr << "Number of shares purchased can't be negative. "
				<< "Transaction is aborted.\n";
	} else {
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(int num, double price) {
	using std::cerr;
	if (num < 0) {
		cerr << "Number of shares sold can't be negative. "
				<< "Transaction is aborted.\n";
	} else if (num > shares) {
		cerr << "You can't sell more than you have! "
				<< "Transaction is aborted.\n";
	} else {
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price) {
	share_val = price;
	set_tot();
}

//void Stock::show() const {
//	using std::cout;
//	using std::endl;
//	cout << "Company: " << company << "  Shares: " << shares << endl
//			<< "  Share Price: $" << share_val << "  Total Worth: $"
//			<< total_val << endl;
//}

std::ostream & operator<<(std::ostream & out, const Stock & st) {
	using std::endl;
	out << "Company: " << st.company << "  Shares: " << st.shares << endl
			<< "  Share Price: $" << st.share_val << "  Total Worth: $"
			<< st.total_val << endl;
	return out;
}

const Stock & Stock::topval(const Stock & s) const {
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}

} // namespace bclx123

static const int STKS = 4;
void bclx123test() {
	using std::cout;
	using std::ios_base;
	using namespace bclx123;

	// create an array of initialized objects
	Stock stocks[STKS] = { Stock("NanoSmart", 12, 20.0), Stock("Boffo Objects",
			200, 2.0), Stock("Monolithic Obelisks", 130, 3.25), Stock(
			"Fleep Enterprises", 60, 6.5) };

	cout.precision(2); // #.## format
	cout.setf(ios_base::fixed, ios_base::floatfield); // #.## format
	cout.setf(ios_base::showpoint); // #.## format

	cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < STKS; st++)
		cout << stocks[st];

	Stock top = stocks[0];
	for (st = 1; st < STKS; st++)
		top = top.topval(stocks[st]);
	cout << "\nMost valuable holding:\n";
	cout << top;
}

