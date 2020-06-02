// ***********************************************************
// Assembly Line Project
// ItemSet.h
// Matheus Fernando Leitao
// Date: 2019/03/02
// ***********************************************************
#include <iostream>
#include <string>
#include "Utilities.h"

#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H

namespace sict {

	class ItemSet {
		std::string name;
		std::string description;
		unsigned int serialNumber;
		unsigned int quantity;
		Utilities util;

	public:
		ItemSet(const std::string& str);
		ItemSet(ItemSet&&);
		ItemSet& operator--();
		
		const std::string& getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getQuantity() const;
		const std::string& getDescription() const;

		void display(std::ostream& os, bool full) const;
	};
}

#endif