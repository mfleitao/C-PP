// ***********************************************************
// Assembly Line Project
// ItemSet.cpp
// Matheus Fernando Leitao
// Date: 2019/03/02
// ***********************************************************
#include <iomanip>
#include <iostream>
#include "Utilities.h"
#include "ItemSet.h"
using namespace std;

namespace sict {

	ItemSet::ItemSet(const std::string& str) {
		size_t nextPosition = 0u;
		try {
			name = util.extractToken(str, nextPosition);
			serialNumber = stoul(util.extractToken(str, nextPosition));
			quantity = stoi(util.extractToken(str, nextPosition));
			description = util.extractToken(str, nextPosition);

			if (util.getFieldWidth() < name.length())
				util.setFieldWidth(name.length());
		}
		catch (string msg) {
			throw "Error - " + msg;
		}
	}

	ItemSet::ItemSet(ItemSet&& src) {
		if (this != &src) {
			name = src.name;
			description = src.description;
			serialNumber = src.serialNumber;
			quantity = src.quantity;
	
			src.name = "";
			src.description = "";
			src.serialNumber = 0;
			src.quantity = 0;
		}
	}

	const std::string& ItemSet::getName() const {
		return name;
	}

	const unsigned int ItemSet::getSerialNumber() const {
		return serialNumber;
	}

	const unsigned int ItemSet::getQuantity() const {
		return quantity;
	}

	const std::string& ItemSet::getDescription() const {
		return description;
	}

	ItemSet& ItemSet::operator--() {
		quantity--;
		serialNumber++;
		return *this;
	}

	void ItemSet::display(std::ostream& os, bool full) const {
		//if (full) {
			os << left << setw(util.getFieldWidth()) << name;
			os << " [" << setw(5) << serialNumber << "]";
			os << " Quantity " << setw(3) << quantity << right;
			os << " Description: " << description << endl;
		//}
	}

};

