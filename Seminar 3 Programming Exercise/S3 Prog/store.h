#ifndef STORE_H
#define STORE_H

#include "cylinderType.h"
#include <iostream>

using namespace std;

class store
{

public:
	store();
	
	void totalShippingCost();
	void paintingCost();

	void setPriceOfPaint(double);
	void setShippingCost(double);

private:
	cylinderType c;
	
	double priceOfPaint;
	double shippingCost;
};
#endif // !STORE_H
