//Program Name: Roman Numeral to Decimal Converter
//Description: Converts an inputted roman numeral to a decimal value
//Developer: Bill Fulton of Baker College
//Date: 28 February 2017 - Winter

#include "romanApp.h"

using namespace std;

//default constructor
romanApp::romanApp() {}

void romanApp::enterConvertAndPrint() //function to allow for entry, conversion, and output all at once
{
	system("CLS");

	r.setRomanNumeral(getInput()); //get a valid numeral, get it's decimal value, and set it to the member variable for roman numeral and decemal - in romanType.cpp

	print(); //output to screen
}//end enterConvertAndPrint

void romanApp::menu() //display a menu to the screen
{
	cout << "Roman Numeral Converter" << endl;
	cout << "1. Enter a Roman Numeral" << endl;
	cout << "2. Display the Romen Numeral" << endl;

	cout << "3. Enter, Convert and Print a Roman Numeral" << endl;
	cout << "4. Convert and Print the Roman Numeral" << endl;
	cout << "5. Exit the Program" << endl << endl;
	cout << "Please make a selection" << endl;
	makeSelection(); //prompt for user selection
} //end menu

void romanApp::makeSelection() //get a valid user menu selection
{
	string selection = "";
	bool valid = false;
	regex pattern("[1-5]");

	do {
		cin >> selection;

		if (regex_match(selection, pattern))
		{
			switch (stoi(selection)) //run the user selected function
			{
			case 1:
				enterNumeral(); //enter a roman numeral
				break;
			case 2:
				displayNumeral(); //display the entered numeral
				break;
			case 3:
				enterConvertAndPrint(); //enter, convert, and print a roman numeral
				break;
			case 4:
				print(); //convert and print an entered numeral
				break;
			case 5:
				exit(0); //exit the program
			}

			menu(); //return to the menu after the desired function has run
		}
		else
		{
			cout << "Please enter a valid selection" << endl; //error handling for selection out-of-bounds
		}
	} while (!valid);
} //end makeSelection

void romanApp::enterNumeral() //prompt user to enter a roman numeral
{
	system("CLS");
	r.setRomanNumeral(getInput()); //set the roman numeral variable to a valid roman numeral and store it's decimal value - in romanType.cpp
	cout << "Roman Numeral Entered Successfully" << endl << endl;
} //end enterNumeral

void romanApp::displayNumeral() //display an entered roman numeral
{
	system("CLS");
	string temp = r.getRomanNumeral(); //get the set roman numeral - in romanType.cpp
	if (temp.length() > 0) //check if a numeral has been entered
	{
		cout << "The Roman Numeral entered is: " << r.getRomanNumeral() << endl << endl; //if one has been entered, display it - in romanType.cpp
	}
	else //if no numeral has been entered, display an error
	{
		cout << "No Roman Numeral has been entered yet" << endl << endl;
	}
} //end displayNumeral

string romanApp::getInput() //prompt for user input of a valid roman numeral
{
	string temp = " ";
	bool valid = false;
	regex goodPattern("^[m, c, l, x, i, v, d]+$", regex_constants::icase); //check for valid roman numeral characters
	regex badPattern("(C{4,})|(V{4,})|(D{4,})|(X{4,})|(V{4,})|(I{4,})|(M{4,})", regex_constants::icase); //check for more than 4 of the same letter in a row

	do {
		cout << "Enter a Roman Numeral" << endl; //prompt for user input of a roman numeral
		cin >> temp;
		cout << endl;

		if (!regex_match(temp, badPattern) && regex_match(temp, goodPattern)) //validate the input
		{
			system("CLS"); 
			return temp; //if the numeral is valid, return it - used in enterNumeral and enterConvertAndPrint
		}
		else //if invalid, display an error and reprompt
		{
			cout << "This is not a valid Roman Numeral" << endl << endl;
		}
	} while (!valid);
} //end getInput

void romanApp::print() //display the decimal value of the entered roman numeral
{
	system("CLS");
	cout << "The value of " << r.getRomanNumeral() << " in decimal is: " << r.getDecimalValue() << endl << endl;
} //end print