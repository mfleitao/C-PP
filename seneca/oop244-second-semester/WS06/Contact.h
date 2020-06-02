/***********************************************************
// OOP244 Workshop 6: Class with a resource
// File Contact.h
// Version 1.0
// Date 2018-10-31
// Author Valentin-Gabriel Vlad
// Description
// Contains the Contact class definition and functions prototypes in the sict namespace
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/


#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H



namespace sict
{
	
	static const int MAX_CHAR = 20;

	class Contact
	{
		
		char name[MAX_CHAR+1];
		long long* phoneList;
		int noOfPhoneNumbers;

		//long long* removeInvalidPhones(const long long*, int);
		int noValidPhones(const long long* cPhoneList, int NoOfNo);
		bool phoneValidation(long long cPhoneList);
		//int countryCode( long long PhoneNumber);
		//int areaCode( long long PhoneNumber);
		//int phoneNumber( long long PhoneNumber);
	
	public:
	
		Contact();
		Contact(const char cName[MAX_CHAR + 1], const long long* cPhoneList, int NoOfNo);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};
	
}
#endif