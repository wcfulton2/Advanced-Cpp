#ifndef STOCK_APP_H
#define STOCK_APP_H

#include "stockListType.h"
#include <regex>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class stockApp
{
public:
	stockApp();

	void execute();
	
private:
	stockListType lst;
	void menu();
	int getSelection(string);
	string changeFileName();
};

#endif // !STOCK_APP_H