// ***********************************************************
// Assembly Line Project
// Station.h
// Matheus Fernando Leitao
// Date: 2019/04/02
// ***********************************************************
#ifndef SICT_STATION_H
#define SICT_STATION_H

#include <iostream>
#include <string>
#include <queue>
#include "CustomerOrder.h"
#include "ItemSet.h"

namespace sict {

	class Station {
		std::queue<CustomerOrder> orders;
		ItemSet itemset;

	public:
		Station(const std::string&);
		void display(std::ostream& os) const;
		void fill(std::ostream& os);
		const std::string& getName() const;
		bool hasAnOrderToRelease() const;
		Station& operator--();
		Station& operator+=(CustomerOrder&& order);
		bool pop(CustomerOrder& ready);
		void validate(std::ostream& os) const;

		Station(Station &&) = delete;
		Station & operator=(Station &&) = delete;
		Station(const Station &) = delete;
		Station & operator=(const Station &) = delete;
	};
}

#endif
