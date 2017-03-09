/////////////////////////////////////////////////////////////////////////
//Program Name: Fluid-filled Cylinder Shipping Calculator
//Description: Calculates the price of painting and shipping 
//				a cylindrical container
//Developed by: Bill Fulton of Baker College
//Date: 02 March 2017 - Winter
/////////////////////////////////////////////////////////////////////////

#include "cylinderType.h"

cylinderType::cylinderType() : circleType(0.0), height(0.0), xCoordinate(0.0), yCoordinate(0.0) {}; //default constructor

//constructor that sets radius, height, and base (x,y)
cylinderType::cylinderType(double r, double h, double x, double y) : circleType(r), height(h), xCoordinate(x), yCoordinate(y) {};

void cylinderType::print() //print radius, height, surface area, circumference, volume in cubic feet, and base (x,y)
{
	cout << "Radius: " << getRadius() << " feet" << endl;
	cout << "Height: " << getHeight() << " feet"<< endl;
	cout << "Surface Area: " << getSurfaceArea() << " square feet" << endl;
	cout << "Circumference: " << circumference() << " feet" << endl;
	cout << "Volume: " << getVolume() << " cubic feet" << endl;
	cout << "Base center (x, y): (" << xCoordinate << ", " << yCoordinate << ")" << endl;
} //end print

double cylinderType::getVolume() //return the volume of the cylinder in cubic feet
{
	return PI * pow(getRadius(), 2) * height;
} //end getVolume

double cylinderType::getSurfaceArea() //return surface area of the cylinder
{
	return (2 * PI * getRadius() * height) + (2 * PI * pow(getRadius(), 2));
} //end getSurfaceArea

double cylinderType::getHeight() //return height of the cylinder
{
	return height;
} //end getHeight

void cylinderType::setHeight(double h) //set the height of the cylinder
{
	height = h;
} //end setHeight

void cylinderType::setCenter(double x, double y) //set the center (x,y) of the cylinder's base
{
	xCoordinate = x;
	yCoordinate = y;
} //end setCenter
