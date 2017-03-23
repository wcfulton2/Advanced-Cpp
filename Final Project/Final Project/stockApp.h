#ifndef STOCK_APP_H
#define STOCK_APP_H

#include "stockType.h"
#include "stockListType.h"
#include "reportWriter.h"
#include <regex>
#include <string>
#include <iostream>

using namespace std;

class stockApp
{
public:
	stockApp();
	void execute();
	void menu();
	int getSelection(string);
	string changeFileName();

	
private:
	stockListType lst;

};

#endif // !STOCK_APP_H