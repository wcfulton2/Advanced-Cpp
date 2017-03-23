#ifndef STOCK_LIST_TYPE_H
#define STOCK_LIST_TYPE_H

#include "stockType.h"
#include "listType.h"
#include "reportWriter.h"
#include <iostream>
#include <fstream>

using namespace std;


class stockListType : public listType<stockType>
{
public:

	//int getLength();

	stockListType();
	void populateList();
	void addToList(stockType);
	void clearList();

	void createFileReport();
	void printScreenReport();


	void createHeader(ostream&);
	void createFooter(ostream&);

//	void printFileReport();

	double calculateTotalAssetsValue();

	double getTotalAssetsValue();
	void setTotalAssetsValue(double);

	void sortGainLoss();


	void setFileName(string);
	string getFileName();

private:
	double totalAssetsValue;
	string fileName = "StockInput.txt";


	listType<stockType> t;
};
#endif // !STOCK_LIST_TYPE_H