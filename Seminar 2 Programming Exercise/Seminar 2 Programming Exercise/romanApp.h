//Program Name: Roman Numeral to Decimal Converter
//Description: Converts an inputted roman numeral to a decimal value
//Developer: Bill Fulton of Baker College
//Date: 28 February 2017 - Winter

#ifndef ROMANAPP_H
#define ROMANAPP_H

#include "romanType.h"
#include <regex>
#include <iostream>
#include <string>

using namespace std;

class romanApp 
{
public:
	//constructor
	romanApp();

	//user entry point method
	void menu();

private:
	romanType r; //local romanType object
	
	//local member methods
	void enterConvertAndPrint();
	void makeSelection();
	void enterNumeral();
	string getInput();
	void displayNumeral();
	void print();
};
#endif // !ROMANAPP_H