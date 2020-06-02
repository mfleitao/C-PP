/**********************************************************
// Workshop 3: Classes and Privacy
// Version 2.1
// 2018/09/25
// Matheus Fernando Leitão
// ID: 148 300 171
**********************************************************/
#include <cstring>

namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account {

	private:
		//The family name on the account
		char familyName[sict::max_name_length + 1];

		//The given name on the account
		char givenName[sict::max_name_length + 1];

		//The social insurance number(SIN) on the account
		int sin;

	public:
		void set(const char* familyName, const char* givenName, int sin) {

			if (familyName != nullptr && familyName[0] != '\0' && 
				givenName != nullptr && givenName[0] != '\0' && sin > 0) {

				strcpy(this->familyName, familyName);
				strcpy(this->givenName, givenName);
				this->sin = sin;
			}

		}

		bool isEmpty() const;

		void display() const;
	};

}
