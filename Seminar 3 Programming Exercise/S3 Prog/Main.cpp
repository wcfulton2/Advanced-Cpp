#include "store.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <regex>

using namespace std;

void execute();
double getDouble(string);
void print(store);

int main()
{
	execute();

	system("PAUSE");
	return 0;
}

void execute()
{
	store s;
	char goAgain;

	do {
		s.setRadius(getDouble("Please enter the radius of the container"));
		s.setHeight(getDouble("Please enter the height of the container"));
		s.setPriceOfPaint(getDouble("Please enter the price per sq/ft of paint"));
		s.setShippingPrice(getDouble("Please enter the shipping price per liter"));

		print(s);

		cout << "Do you want to run the program again?" << endl;
		cin >> goAgain;
		cout << endl;

		if (tolower(goAgain) == 'y')
		{
			s.reset();
			system("CLS");
		}

	} while (tolower(goAgain) == 'y');
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

void print(store s)
{
	cout << "The price of shipping " << s.volumeInLiters() << " liters is: $" << setprecision(2) << fixed << s.shippingCost() << endl;
	cout << "The price of painting " << s.getSurfaceArea() << " sq/ft is: $" << setprecision(2) << fixed << s.paintingCost() << endl;
	cout << "The total combined cost is: $" << setprecision(2) << fixed << s.totalCost() << endl << endl;
}
