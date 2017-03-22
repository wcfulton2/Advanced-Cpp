/////////////////////////////////////////////////////////////////////////////////////////////////////
//Program Name: Length Converter
//Description: Convert feet and inches to centimeteres
//Developer: Bill Fulton of Baker College
//Date: 21 March 2017 - Winter
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "converter.h"

converter::converter() : ft(0), in(0) { } //default constructor

converter::converter(double ft, double in) : ft(ft), in(in) { } //parameterized constructor - set ft and in

void converter::setFt(double ft) //set value of feet
{
	this->ft = ft;
} //end setFt

void converter::setIn(double in) //set value of inches
{
	this->in = in;
} //end setIn

double converter::getFt() //return value of feet
{
	return ft;
} //end getFt

double converter::getIn() //return value of inches
{
	return in;
} //end getIn

double converter::convert() //convert feet and inches to centimeters
{
	return (((ft * 12) * inToCm) + (in * inToCm)); //return the user input length in feet and inches as centimeters
} //end convert