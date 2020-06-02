// ***********************************************************
// Workshop 6 - STL Containers
// Product.cpp
// Matheus Fernando Leitao
// Date: 2019/03/12
// ***********************************************************
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "Product.h"
using namespace std;

extern int FW;

namespace sict {

	// non-arg constructor: leave object in safe empty state
	Product::Product() : productNumber{ 0 }, cost{ 0.0 } {}

	// two-arg constructor: initializes members of product
	Product::Product(int productNumber, double cost) : productNumber{ productNumber }, cost{ cost } { }

	// returns the price of product
	double Product::price() const {
		return cost;
	}

	// inserts the output of current object into a ostream object
	void Product::display(ostream & os) const {
		os << setw(FW) << productNumber << setw(FW) << cost;
	}

	// helper which inserts data into a ostream object
	ostream& operator<<(ostream& os, const iProduct& product) {
		product.display(os);
		return os;
	}

	// non-arg constructor: safe empty state
	TaxableProduct::TaxableProduct() {}

	// 3-argument constructor that creates the object - TaxableProduct contains a Product
	TaxableProduct::TaxableProduct(int productNumber, double price, char status) : Product(productNumber, price) {
		taxRate = (status == 'H') ? 0.13 : 0.08;
	}

	// Returns the price with tax (net price) of the product
	double TaxableProduct::price() const {
		return Product::price() * (1 + taxRate);
	}

	// Displays the information about the product with tax status
	void TaxableProduct::display(std::ostream& os) const {
		Product::display(os);
		std::string tax = (taxRate == 0.13) ? " HST" : " PST";
		os << tax;
	}

	// reads a single record from file object file and then allocates memory for a product in the hierarchy
	iProduct* readRecord(ifstream& file) {
		//iProduct* product = nullptr;
		double cost = 0;
		int productNumber = 0;
		char tax = '\0';
		string ln = {};
		getline(file, ln, '\n');
		stringstream data(ln);
		if (count(ln.begin(), ln.end(), ' ') == 2) {
			data >> productNumber >> cost >> tax;
			return new TaxableProduct(productNumber, cost, tax);
		}
		else {
			data >> productNumber >> cost;
			return new Product(productNumber, cost);
		}
		//return product;
	}

}