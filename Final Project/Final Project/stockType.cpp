#include "stockType.h"

/**************************************************
			Stream Operator Overloads
***************************************************/
ostream& operator<<(ostream& out, stockType& temp)
{
	char tab = '\t';
	
	out.imbue(locale(""));
	out << setprecision(2) << fixed;

	out << temp.getSymbol() << tab << setw(6) << temp.getOpeningPrice() << tab << setw(6) << temp.getClosingPrice() << tab << setw(7) << temp.getHighPrice() << tab << setw(8) << temp.getLowPrice() <<
		setw(8) << temp.getPreviousPrice() << setw(10) << temp.getPercentGainLoss() << "%" << tab << setw(11) << temp.getNumOfShares() << endl;
	
	return out;
}

istream& operator>>(istream& in, stockType& obj)
{
	string temp;
	double val;

	in >> temp;
	obj.setSymbol(temp);

	in >> val;
	obj.setOpeningPrice(val);

	in >> val;
	obj.setClosingPrice(val);

	in >> val;
	obj.setHighPrice(val);

	in >> val;
	obj.setLowPrice(val);

	in >> val;
	obj.setPerviousPrice(val);

	in >> val;
	obj.setNumOfShares(val);	

	return in;
}


/***************************************************
				constructors
****************************************************/
stockType::stockType() { }


/**************************************************
				accessors
**************************************************/
string stockType::getSymbol()
{
	return this->symbol;
}

double stockType::getTotalValue()
{
	this->totalValue = closingPrice * numOfShares;

	return totalValue;
}

int stockType::getNumOfShares()
{
	return this->numOfShares;
}

double stockType::getOpeningPrice()
{
	return this->openingPrice;
}

double stockType::getClosingPrice()
{
	return this->closingPrice;
}

double stockType::getHighPrice()
{
	return this->highPrice;
}

double stockType::getLowPrice()
{
	return this->lowPrice;
}

double stockType::getPreviousPrice()
{
	return this->previousPrice;
}

double stockType::getPercentGainLoss()
{
	percentGainLoss = ((closingPrice - previousPrice) / previousPrice) * 100;

	return percentGainLoss;
}


/**************************************************
				Mutators
***************************************************/
void stockType::setSymbol(string symbol)
{
	this->symbol = symbol;
}

void stockType::setNumOfShares(int numOfShares)
{
	this->numOfShares = numOfShares;
}

void stockType::setOpeningPrice(double openingPrice)
{
	this->openingPrice = openingPrice;
}

void stockType::setClosingPrice(double closingPrice)
{
	this->closingPrice = closingPrice;
}

void stockType::setHighPrice(double highPrice)
{
	this->highPrice = highPrice;
}

void stockType::setLowPrice(double lowPrice)
{
	this->lowPrice = lowPrice;
}

void stockType::setPerviousPrice(double previousPrice)
{
	this->previousPrice = previousPrice;
}


/**************************************************
			Relational Operator Overloads
***************************************************/
bool stockType::operator==(stockType& obj)
{
	return symbol == obj.getSymbol();
}

bool stockType::operator!=(stockType& obj)
{
	return symbol != obj.getSymbol();
}

bool stockType::operator<=(stockType& obj)
{
	return symbol <= obj.getSymbol();
}

bool stockType::operator<(stockType& obj)
{
	return symbol < obj.getSymbol();
}

bool stockType::operator>=(stockType& obj)
{
	return symbol >= obj.getSymbol();
}

bool stockType::operator>(stockType& obj)
{
	return symbol > obj.getSymbol();
}