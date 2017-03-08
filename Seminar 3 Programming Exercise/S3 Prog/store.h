#ifndef STORE_H
#define STORE_H

#include "cylinderType.h"
#include <iostream>

using namespace std;

class store
{

public:
	store();
	
	void reset();

	double shippingCost(); //price to ship the container
	double totalCost(); //total cost of order: shipping + painting
	double paintingCost(); //cost to paint the container
	double volumeInLiters();
	double getSurfaceArea();

	void setPriceOfPaint(double); //set price of paint per sq/ft
	void setShippingPrice(double); //set price of shipping per liter
	void setRadius(double);
	void setHeight(double);

	double getPriceOfPaint(); //get price of paint per sq/ft
	double getShippingPrice(); //get price of shipping per liter

	private:
	cylinderType c;
	
	double priceOfPaint;
	double shippingPrice;
};
#endif // !STORE_H
