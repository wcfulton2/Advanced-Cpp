#include "cylinderType.h"

cylinderType::cylinderType() : circleType(0.0), height(0.0), xCoordinate(0.0), yCoordinate(0.0) {};

cylinderType::cylinderType(double r, double h, double x, double y) : circleType(r), height(h), xCoordinate(x), yCoordinate(y) {};

void cylinderType::print()
{
	cout << "Radius: " << getRadius() << " feet" << endl;
	cout << "Height: " << getHeight() << " feet"<< endl;
	cout << "Surface Area: " << getSurfaceArea() << " square feet" << endl;
	cout << "Circumference: " << circumference() << " feet" << endl;
	cout << "Volume: " << getVolume() << " cubic feet" << endl;
	cout << "Base center (x, y): (" << xCoordinate << ", " << yCoordinate << ")" << endl;
}

double cylinderType::getVolume()
{
	return PI * pow(getRadius(), 2) * height;
}

double cylinderType::getSurfaceArea()
{
	return (2 * PI * getRadius() * height) + (2 * PI * pow(getRadius(), 2));
}

double cylinderType::getHeight()
{
	return height;
}

void cylinderType::setHeight(double h)
{
	height = h;
}

void cylinderType::setCenter(double x, double y)
{
	xCoordinate = x;
	yCoordinate = y;
}
