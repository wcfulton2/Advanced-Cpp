//Program Name: Roman Numeral to Decimal Converter
//Description: Converts an inputted roman numeral to a decimal value
//Developer: Bill Fulton of Baker College
//Date: 28 February 2017 - Winter

#include "romanType.h"

using namespace std;

//default constructor
romanType::romanType() {}

string romanType::getRomanNumeral()  //accessor for the set roman numeral
{
	return romanNumeral;
} //end getRomanNumeral

int romanType::getDecimalValue() //accessor for converted roman numeral decimal value
{
	return decimalValue;
} //end getDecimalValue

void romanType::setRomanNumeral(string romanNumeral) //mutator for the roman numeral variable
{
	this->romanNumeral = romanNumeral;
	romanToDec(); //convert the roman numeral everytime it is changed.
} //emd setRomanNumeral

void romanType::romanToDec() //convert the entered roman numeral to decimal
{
	int value = 0; //local variable used when converting roman to decimal

	for (int i = 0; i < romanNumeral.length(); i++) //iterate over each character in the entered roman numeral
	{
		if (i == 0) //if first character in the string
		{
			if (romanNumeral.length() > 1 && getVal(romanNumeral[i + 1]) > getVal(romanNumeral[i])) //check if first character is smaller than the second
			{
				value = getVal(romanNumeral[i + 1]) - getVal(romanNumeral[i]); //if value of first is less than the value of the second, subtract first from second
				i++; //advance iterator to skip second character in the string
			}
			else //if first character's value is lager than the second, add the first's value to the total decimal value
				value += getVal(romanNumeral[i]);
		} //end first char check
		else if (i != 0 && i <= romanNumeral.length() - 2) //check second character throught second to last characters (range reguired to check for subtraction at the last variable an
		{																												//ensure check does not go out of bounds)
			if (getVal(romanNumeral[i]) < getVal(romanNumeral[i + 1])) //if current character's value is less than the next
			{
				value -= getVal(romanNumeral[i]); //subtract the chracter's value
			}
			else
			{
				value += getVal(romanNumeral[i]); //otherwise, add it
			}
		}//end else-if
		else if (i == romanNumeral.length() - 1) //add the value of the final entered character
			value += getVal(romanNumeral[i]);
	} //end for

	decimalValue = value; //store the decimal value of the entered numeral
} //end romanToDec

int romanType::getVal(char input) //get the decimal value of each roman numeral character
{
	int val = 0;

	char upper = toupper(input); //convert the character to uppercase

	switch (upper) //return the appropriate value of each roman numeral character - used in romanToDec
	{
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	}
} //end getVal