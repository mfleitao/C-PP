// ***********************************************************
// Assembly Line Project
// Station.cpp
// Matheus Fernando Leitao
// Date: 2019/04/02
// ***********************************************************
#include <iostream>
#include <string>
#include <utility>
#include "Station.h"
using namespace std;

namespace sict {

	Station::Station(const string& str) : itemset(str) { }

	void Station::display(ostream& os) const {
		itemset.display(os, false);
	}

	void Station::fill(ostream& os) {
		if (!orders.empty())
			orders.back().fillItem(itemset, os);
	}

	const string& Station::getName() const {
		return itemset.getName();
	}

	bool Station::hasAnOrderToRelease() const {
		if (!orders.empty())
			return (orders.front().isItemFilled(itemset.getName()) || itemset.getQuantity() == 0);
		return false;
	}

	Station& Station::operator--() {
		--itemset;
		return *this;
	}

	Station& Station::operator+=(CustomerOrder&& order) {
		orders.push(move(order));
		return *this;
	}

	bool Station::pop(CustomerOrder& ready) {
		bool out = false;
		if (!orders.empty()) {
			out = orders.front().isFilled();
			ready = move(orders.front());
			orders.pop();
		}
		return out;
	}

	void Station::validate(ostream& os) const {
		os << " getName(): " << itemset.getName() << endl;
		os << " getSerialNumber(): " << itemset.getSerialNumber() << endl;
		os << " getQuantity(): " << itemset.getQuantity() << endl;
	}

};