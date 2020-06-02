// ***********************************************************
// Workshop 7 - STL Algorithms
// DataTable.h
// Matheus Fernando Leitao
// Date: 2019/03/18
// ***********************************************************
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

extern int FW;
extern int ND;

namespace sict {

	template<class T> class DataTable {

		vector<pair<T, T>> dataList;

		// calculates the average of values in sample
		T mean() const {
			pair<T, T> xyPair = sumPair();
			return get<1>(xyPair) / dataList.size();
		}

		// calculates the sum of the X and Y then returns a pair object of them
		pair<T, T> sumPair() const {
			T x = 0, y = 0;
			x += accumulate(dataList.begin(), dataList.end(), static_cast<T>(0), [](auto& a, auto& b) { 
				return a + b.first; 
			});
			y += accumulate(dataList.begin(), dataList.end(), static_cast<T>(0), [](auto& a, auto& b) { 
				return a + b.second; 
			});
			return make_pair(x, y);
		}

		// returns X and Y coordinates by a pair object
		pair<vector<T>, vector<T>> getXYPair() const {
			vector<T> x, y;
			for (auto& i : dataList) {
				x.push_back(get<0>(i));
				y.push_back(get<1>(i));
			}
			return make_pair(x, y);
		}

		// calculates the sample standard deviation 
		T sigma() const {
			T total = 0;
			vector<T> y = get<1>(getXYPair());
			for_each(y.begin(), y.end(), [&](T& size) {
				total += pow(size - mean(), 2);
			});
			return sqrt(total / (y.size() - 1));
		}

		// calculates the median (the middle number in the sorted set of the values)
		T median() const {
			vector<T> y = get<1>(getXYPair());
			sort(y.begin(), y.end());
			return y[y.size() / 2];
		}

		// calculates the slope of the line in the x-y plane
		T slope() const {
			T xySum = 0;
			for_each(dataList.begin(), dataList.end(), [&](auto& i) { 
				xySum += i.first * i.second; 
			});
			T sumSquaredX = 0;
			vector<T> x = get<0>(getXYPair());
			for_each(x.begin(), x.end(), [&](auto& i) { 
				sumSquaredX += i * i; 
			});

			size_t size = dataList.size();
			pair<T, T> xyPairSum = sumPair();
			T sumX = get<0>(xyPairSum);
			T sumY = get<1>(xyPairSum);
			T objNumerator = (size * xySum) - (sumX * sumY);
			T objDenominator = ((size * sumSquaredX) - (sumX * sumX));

			return (objNumerator / objDenominator);
		}

		// calculates the intercept value
		T intercept() const {
			pair<T, T> xyPairSum = sumPair();
			T sumX = get<0>(xyPairSum);
			T sumY = get<1>(xyPairSum);
			return (sumY - (slope() * sumX)) / dataList.size();
		}

	public:

		// single-arg constructor which gets the lines from the file then push them into a vector
		DataTable(ifstream& file) {
			bool readFile = true;
			if (file) {
				T x = 0, y = 0;
				do {
					if (file >> x >> y) dataList.push_back(make_pair(x, y));
					else readFile = false;
				} while (readFile);
			}
		}

		// inserts the data into an ostream object which displays the x-y data
		void displayData(ostream& os) {
			os << "Data Values\n------------" << endl;
			os << setw(FW) << "x" << setw(FW) << "y" << endl;
			for (auto& i : dataList) {
				os << fixed;
				os << setprecision(ND) << setw(FW) << right << get<0>(i);
				os << setprecision(ND) << setw(FW) << get<1>(i) << endl;
			}
		}

		// inserts the data into an ostream object which displays the statistics for the current object
		void displayStatistics(ostream& os) {
			os << "\nStatistics\n----------" << endl;
			os << fixed << setprecision(ND) << "  y mean    = " << setw(FW) << mean() << endl;
			os << fixed << setprecision(ND) << "  y sigma   = " << setw(FW) << sigma() << endl;
			os << fixed << setprecision(ND) << "  y median  = " << setw(FW) << median() << endl;
			os << fixed << setprecision(ND) << "  slope     = " << setw(FW) << slope() << endl;
			os << fixed << setprecision(ND) << "  intercept = " << setw(FW) << intercept() << endl;
		}

	};
}
#endif 