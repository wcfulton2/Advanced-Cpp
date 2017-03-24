#ifndef STOCK_LIST_TYPE_H
#define STOCK_LIST_TYPE_H

#include "stockType.h"
#include "listType.h"
#include <iostream>
#include <fstream>

using namespace std;

class stockListType : public listType<stockType>
{
public:

	stockListType();
	
	void populateList();
	void clearList();	
	
	string getFileName();
	double getTotalAssetsValue();

	void setFileName(string);

	void createFileReport();
	void printScreenReport();
	void printScreenReportByGain();

private:
	listType<stockType> t;
	double totalAssetsValue;
	string fileName = "stocks.txt";

	void addToList(stockType);
	void createHeader(ostream&);
	void createFooter(ostream&);
	int* sortGainLoss();

	int countLines();	
};
#endif // !STOCK_LIST_TYPE_H