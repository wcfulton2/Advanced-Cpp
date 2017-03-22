/////////////////////////////////////////////////////////////////////////////////////////////////////
//Program Name: Length Converter
//Description: Convert feet and inches to centimeteres
//Developer: Bill Fulton of Baker College
//Date: 21 March 2017 - Winter
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "converterApp.h"

void converterApp::execute() //user entry point
{
	char goAgain = ' ';

	do 
	{
		system("CLS"); //clear console window
		reset(); //reset the converter object to ft = 0, in = 0

		c.setFt(getDouble("Enter a length in feet")); //get a valid double and set it to the value of feet
		c.setIn(getDouble("Enter a length in inches")); //get a valid double and set it to the value of inches

		print(); //call to the print function - displays converted user input values

		cout << "Do you want to run the program again? y/n" << endl; //repeat the program if desired
		cin >> goAgain;

	} while (tolower(goAgain) == 'y'); //end do/while
} //end execute

double converterApp::getDouble(string prompt) //get and return a valid user inputted double
{
	double val;
	string input;
	bool valid = false;
	regex pattern("^[0-9]*[\.]?[0-9]*$");

	do //loop until a valid input is received
	{ 
		try
		{
			cout << prompt << endl; //propt user to enter the desired value
			cin >> input;
			cout << endl;

			if (!regex_match(input, pattern)) //if the input is not numeric or is negative, throw an exception
				throw 0;

			val = stod(input); //if the input is valid, convert it to a double
			valid = true;

		} //end try
		catch (int) //catch a thrown exception - if user input is not within the desired paramaters - must be numeric and positive
		{
			cout << "This is not a valid number, please try again" << endl;
		} //end catch
	} while (!valid); //end do/while

	return val; //return the valid double
} //end getDouble


void converterApp::print() //print the converted feet and inches to the screen
{
	cout << c.getFt() << " feet and " << c.getIn() << " inches converterd to centimeteres is: " << c.convert() << endl << endl;
} //end print

void converterApp::reset() //reset the converter object
{
	c.setFt(0); //set feet to 0
	c.setIn(0); //set inches to 0
} //end reset