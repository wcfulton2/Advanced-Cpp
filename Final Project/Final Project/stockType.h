#ifndef STOCK_TYPE_H
#define STOCK_TYPE_H

#include <string>

using namespace std;

class stockType
{

	friend ostream& operator<<(ostream&, stockType&);
	friend istream& operator>>(istream&, stockType&);
	//friend bool operator>(const stockType&, stockType&);
	

public:

	stockType();
	stockType(string, double, int, double, double, double, double, double);

	string getSymbol();
	double getTotalValue();
	int getNumOfShares();
	double getOpeningPrice();
	double getClosingPrice();
	double getHighPrice();
	double getLowPrice();
	double getPreviousPrice();
	double getPercentGainLoss();

	void setSymbol(string);
	void setNumOfShares(int);
	void setOpeningPrice(double);
	void setClosingPrice(double);
	void setHighPrice(double);
	void setLowPrice(double);
	void setPerviousPrice(double);

	bool operator== (stockType&);
	bool operator!= (stockType&);
	bool operator<= (stockType&);
	bool operator< (stockType&);
	bool operator>= (stockType&);	
	bool operator> (stockType&);

private:
	string symbol;
	double totalValue;
	int numOfShares;
	double openingPrice;
	double closingPrice;
	double highPrice;
	double lowPrice;
	double previousPrice;
	double percentGainLoss;
};
#endif // !STOCK_TYPE_H