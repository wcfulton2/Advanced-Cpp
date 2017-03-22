/////////////////////////////////////////////////////////////////////////////////////////////////////
//Program Name: Length Converter
//Description: Convert feet and inches to centimeteres
//Developer: Bill Fulton of Baker College
//Date: 21 March 2017 - Winter
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CONVERTER_APP_H
#define CONVERTER_APP_H

#include "converter.h"
#include <iostream>
#include <string>
#include <regex>


class converterApp
{

public:
	void execute(); //begin program execution - set feet and inches, validate, convert, display, and loop program if desired

private:
	converter c; //local converter object
	double getDouble(string); //validate a user input double - must be positive and numeric
	void print(); //print to screen the converted lengths
	void reset(); //reset the object to ft = 0 and in = 0

};
#endif // !CONVERTER_APP_H