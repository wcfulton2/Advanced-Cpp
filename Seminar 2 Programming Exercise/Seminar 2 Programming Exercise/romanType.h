//Program Name: Roman Numeral to Decimal Converter
//Description: Converts an inputted roman numeral to a decimal value
//Developer: Bill Fulton of Baker College
//Date: 28 February 2017 - Winter

#ifndef ROMANTYPE_H
#define ROMANTYPE_H

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class romanType
{
public:
	//constructor
	romanType();

	//accessors
	string getRomanNumeral();
	int getDecimalValue();

	//mutator
	void setRomanNumeral(string);	

private:
	//data members
	string romanNumeral;
	int decimalValue;
	
	//member methods
	int getVal(char);
	void romanToDec();	
};
#endif // !ROMANTYPE_H