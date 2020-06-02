/***********************************************************
// OOP244 Workshop 6: Class with a resource
// File Contact.cpp
// Version 1.0
// Date 2018-10-31
// Author Valentin-Gabriel Vlad
// Description
// Contains the Contact class member function definitions 
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/

#include <iostream>
#include"Contact.h"
#include"string.h"

using namespace std;

namespace sict
{
	Contact::Contact()
	{
		name[0]='\0';
		phoneList = nullptr;
		noOfPhoneNumbers = 0;
	}

	int Contact::noValidPhones(const long long* cPhoneList, int NoOfNo)
	{
		int increment = 0;
		for (int i = 0; i < NoOfNo; i++)
		{
			if (phoneValidation(cPhoneList[i]))
			{
				increment++;
			}
		} return increment;
	}
	//long long* Contact::removeInvalidPhones(const long long* cPhoneList, int NoOfNo)
	//{		
		
		
	//};

	
	
	bool Contact::phoneValidation(long long cPhoneList) 
	{
		
		//bool validPhone = (cPhoneList != nullptr || NoOfNo==0 ) ? true : false;
		bool oneValid = false;
		
			
				long long phoneNumber = cPhoneList;
				int countryCode = 0, areaCode = 0, phonenumber = 0;
				
				countryCode = phoneNumber / 10000000000;
				areaCode = (phoneNumber % 10000000000) / 10000000;
				phonenumber = (phoneNumber % 10000000000) % 10000000;
				if (countryCode < 99 && countryCode>0 &&
					countryCode % 1 == 0 && areaCode > 99 &&
					areaCode < 1000 && phonenumber > 999999 &&
					phonenumber < 10000000)
				{
					oneValid = true;
				}
				return oneValid;
			}
	
	// TODO: implement the three-argument constructor
	
	Contact::~Contact()
	{
		delete[] phoneList;
	}

	Contact::Contact(const char cName[MAX_CHAR+1],const long long* cPhoneList, int NoOfNo) 
	{
		if (cName==nullptr || strncmp(cName, "", MAX_CHAR+1)==0)
		{	
			*this = Contact();
			
		}
		else
		{
			if (NoOfNo == 0)
			{

				strncpy(name, cName, MAX_CHAR + 1);
				name[MAX_CHAR] = '\0';
				phoneList = nullptr;
				noOfPhoneNumbers = 0;
			}
			else
			{
				strncpy(name, cName, MAX_CHAR + 1);
				name[MAX_CHAR] = '\0';
				noOfPhoneNumbers = noValidPhones(cPhoneList, NoOfNo);
				
					phoneList = new long long[noOfPhoneNumbers];
					// copy resource data
					int j = 0;
					while (j < noOfPhoneNumbers)
					{
						for (int i = 0; i < NoOfNo; i++)
						{
							if (phoneValidation(cPhoneList[i]))
							{
								phoneList[j] = cPhoneList[i];
								j++;
							}
						}
					}
			}
			
		}
		
		

	}
	
	 
	// TODO: implement the display query
	void Contact::display() const
	{		
		if (!isEmpty())
		{
			if(noOfPhoneNumbers == 0){
				cout  << name << endl;
			}
			else
			{
				cout << name << endl;
				
				for (int i = 0; i < noOfPhoneNumbers-1; i++)
				{
					 cout<<
						"(+" << phoneList[i] / 10000000000 << ") " <<
						(phoneList[i] % 10000000000) / 10000000 << " " <<
						((phoneList[i] % 10000000000) % 10000000) / 10000 << "-" <<
						 
						((phoneList[i] % 10000000000) % 10000000) % 10000 << endl;
				}
				cout <<
					"(+" << phoneList[noOfPhoneNumbers-1] / 10000000000 << ") " <<
					(phoneList[noOfPhoneNumbers - 1] % 10000000000) / 10000000 << " " <<
					((phoneList[noOfPhoneNumbers - 1] % 10000000000) % 10000000) / 10000 << "-" <<
					"000" <<
					((phoneList[noOfPhoneNumbers - 1] % 10000000000) % 10000000) % 10000 << endl;
			
			}
		}
		else
		{
			cout << "Empty contact!" << endl;
		}
	}
	// TODO: implement the isEmpty query
	bool Contact::isEmpty() const
	{
		if (name == nullptr || name[0]=='\0' || strncmp(name, "", MAX_CHAR)==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
}