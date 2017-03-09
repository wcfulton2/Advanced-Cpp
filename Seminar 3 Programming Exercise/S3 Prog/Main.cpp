/////////////////////////////////////////////////////////////////////////
//Program Name: Fluid-filled Cylinder Shipping Calculator
//Description: Calculates the price of painting and shipping 
//				a cylindrical container
//Developed by: Bill Fulton of Baker College
//Date: 02 March 2017 - Winter
/////////////////////////////////////////////////////////////////////////

#include "store.h"
#include <iostream>
#include <string>
#include <regex>

using namespace std;

//function prototypes
void execute(); //entry-point function
double getDouble(string); //get a valid double

int main()
{
	execute(); //call eexecute function - user entry point

	system("PAUSE");
	return 0;
} //end main

void execute() //user entry point function
{
	store s; //store object
	char goAgain;

	do {
		s.setRadius(getDouble("Please enter the radius of the container")); //get and set valid radius
		s.setHeight(getDouble("Please enter the height of the container")); //get and set a valid height
		s.setPriceOfPaint(getDouble("Please enter the price per sq/ft of paint")); //get and set the price of paint per sq/ft
		s.setShippingPrice(getDouble("Please enter the shipping price per liter")); //get and set the price of shipping per liter

		s.print(); //call the print function - output the calculated values to the screen

		cout << "Do you want to run the program again?" << endl; //prompt to run the program again
		cin >> goAgain;
		cout << endl;

		if (tolower(goAgain) == 'y') //if the program is running again, clear the screen and the variables used in the store
		{
			s.reset();
			system("CLS");
		}

	} while (tolower(goAgain) == 'y');
} //end execute

double getDouble(string prompt) //prompt for and validate a valid double
{
	string input;
	bool valid = false;
	regex pattern("^[0-9]*\.?[0-9]+$");
	
	do
	{
		cout << prompt << endl; //prompt the user to enter a value for a specific field (height, radius, etc...)
		cin >> input;
		cout << endl;

		if (!regex_match(input, pattern) || stod(input) < 0) //if the number is invalid
		{
			cout << "This is not a valid number" << endl; //display an error			
		}
		else //if the number is valid, return it as a double
		{
			return stod(input);
		}

	} while (!valid); //loop until a valid number is entered
} //end getDouble