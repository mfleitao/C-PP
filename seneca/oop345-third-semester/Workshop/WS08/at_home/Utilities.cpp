// Workshop 8 - Smart Pointers
// Utilities.cpp
// Chris Szalwinski from Cornel Barna
// 2019/03/17

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"
using namespace std;

namespace sict {
	
	// combines description and price to create a product object which is put into a list
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					Product* prd = new Product(desc[i].desc, price[j].price);
					prd->validate();
					priceList += prd;
					delete prd;
				}
			}
		}
		return priceList;
	}

	// combines description and price to create a product object which is put into a list
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					unique_ptr<Product> prd { 
						new Product(desc[i].desc, price[j].price) 
					};
					prd->validate();
					priceList += prd;
				}
			}
		}
		return priceList;
	}

}