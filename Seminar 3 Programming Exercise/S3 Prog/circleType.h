#ifndef CIRCLE_TYPE_H
#define CIRCLE_TYPE_H

#include <iostream>

class circleType
{
public:
	circleType(double r = 0);
	void print();
	void setRadius(double r);
	double getRadius();
	double area();
	double circumference();

private:
	double radius;
};
#endif // !CIRCLE_TYPE_H