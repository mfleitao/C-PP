// ***********************************************************
// Assembly Line Project
// LineManager.h
// Matheus Fernando Leitao
// Date: 2019/04/02
// ***********************************************************
#ifndef SICT_LINE_MANAGER_H
#define SICT_LINE_MANAGER_H

#include <iostream>
#include <vector>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace sict {

	class LineManager {
		std::deque<CustomerOrder> completedOrders;
		std::deque<CustomerOrder> incompletedOrders;
		std::deque<CustomerOrder> ordersToBeFilled;
		std::vector<Station*> line;
		std::vector<size_t> indexes;
		const size_t orderNumber;
		const size_t start;
		size_t lastStation;

	public:
		LineManager(std::vector<Station*>& sptr, std::vector<size_t>& indexes, std::vector<CustomerOrder>& orders, 
			size_t begindex, std::ostream& os);

		void display(std::ostream& os) const;
		bool run(std::ostream& os);

		LineManager(LineManager &&) = delete;
		LineManager & operator=(LineManager &&) = delete;
		LineManager(const LineManager &) = delete;
		LineManager & operator=(const LineManager &) = delete;
	};

}

#endif