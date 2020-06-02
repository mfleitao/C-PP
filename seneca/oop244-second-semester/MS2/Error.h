// -----------------------------------------------------------
// Final Project Milestone 2
// Version 1.0
// Date: 06/11/2018
// Author: Matheus Leitao 
// ID: 148 300 171
// Description: OOP - Final Project Milestone 2
// -----------------------------------------------------------
#ifndef AID_ERROR_H_
#define AID_ERROR_H_

#include <iostream>

namespace aid {

	class Error {

		char* messageError;
		int messageLength;

	public:

		explicit Error(const char* msg = nullptr);
		Error(const Error& er) = delete;
		Error& operator=(const Error& er) = delete;
		virtual ~Error();

		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
	};

	std::ostream& operator<<(std::ostream& os, const Error& er);
}

#endif