/////////////////////////////////////////////////////////////////////////////////////////////////////
//Program Name: Operator Overloading Examples - Extended functionality of clockType class
//Description: Adds operator overloading to the clockType class originally outlined in chapter 10
//Developer: Bill Fulton of Baker College
//Date: 15 March 2017 - Winter
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "clockType.h"

int main()
{
	clockType clock(11, 59, 59); //create a new clock

	clock.printTime(); //print the time of the clock
	
	clock++; //increment the time of the clock
	clock.printTime(); //print the time of the clock

	clock++; //increment the time of the clock
	clock.printTime(); //print the time of the clock

	clock++; //increment the time of the clock
	clock.printTime(); //print the time of the clock


	system("PAUSE");
	return 0;
}