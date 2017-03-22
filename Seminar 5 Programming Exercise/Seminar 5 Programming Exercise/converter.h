/////////////////////////////////////////////////////////////////////////////////////////////////////
//Program Name: Length Converter
//Description: Convert feet and inches to centimeteres
//Developer: Bill Fulton of Baker College
//Date: 21 March 2017 - Winter
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>

using namespace std;

class converter
{

public:
	//constructors
	converter();
	converter(double, double); //parameterized constructor - set feet and inches

	//mutators
	void setFt(double); //set feet
	void setIn(double);	 //set inches
	
	//accessors
	double getFt(); //return feet
	double getIn();	 //return inches
	double convert(); //convert from feet and inches to centimeters

private:
	const double inToCm = 2.54; //constant for centimeteres/inch
	double ft; //user input feet
	double in; //user input inches

};
#endif // !CONVERTER_H
