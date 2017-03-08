#include "store.h"

store::store(){}

void store::reset()
{
	setRadius(0);
	setHeight(0);
	priceOfPaint = 0;
	shippingPrice = 0;
}

double store::shippingCost()
{
	return volumeInLiters() * shippingPrice;
}

double store::totalCost()
{
	return shippingCost() + paintingCost();
}

double store::paintingCost()
{
	return c.getSurfaceArea() * priceOfPaint;
}

double store::volumeInLiters()
{
	return c.getVolume() * 28.32;
}

double store::getSurfaceArea()
{
	return c.getSurfaceArea();
}

void store::setPriceOfPaint(double price)
{
	priceOfPaint = price;
}

void store::setShippingPrice(double cost)
{
	shippingPrice = cost;
}

void store::setRadius(double r)
{
	c.setRadius(r);
}

void store::setHeight(double h)
{
	c.setHeight(h);
}

double store::getPriceOfPaint()
{
	return priceOfPaint;
}

double store::getShippingPrice()
{
	return shippingPrice;
}
