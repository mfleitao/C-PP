// ***********************************************************
// Workshop 7 - STL Algorithms
// iProduct.h
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

		T mean() const {
			T total = 0;
			total += accumulate(dataList.begin(), dataList.end(), static_cast<T>(0), [](auto& v1, auto& v2) {
				return v1 + v2.second;
			});
			return (total / dataList.size());
		}

		T sigma() const {
			vector<T> yValues;
			for (auto& i : dataList)
				yValues.push_back(get<1>(i));

			T total = 0;
			for_each(yValues.begin(), yValues.end(), [&](T& data) {
				total += pow(data - mean(), 2);
			});
			return sqrt(total / (yValues.size() - 1));
		}

	public:
		DataTable(ifstream& file) {
			if (file.is_open()) {
				T x = 0, y = 0;
				string line = {};
				do {
					file >> x >> y;
					dataList.push_back(make_pair(x, y));
				} while (getline(file, line));
			}
		}

		void displayData(ostream& os) {
			os << "Data Values\n------------" << endl;
			os << setw(FW) << "x" << setw(FW) << "y" << endl;
			for (auto& i : dataList) {
				os << fixed;
				os << setprecision(ND) << setw(FW) << right << get<0>(i);
				os << setprecision(ND) << setw(FW) << get<1>(i) << endl;
			}
		}

		void displayStatistics(ostream& os) {
			os << "\nStatistics\n----------" << endl;
			os << fixed << setprecision(ND) << "  y mean    =  " << mean() << endl;
			os << fixed << setprecision(ND) << "  y sigma   =   " << sigma() << endl;
		}
	};

}
#endif