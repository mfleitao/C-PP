#include <iostream>
#include <cstring>
#include "IceCream.h"
using namespace std;

namespace sict {

	IceCream::IceCream() {
		this->numOfScoops = 0;
		this->flavour[0] = '\0';
	}

	IceCream::IceCream(int num, char* flavour) {
		this->set(num, flavour);
	}

	void IceCream::set(int num, char* flavour) {
		if (num > 0 && flavour != nullptr && flavour[0] != '\0') {
			if (num >= 1 && num <= 5) {
				this->numOfScoops = num;
				strncpy(this->flavour, flavour, MAX_LENGTH_FLAVOUR);
				this->flavour[MAX_LENGTH_FLAVOUR] = '\0';
			}
		}
		else {
			*this = IceCream();
		}
	}

	bool IceCream::isEmpty() const {
		return (numOfScoops > 0 && flavour != nullptr && flavour[0] != '\0');
	}

	void IceCream::display(std::ostream&) const {

	}

	IceCream IceCream::operator++(int num) {

	}

	IceCream& IceCream::operator-(int) const {

	}

}