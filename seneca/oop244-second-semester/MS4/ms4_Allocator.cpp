// ************************************************************
// Final Project Milestone 4
// Date: 24/11/2018
// Author: Matheus Leitao 
// ID: 148 300 171
// Description: OOP - Final Project Milestone 4
// ************************************************************
#include "ms4_MyGood.h"

namespace aid {

	iGood* CreateGood() {
		return new MyGood("Good");
	}
	iGood* CreatePerishable() {
		return new MyGood("Perishable");
	}
}