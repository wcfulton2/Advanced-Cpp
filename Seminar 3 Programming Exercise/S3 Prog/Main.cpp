#include "store.h"
#include <iostream>
#include <string>
#include <regex>

using namespace std;

double getDouble(string);

int main()
{
	
	//cylinderType c(2, 5, 4, 4);

	//c.setCenter(4, 4);

	//c.print();

	double x = getDouble("Enter a double");


	system("PAUSE");
	return 0;
}

double getDouble(string prompt)
{
	string input;
	bool valid = false;
	regex pattern("^[0-9]*\.?[0-9]+$");
	
	do
	{
		cout << prompt << endl;
		cin >> input;
		cout << endl;

		if (!regex_match(input, pattern))
		{
			cout << "This is not a valid number" << endl;
			continue;
		}
		else
		{
			return stod(input);
		}

	} while (!valid);	
}
