#ifndef CYLINDER_TYPE_H
#define CYLINDER_TYPE_H

#include "circleType.h"
#include <iostream>
#include <math.h>

using namespace std;

class cylinderType : public circleType
{
public:
	cylinderType();
	cylinderType(double, double, double, double);

	void print();

	double getVolume();
	double getSurfaceArea();
	double getHeight();

	void setHeight(double);	
	void setCenter(double, double);
	
	//set radius

private:
	double height;
	double xCoordinate;
	double yCoordinate;
	const double PI = atan(1) * 4;
};
#endif // !CYLINDER_TYPE_H