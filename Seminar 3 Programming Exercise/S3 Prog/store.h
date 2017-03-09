/////////////////////////////////////////////////////////////////////////
//Program Name: Fluid-filled Cylinder Shipping Calculator
//Description: Calculates the price of painting and shipping 
//				a cylindrical container
//Developed by: Bill Fulton of Baker College
//Date: 02 March 2017 - Winter
/////////////////////////////////////////////////////////////////////////

#ifndef STORE_H
#define STORE_H

#include "cylinderType.h"
#include <iostream>
#include <iomanip>

using namespace std;

class store
{

public:
	store(); //default constructor
	
	void print(); //print the shipping cost, cost of painting, and combined total cost

	void reset(); //reset the variables used throught the order

	//accessors
	double shippingCost(); //price to ship the container
	double totalCost(); //total cost of order: shipping + painting
	double paintingCost(); //cost to paint the container
	double volumeInLiters(); //convert volume from cubic feet to liters
	double getSurfaceArea(); //get the surface area of the cylinder in sq/ft
	double getPriceOfPaint(); //get price of paint per sq/ft
	double getShippingPrice(); //get price of shipping per liter

	//mutators
	void setPriceOfPaint(double); //set price of paint per sq/ft
	void setShippingPrice(double); //set price of shipping per liter
	void setRadius(double); //set the radius of the cylinder's base
	void setHeight(double); //set the height of the cylinder



	private:
	cylinderType c; //local instance of CylinderType
	
	//data members
	double priceOfPaint;
	double shippingPrice;
};
#endif // !STORE_H
