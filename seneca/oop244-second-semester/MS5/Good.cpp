// ************************************************************
// Final Project Milestone 5
// Date: 27/11/2018
// Author: Matheus Leitao 
// ID: 148 300 171
// Description: OOP - Final Project Milestone 5
// ************************************************************
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include "Good.h"
#include "Error.h"
using namespace std;

namespace aid {

	Good::Good(char type) {
		typeOfGood = type;
		goodSKU[0] = '\0';
		goodUnit[0] = '\0';
		goodName = nullptr;
		currentQuantity = 0;
		neededQuantity = 0;
		price = 0.0;
		taxableStatus = true;
		error = new Error(nullptr);
	}

	Good::Good(const char* skuNo, const char* nm, const char* unit, int qtyOnHand, bool taxed, double prc, int qtyNeeded) {
		// temp here

		name(nm);
		strncpy(goodSKU, skuNo, max_sku_length);
		goodSKU[max_sku_length] = '\0';

		strncpy(goodUnit, unit, max_unit_length);
		goodUnit[max_unit_length] = '\0';

		currentQuantity = qtyOnHand;
		taxableStatus = taxed;
		price = prc;
		neededQuantity = qtyNeeded;
		error = new Error(nullptr);
	}

	Good::Good(const Good& good) {
		name(good.name());
		strncpy(goodSKU, good.goodSKU, max_sku_length);
		strncpy(goodUnit, good.goodUnit, max_unit_length);
		currentQuantity = good.currentQuantity;
		neededQuantity = good.neededQuantity;
		price = good.price;
		taxableStatus = good.taxableStatus;
		error = good.error;
	}

	Good::~Good() {
		delete[] goodName;
		goodName = nullptr;
	}

	Good& Good::operator=(const Good& good) {
		if (this != &good) {
			name(good.name());
			strncpy(goodSKU, good.goodSKU, max_sku_length);
			strncpy(goodUnit, good.goodUnit, max_unit_length);
			currentQuantity = good.currentQuantity;
			neededQuantity = good.neededQuantity;
			price = good.price;
			taxableStatus = good.taxableStatus;
			error = good.error;
		}
		return *this;
	}

	void Good::name(const char* name) {
		goodName = nullptr;
		if (name != nullptr) {
			goodName = new char[max_name_length + 1];
			strncpy(goodName, name, max_name_length);
			goodName[max_name_length] = '\0';
		}
	}

	const char* Good::name() const {
		return (goodName != nullptr) ? goodName : nullptr;
	}

	const char* Good::sku() const {
		return goodSKU;
	}

	const char* Good::unit() const {
		return goodUnit;
	}

	bool Good::taxed() const {
		return taxableStatus;
	}

	double Good::itemPrice() const {
		return price;
	}

	double Good::itemCost() const {
		return (taxableStatus) ? price * tax_rate : price;
	}

	void Good::message(const char* errMsn) {
		if (errMsn != nullptr)
			error->message(errMsn);
	}

	bool Good::isClear() const {
		return error->isClear();
	}

	double Good::total_cost() const {
		return (currentQuantity * price) * tax_rate;
	}

	void Good::quantity(int noUnits) {
		if (noUnits > 0)
			currentQuantity = noUnits;
	}

	bool Good::isEmpty() const {
		return (!(goodSKU != nullptr && goodSKU[0] != '\0'));
	}

	int Good::qtyNeeded() const {
		return neededQuantity;
	}

	int Good::quantity() const {
		return currentQuantity;
	}

	char Good::type() const {
		return typeOfGood;
	}

	bool Good::operator>(const char* sku) const {
		return (strcmp(sku, goodSKU) == 1);
	}

	bool Good::operator>(const iGood& good) const {
		return (strcmp(good.name(), goodName) == 1);
	}

	int Good::operator+=(int noUnits) {
		if (noUnits > 0) {
			currentQuantity += noUnits;
		}
		return currentQuantity;
	}

	bool Good::operator==(const char* sku) const {
		return (strcmp(goodSKU, sku) == 0);
	}

	std::fstream& Good::store(std::fstream& file, bool newLine) const {
		if (!isEmpty()) {
			file << type() << COMMA;
			file << sku() << COMMA;
			file << name() << COMMA;
			file << unit() << COMMA;
			file << (taxed() ? 1 : 0) << COMMA;
			file << itemPrice() << COMMA;
			file << quantity() << COMMA;
			file << qtyNeeded();
			if (newLine) file << '\n';
		}
		return file;
	}

	std::fstream& Good::load(std::fstream& file) {

		string skuStr;
		getline(file, skuStr, COMMA);
		char* sku = new char[skuStr.length() + 1];
		strncpy(sku, skuStr.c_str(), skuStr.length());
		sku[skuStr.length()] = '\0';
		if (file.fail()) {
			*this = Good();
			file.clear();
			file.close();
			return file;
		}

		string nameStr;
		getline(file, nameStr, COMMA);
		char* name = new char[nameStr.length() + 1];
		strncpy(name, nameStr.c_str(), nameStr.length());
		name[nameStr.length()] = '\0';
		if (file.fail()) {
			*this = Good();
			file.clear();
			file.close();
			return file;
		}

		string unitStr;
		getline(file, unitStr, COMMA);
		char* unit = new char[unitStr.length() + 1];
		strncpy(unit, unitStr.c_str(), unitStr.length());
		unit[unitStr.length()] = '\0';
		if (file.fail()) {
			*this = Good();
			file.clear();
			file.close();
			return file;
		}

		string taxedStr;
		getline(file, taxedStr, COMMA);
		char* taxed = new char[taxedStr.length() + 1];
		strncpy(taxed, taxedStr.c_str(), taxedStr.length());
		taxed[taxedStr.length()] = '\0';
		bool isTaxed = (taxed[0] == '1');
		if (file.fail()) {
			*this = Good();
			file.clear();
			file.close();
			return file;
		}

		string priceStr;
		getline(file, priceStr, COMMA);
		char* priceChar = new char[priceStr.length() + 1];
		strncpy(priceChar, priceStr.c_str(), priceStr.length());
		double price = atof(priceChar);
		if (file.fail()) {
			*this = Good();
			file.clear();
			file.close();
			return file;
		}

		string qtyStr;
		getline(file, qtyStr, COMMA);
		char* qtyChar = new char[qtyStr.length() + 1];
		strncpy(qtyChar, qtyStr.c_str(), qtyStr.length());
		int qty = atoi(qtyChar);
		if (file.fail()) {
			*this = Good();
			file.clear();
			file.close();
			return file;
		}

		string qtyNeededStr;
		getline(file, qtyNeededStr, COMMA);
		char* qtyNeededChar = new char[qtyNeededStr.length() + 1];
		strncpy(qtyNeededChar, qtyNeededStr.c_str(), qtyNeededStr.length());
		int qtyNeeded = atoi(qtyNeededChar);
		if (file.fail()) {
			*this = Good();
			file.clear();
			file.close();
			return file;
		}

		Good tempObj(sku, name, unit, qty, isTaxed, price, qtyNeeded);
		*this = tempObj;
		return file;
	}

	std::ostream& Good::write(std::ostream& os, bool linear) const {
		if (!isClear()) {
			os << error->message();
		}
		else {
			if (!isEmpty()) {
				if (linear) {
					os.setf(ios::left);
					os.width(max_sku_length);
					os << sku() << BAR;
					os.width(20);
					os << name() << BAR;
					os.width(7);
					os.unsetf(ios::left);
					os << fixed << setprecision(2) << itemCost() << BAR;
					os.width(4);
					os << quantity() << BAR;
					os.width(10);
					os.setf(ios::left);
					os << unit() << BAR;
					os.width(4);
					os.unsetf(ios::left);
					os << qtyNeeded() << BAR;
				}
				else {
					string nameOutput(name());
					os << " Sku: " << sku() << endl;
					os << " Name (no spaces): " << nameOutput.substr(0, 73) << endl;
					os << " Price: " << fixed << setprecision(2) << price << endl;
					os << " Price after tax: ";
					if (!taxed()) os << " N/A" << endl;
					else os << fixed << setprecision(2) << itemCost() << endl;
					os << " Quantity on Hand: " << quantity() << " " << unit() << endl;
					os << " Quantity needed: " << qtyNeeded();
					if (type() == 'N') cin.ignore(2000, '\n');
				}
			}
		}
		return os;
	}

	std::istream& Good::read(std::istream& is) {
		error->clear();

		cout << " Sku: ";
		char skuInput[max_sku_length + 1];
		is >> skuInput;

		cout << " Name (no spaces): ";
		char nameInput[max_name_length + 1];
		is >> nameInput;

		cout << " Unit: ";
		char unitInput[max_unit_length + 1];
		is >> unitInput;

		cout << " Taxed? (y/n): ";
		char taxedInput;
		is >> taxedInput;
		if (taxedInput != 'Y' && taxedInput != 'y' && taxedInput != 'N' && taxedInput != 'n') {
			message("Only (Y)es or (N)o are acceptable");
			is.setstate(std::ios::failbit);
			return is;
		}
		bool isTaxed = (taxedInput != 'N' && taxedInput != 'n');

		cout << " Price: ";
		double priceInput;
		is >> priceInput;
		if (is.fail()) {
			message("Invalid Price Entry");
			return is;
		}

		cout << " Quantity on hand: ";
		int quantity;
		is >> quantity;
		if (is.fail()) {
			message("Invalid Quantity Entry");
			return is;
		}

		cout << " Quantity needed: ";
		int qtyNeeded;
		is >> qtyNeeded;
		if (is.fail()) {
			message("Invalid Quantity Needed Entry");
			return is;
		}

		Good tmp(skuInput, nameInput, unitInput, quantity, isTaxed, priceInput, qtyNeeded);
		*this = tmp;
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const iGood& good) {
		good.write(os, true);
		return os;
	}

	std::istream& operator>>(std::istream& is, iGood& good) {
		good.read(is);
		return is;
	}

	double operator+=(double& totalCost, const iGood& good) {
		totalCost += good.total_cost();
		return totalCost;
	}

}