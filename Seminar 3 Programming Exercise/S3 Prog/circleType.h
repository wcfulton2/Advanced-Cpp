/////////////////////////////////////////////////////////////////////////
//Program Name: Fluid-filled Cylinder Shipping Calculator
//Description: Calculates the price of painting and shipping 
//				a cylindrical container
//Developed by: Bill Fulton of Baker College
//Date: 02 March 2017 - Winter
/////////////////////////////////////////////////////////////////////////

#ifndef CIRCLE_TYPE_H
#define CIRCLE_TYPE_H

#include <iostream>

class circleType
{
public:
	circleType(double r = 0); //constructor

	void print(); //display radius, circumference, and area of the circle

	//mutators
	void setRadius(double r); //set the radius of the circle
	
	//accessors
	double getRadius(); //returnt the radius of the circle
	double area(); //calculate the area of the circle
	double circumference(); //calculate the circumference of the circle

private:
	//data members
	double radius;
};
#endif // !CIRCLE_TYPE_H