/////////////////////////////////////////////////////////////////////////////////////////////////////
//Program Name: Operator Overloading Examples - Extended functionality of clockType class
//Description: Adds operator overloading to the clockType class originally outlined in chapter 10
//Developer: Bill Fulton of Baker College
//Date: 15 March 2017 - Winter
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CLOCK_TYPE_H
#define CLOCK_TYPE_H

#include <iostream>

using namespace std;

class clockType
{
	friend ostream& operator<<(ostream&, const clockType&); //overload the stream insertion operator
	friend istream& operator>>(istream&, clockType&); //overload the stream extraction operator

public:
	//constructors
	clockType(int hours = 0, int minutes = 0, int seconds = 0); //set time equal-to user definition or else set the time to all 0s

	//accessors
	void getTime(int& hours, int& minutes, int& seconds) const; //return the time of the clock

	//mutators
	void setTime(int hours, int minutes, int seconds); //set the time of the clock

	//Operator overloads
	clockType operator++(int); //overload the post-increment operator. Advance the time by 1 second

	clockType operator++(); //overload the pre-increment operator. Advance the time by 1 second

	bool operator==(const clockType& otherClock) const; //overload equality operator. Check if two clocks are equal to eachother and return a boolean result

	bool operator!=(const clockType& otherClock) const; //overload not-equal operator. Check if two clocks are not-equal to eachother and return a boolean result

	bool operator<=(const clockType& otherClock) const; //overload the less-than or equal-to operator. Chekck if one clock's time is less-than or equal-to another clock's and return a boolean result

	bool operator<(const clockType& otherClock) const; //overload the less-than operator. Chekck if one clock's time is less-than another clock's and return a boolean result

	bool operator>=(const clockType& otherClock) const; //overload the greater-than or equal-to operator. Chekck if one clock's time is greater-than or equal-to another clock's and return a boolean result

	bool operator>(const clockType& otherClock) const; //overload the greater-than operator. Chekck if one clock's time is greater-than another clock's and return a boolean result


	void printTime() const; //display the current time of the clock

private:
	//local data members
	int hr;  //variable to store the hours
	int min; //variable to store the minutes
	int sec; //variable to store the seconds
};

#endif //	!CLOCK_TYPE_H
