#include "circleType.h"

using namespace std;

circleType::circleType(double r)
{
	setRadius(r);
}

void circleType::print()
{
	cout << "Radius: " << radius << endl;
	cout << "Area: " << area() << endl;
	cout << "Circumference: " << circumference() << endl;
}

void circleType::setRadius(double r)
{
	if (r >= 0)
		radius = r;
	else
		radius = 0;
}

double circleType::getRadius()
{
	return radius;
}

double circleType::area()
{
	return 3.1416 * radius * radius;
}

double circleType::circumference()
{
	return 2 * 3.1416 * radius;
}