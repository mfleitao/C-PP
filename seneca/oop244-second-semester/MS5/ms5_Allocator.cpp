// ************************************************************
// Final Project Milestone 5
// Date: 27/11/2018
// Author: Matheus Leitao 
// ID: 148 300 171
// Description: OOP - Final Project Milestone 5
// ************************************************************
#include "Good.h"
#include "Perishable.h"

namespace aid {

	// creates an empty good
	//
	iGood* CreateGood() {
		return new Good();
	}

	// creates an empty perishable good
	//
	iGood* CreatePerishable() {
		return new Perishable();
	}
}
