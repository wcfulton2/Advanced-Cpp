/////////////////////////////////////////////////////////////////////////
//Program Name: Fluid-filled Cylinder Shipping Calculator
//Description: Calculates the price of painting and shipping 
//				a cylindrical container
//Developed by: Bill Fulton of Baker College
//Date: 02 March 2017 - Winter
/////////////////////////////////////////////////////////////////////////

#ifndef CYLINDER_TYPE_H
#define CYLINDER_TYPE_H

#include "circleType.h"
#include <iostream>
#include <math.h>

using namespace std;

class cylinderType : public circleType
{
public:
	//constructors
	cylinderType();
	cylinderType(double, double, double, double);

	void print(); //print radius, height, surface area, circumference, volume in cubic feet, and base center (x, y)

	//accessors
	double getVolume(); //return the volume of the cylinder in sq/ft
	double getSurfaceArea(); //return the surface area of the cylinder
	double getHeight(); //return the height of the cylinder

	//mutators
	void setHeight(double);	//set the height of the cylinder
	void setCenter(double, double); //set the center point of the base in (x, y)

private:
	//data members
	double height;
	double xCoordinate;
	double yCoordinate;
	const double PI = atan(1) * 4;
};
#endif // !CYLINDER_TYPE_H