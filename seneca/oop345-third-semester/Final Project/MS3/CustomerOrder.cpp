// ***********************************************************
// Assembly Line Project
// CustomerOrder.cpp
// Matheus Fernando Leitao
// Date: 2019/03/20
// ***********************************************************
#include <iomanip>
#include <iostream>
#include "Utilities.h"
#include "CustomerOrder.h"
using namespace std;

namespace sict {

	size_t CustomerOrder::fieldWidth = 0;

	CustomerOrder::CustomerOrder() { }

	CustomerOrder::CustomerOrder(const std::string& str) {
		size_t pos = 0u, aux_pos = 0u;
		try {
			customerName = util.extractToken(str, pos);
			if (fieldWidth < customerName.size())
				fieldWidth = customerName.size();

			productName = util.extractToken(str, pos);
			aux_pos = pos;
			if (str.size() < pos) throw "Error - There is no item requested for this Order";

			while (pos < str.size()) {
				string dummy = util.extractToken(str, pos);
				numberItems++;
			}
			itemInfo = new ItemInfo[numberItems];
			pos = aux_pos;

			for (int i = 0; i < numberItems; i++) {
				itemInfo[i].name = util.extractToken(str, pos);
				itemInfo[i].filledStatus = false;
				itemInfo[i].serialNumber = 0;
			}
		}
		catch (string msg) {
			throw "Error - "+ msg;
		}
	}

	CustomerOrder::~CustomerOrder() {
		delete[] itemInfo;
	}

	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {
		for (int i = 0; i < numberItems; i++) {
			if (item.getName() == itemInfo[i].name) {
				if (item.getQuantity() == 0) {
					os << " Unable to fill ";
					os << getNameProduct() << "[" << itemInfo[i].name << "][" << itemInfo[i].serialNumber << "]";
					os << " out of stock" << endl;
				}
				else {
					if (itemInfo[i].filledStatus) {
						os << " Unable to fill ";
						os << getNameProduct() << "[" << itemInfo[i].name << "][" << itemInfo[i].serialNumber << "]";
						os << " already filled" << endl;
					}
					else {
						itemInfo[i].filledStatus = true;
						itemInfo[i].serialNumber = item.getSerialNumber();
						item.operator--();
						os << " Filled ";
						os << getNameProduct() << "[" << itemInfo[i].name << "][" << itemInfo[i].serialNumber << "]" << endl;
					}
				}
	
			}
		}
	}

	bool CustomerOrder::isFilled() const {
		for (int i = 0; i < numberItems; i++)
			if (!itemInfo[i].filledStatus)
				return false;
		return true;
	}

	string CustomerOrder::getNameProduct() const {
		return customerName + " [" + productName + "]";
	}

	bool CustomerOrder::isItemFilled(const string& itemName) const {
		for (int i = 0; i < numberItems; i++) {
			if (itemInfo[i].name == itemName) {
				if (!itemInfo[i].filledStatus)
					return false;
			}
		}
		return true;
	}

	void CustomerOrder::display(std::ostream& os, bool showDetail) const {
		os << left << setw(fieldWidth + 1) << customerName << +"[" + productName + "]" << endl;
		if (!showDetail) {
			for (int i = 0; i < numberItems; i++)
				os << setw(fieldWidth + 1) << " " << itemInfo[i].name << endl;
		}
		else {
			for (int i = 0; i < numberItems; i++) {
				os << setw(fieldWidth + 1) << " " << "[" << itemInfo[i].serialNumber << "] " << itemInfo[i].name;
				os << " - " << (itemInfo[i].filledStatus == 0 ? "MISSING" : "FILLED") << endl;
			}
		}
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) { 
		*this = std::move(src); 
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src)  {
		if (this != &src) {
			delete[] itemInfo;
			customerName = src.customerName;
			productName = src.productName;
			itemInfo = src.itemInfo;
			numberItems = src.numberItems;

			src.itemInfo = nullptr;
			src.numberItems = 0;
			src.customerName.clear();
			src.productName.clear();
		}
		return *this;
	}

};