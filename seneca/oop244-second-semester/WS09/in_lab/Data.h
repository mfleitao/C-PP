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

namespace sict {

	const int LARGEST_NUMBER  = 1000000000; 
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data
	template<typename T>
	T max(const T* data, int n) {
		T max = SMALLEST_NUMBER;
		for (int i = 0; i < n; i++)
			if (max < data[i]) max = data[i];
		return max;
	}

	// min returns the smallest item in data
	template<typename T>
	T min(const T* data, int n) {
		T min = LARGEST_NUMBER;
		for (int i = 0; i < n; i++)
			if (min > data[i]) min = data[i];
		return min;
	}

	// sum returns the sum of n items in data
	template<typename T>
	T sum(const T* data, int n) {
		T sum = 0;
		for (int i = 0; i < n; i++)
			sum += data[i];
		return sum;
	}

	// average returns the average of n items in data
	template<typename T>
	double average(const T* data, int n) {
		int s = sum(data, n);
		double avg = ((double)s / n);
		return avg / 1000000;
	}

	// display inserts n items of data into std::cout
	template<typename T>
	void display(const char* name, const T* data, int n) {
		std::cout.width(20);
		std::cout << name;
		for (int i = 0; i < n; i++) {
			std::cout.width(COLUMN_WIDTH);
			std::cout << data[i];
		}
		std::cout << std::endl;
	}

	template<typename T>
	bool read(std::istream& input, T* data, int n) {
		for (int i = 0; i < n; i++) {
			input.ignore();
			input >> data[i];
			if (input.fail())
				return false;
		}
		return true;
	}

	template<typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();
		if (ok) {
			input.get(rowname, 2000, ',');
			if (std::strcmp(rowname, name) != 0) {
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}
		if (ok) // read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n);

}

