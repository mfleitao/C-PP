// ***********************************************************
// Workshop 6 - STL Containers
// Product.h
// Matheus Fernando Leitao
// Date: 2019/03/12
// ***********************************************************
#include "iProduct.h"

#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H

namespace sict {

	class Product : public iProduct {
		int productNumber;
		double cost;

	public:
		Product();
		explicit Product(int, double);
		double price() const override;
		void display(std::ostream& os) const;
	};

	class TaxableProduct : public Product {
		double taxRate;

	public:
		enum class TaxEnum { HST = 13, PST = 8 };
		TaxableProduct();
		TaxableProduct(int, double, char);
		double price() const;
		void display(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);
}

#endif