// ***********************************************************
// Assembly Line Project
// CustomerOrder.h
// Matheus Fernando Leitao
// Date: 2019/03/20
// ***********************************************************
#ifndef SICT_CUSTOMER_ORDER_H
#define SICT_CUSTOMER_ORDER_H

#include <string>
#include <memory>
#include <iostream>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict {

	class CustomerOrder {

		struct ItemInfo {
			std::string name;
			int serialNumber;
			bool filledStatus;
		} info;

		std::string customerName = "";
		std::string productName = "";
		int numberItems = 0u;
		static size_t fieldWidth;
		ItemInfo* itemInfo = nullptr;
		Utilities util;

	public:
		CustomerOrder();
		CustomerOrder(const std::string&);
		~CustomerOrder();
		CustomerOrder(CustomerOrder&&);
		CustomerOrder& operator=(CustomerOrder&&);
		CustomerOrder(const CustomerOrder&) = delete;
		CustomerOrder& operator=(const CustomerOrder&) = delete;

		void fillItem(ItemSet& item, std::ostream& os);
		bool isFilled() const;
		bool isItemFilled(const std::string& item) const;
		std::string getNameProduct() const;
		void display(std::ostream& os, bool showDetail = false) const;
	};

}

#endif