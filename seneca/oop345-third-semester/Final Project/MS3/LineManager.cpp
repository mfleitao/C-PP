// ***********************************************************
// Assembly Line Project
// LineManager.cpp
// Matheus Fernando Leitao
// Date: 2019/04/02
// ***********************************************************
#include <iostream>
#include <vector>
#include <utility>
#include "CustomerOrder.h"
#include "Station.h"
#include "LineManager.h"
using namespace std;

namespace sict {

	LineManager::LineManager(vector<Station*>& sptr, vector<size_t>& indexes,
		vector<CustomerOrder>& orders, size_t begindex, ostream& os) :
		line(sptr), indexes(indexes), orderNumber(orders.size()), start(begindex) {

		for (size_t i = 0u; i < orders.size(); i++)
			ordersToBeFilled.push_front(move(orders[i]));

		lastStation = begindex;
		for (size_t i = 0u; i < indexes.size(); i++) {
			if (indexes[lastStation] < line.size())
				lastStation = indexes[lastStation];
		}
	}

	void LineManager::display(ostream& os) const {
		os << "COMPLETED ORDERS" << endl;
		for (size_t i = 0u; i < completedOrders.size(); i++)
			completedOrders[i].display(os, true);
		os << endl;
		os << "INCOMPLETE ORDERS" << endl;
		for (size_t i = 0u; i < incompletedOrders.size(); i++)
			incompletedOrders[i].display(os, true);
	}

	bool LineManager::run(ostream& os) {
		if (!ordersToBeFilled.empty()) {
			*line[start] += move(ordersToBeFilled.back());
			ordersToBeFilled.pop_back();
		}
		for (size_t i = 0; i < line.size(); i++)
			line[i]->fill(os);

		for (size_t i = 0; i < line.size(); i++) {
			if (line[i]->hasAnOrderToRelease()) {
				CustomerOrder custOrder;
				bool done = line[i]->pop(custOrder);
				os << " --> " << custOrder.getNameProduct() << " moved from " << line[i]->getName() << " to ";
				if (i != lastStation) {
					os << line[indexes[i]]->getName() << endl;
					*line[indexes[i]] += move(custOrder);
				}
				else if (done) {
					os << "Completed Set" << endl;
					completedOrders.push_back(move(custOrder));
				}
				else {
					os << "Incomplete Set" << endl;
					incompletedOrders.push_back(move(custOrder));
				}
			}
		}
		return ((incompletedOrders.size() + completedOrders.size()) == orderNumber);
	}

}