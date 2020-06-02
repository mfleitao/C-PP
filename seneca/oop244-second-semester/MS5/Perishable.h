// ************************************************************
// Final Project Milestone 5
// Date: 27/11/2018
// Author: Matheus Leitao 
// ID: 148 300 171
// Description: OOP - Final Project Milestone 5
// ************************************************************
#ifndef AID_PERISHABLE_H_
#define AID_PERISHABLE_H_

#include <iostream>
#include "Good.h"
#include "Date.h"

namespace aid {
	
	class Perishable : public Good {
		Date date;

	public:
		Perishable();

		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);

		const Date& expiry() const;
	};

}

#endif 