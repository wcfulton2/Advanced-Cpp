/////////////////////////////////////////////////////////////////////////
//Program Name: Fluid-filled Cylinder Shipping Calculator
//Description: Calculates the price of painting and shipping 
//				a cylindrical container
//Developed by: Bill Fulton of Baker College
//Date: 02 March 2017 - Winter
/////////////////////////////////////////////////////////////////////////

#include "store.h"

store::store(){} //default constructor

void store::print() //print the price of shipping, price of painting, and total cost of order
{
	cout << "The price of shipping " << volumeInLiters() << " liters is: $" << setprecision(2) << fixed << shippingCost() << endl;
	cout << "The price of painting " << getSurfaceArea() << " sq/ft is: $" << setprecision(2) << fixed << paintingCost() << endl;
	cout << "The total combined cost is: $" << setprecision(2) << fixed << totalCost() << endl << endl;
} //end print

void store::reset() //reset all of the relevent variables used throught the execution of the program
{
	setRadius(0);
	setHeight(0);
	priceOfPaint = 0;
	shippingPrice = 0;
} //end reset

double store::shippingCost() //calculate the shipping cost of the order
{
	return volumeInLiters() * shippingPrice;
} //end shippingCost()

double store::totalCost() //get the total combined cost of the order (painting + shipping)
{
	return shippingCost() + paintingCost();
} //end totalCost

double store::paintingCost() //calculate the painting cost for the order
{
	return c.getSurfaceArea() * priceOfPaint;
} //end paintingCost

double store::volumeInLiters() //convert the volume of the cylinder to liters from cubic feet
{
	return c.getVolume() * 28.32;
} //end getVolumeInLiters

double store::getSurfaceArea() //return the surface area of the cylinder
{
	return c.getSurfaceArea(); 
} //end getSurfaceArea

double store::getPriceOfPaint() //return the price per sq/ft of the paint
{
	return priceOfPaint;
} //end getPriceOfPaint

double store::getShippingPrice() //return the price of shipping per liter
{
	return shippingPrice;
} //end getShippingPrice

void store::setPriceOfPaint(double price) //set the price of paint per sq/ft
{
	priceOfPaint = price;
} //end setPriceOfPaint

void store::setShippingPrice(double cost) //set the per liter shipping cost
{
	shippingPrice = cost;
} //end setShippingCost

void store::setRadius(double r) //set the radius of the base of the cylinder
{
	c.setRadius(r);
} //end setRadius

void store::setHeight(double h) //set the height of the cylinder
{
	c.setHeight(h);
} //end setHeight