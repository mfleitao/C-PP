//**********************************************************************
// OOP244 Workshop 9 - Function Templates
// Version: 1.0
// 2018/11/20
// Matheus Fernando Leitao
// ID: 148300171
// Description: in_lab
//**********************************************************************
#include <iostream>
#include <cstring>
#include "Data.h"

namespace sict {

	// answers outputs statistics for visual validation of data
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		int pop = max(population, n) - min(population, n);
		std::cout << "Population change from 2000 to 2004 is ";
		std::cout.precision(2);
		std::cout << std::fixed << ((double)pop / 1000000) << " million" << std::endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		bool isCrimeIncreased = false;
		for (int i = 0; i < n; i++) 
			isCrimeIncreased = (violentCrime[i + 1] > violentCrime[i]);
		std::cout << "Violent Crime trend is " << ((isCrimeIncreased) ? "up" : "down") << std::endl;

		// Q3 print the GTA number accurate to 0 decimal places
		std::cout << "There are ";
		std::cout.precision(2);
		std::cout << std::fixed << average(grandTheftAuto, n);
		std::cout << " million Grand Theft Auto incidents on average a year" << std::endl;

		// Q4. Print the min and max violentCrime rates
		std::cout << "The Minimum Violent Crime rate was ";
		std::cout << static_cast<int>(min(violentCrimeRate, n)) << std::endl;

		std::cout << "The Maximum Violent Crime rate was ";
		std::cout << static_cast<int>(max(violentCrimeRate, n)) << std::endl;

	}

}