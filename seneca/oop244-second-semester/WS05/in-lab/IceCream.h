
#include <iostream>

namespace sict {
	
	const int MAX_LENGTH_FLAVOUR = 18;

	class IceCream {

		int numOfScoops;
		char flavour[MAX_LENGTH_FLAVOUR + 1];

	public:

		IceCream();
		IceCream(int, char*);

		void set(int, char*);
		bool isEmpty() const;
		void display(std::ostream&) const;
		IceCream operator++(int);
		IceCream& operator-(int) const;

	}

}