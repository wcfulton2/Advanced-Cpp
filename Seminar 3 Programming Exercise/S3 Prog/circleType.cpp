/////////////////////////////////////////////////////////////////////////
//Program Name: Fluid-filled Cylinder Shipping Calculator
//Description: Calculates the price of painting and shipping 
//				a cylindrical container
//Developed by: Bill Fulton of Baker College
//Date: 02 March 2017 - Winter
/////////////////////////////////////////////////////////////////////////

#include "circleType.h"

using namespace std;

circleType::circleType(double r) //constructor that takes and sets radius
{
	setRadius(r);
} //end constructor

void circleType::print() //print radius, area, and circumference to the screen
{
	cout << "Radius: " << radius << endl;
	cout << "Area: " << area() << endl;
	cout << "Circumference: " << circumference() << endl;
} //end print

void circleType::setRadius(double r) //set the radius of the cricle
{
	if (r >= 0) //check for radius greater-than 0
		radius = r;
	else //if less-than or equal-to 0, make it 0
		radius = 0;
} //end setRadius

double circleType::getRadius() //return the radius of the circle
{
	return radius;
} //end getRadius

double circleType::area() //return the area of the circle
{
	return 3.1416 * radius * radius;
} //end area

double circleType::circumference() //return the circumference of the circle
{
	return 2 * 3.1416 * radius;
} //end circumference