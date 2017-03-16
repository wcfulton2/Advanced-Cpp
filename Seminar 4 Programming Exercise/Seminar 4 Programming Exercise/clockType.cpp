/////////////////////////////////////////////////////////////////////////////////////////////////////
//Program Name: Operator Overloading Examples - Extended functionality of clockType class
//Description: Adds operator overloading to the clockType class originally outlined in chapter 10
//Developer: Bill Fulton of Baker College
//Date: 15 March 2017 - Winter
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "clockType.h"

//Constructor
clockType::clockType(int hours, int minutes, int seconds)
{
	setTime(hours, minutes, seconds);
}//end constructor

//Overload the post-intrement operator
clockType clockType::operator++(int)
{
	sec++; //add one second to the clock   

	if (sec > 59) //roll over minuites if seconds > 59
	{
		sec = 0;
		min++;

		if (min > 59) //roll hours if minuites > 59
		{
			min = 0;
			hr++;

			if (hr > 23) //zero hours if hours > 23
				hr = 0;
		} //end inner-if
	} //end outer-if

	return *this;
} //end post-intrement overload


//Overload the pre-increment operator.
clockType clockType::operator++()
{
	sec++; //add one second to the clock   

	if (sec > 59) //roll over minuites if seconds > 59
	{
		sec = 0;
		min++;

		if (min > 59) //roll hours if minuites > 59
		{
			min = 0;
			hr++;

			if (hr > 23) //zero hours if hours > 23
				hr = 0;
		} //end inner-if
	} //end outer-if

	return *this;
} //end pre-increment overload

//Overload the equality operator.
bool clockType::operator==(const clockType& otherClock) const
{
	return (hr == otherClock.hr && min == otherClock.min
		&& sec == otherClock.sec);
} //end equality operator overload

//Overload the not equal operator.
bool clockType::operator!=(const clockType& otherClock) const
{
	return (hr != otherClock.hr || min != otherClock.min
		|| sec != otherClock.sec);
} //end not-equal operator overload

//Overload the less than or equal to operator.
bool clockType::operator<=(const clockType& otherClock) const
{
	return ((hr < otherClock.hr) ||
		(hr == otherClock.hr && min < otherClock.min) ||
		(hr == otherClock.hr && min == otherClock.min &&
			sec <= otherClock.sec));
} //end less-than or equal-top operator overload

//Overload the less than operator.
bool clockType::operator<(const clockType& otherClock) const
{
	return ((hr < otherClock.hr) ||
		(hr == otherClock.hr && min < otherClock.min) ||
		(hr == otherClock.hr && min == otherClock.min &&
			sec < otherClock.sec));
} //end less-than operator overload

//Overload the greater than or equal to operator.
bool clockType::operator>=(const clockType& otherClock) const
{
	return ((hr > otherClock.hr) ||
		(hr == otherClock.hr && min > otherClock.min) ||
		(hr == otherClock.hr && min == otherClock.min &&
			sec >= otherClock.sec));
} //end greater-than or equal-to operator overload

//Overload the greater than operator.
bool clockType::operator>(const clockType& otherClock) const
{
	return ((hr > otherClock.hr) ||
		(hr == otherClock.hr && min > otherClock.min) ||
		(hr == otherClock.hr && min == otherClock.min &&
			sec > otherClock.sec));
} //end greater-than operator overload

void clockType::setTime(int hours, int minutes, int seconds)
{
	if (0 <= hours && hours < 24)
		hr = hours;
	else
		hr = 0;

	if (0 <= minutes && minutes < 60)
		min = minutes;
	else
		min = 0;

	if (0 <= seconds && seconds < 60)
		sec = seconds;
	else
		sec = 0;
} //end setTime

void clockType::getTime(int& hours, int& minutes,
	int& seconds) const
{
	hours = hr;
	minutes = min;
	seconds = sec;
} //end getTime

void clockType::printTime() const
{
	if (hr < 10)
		cout << "0";
	cout << hr << ":";

	if (min < 10)
		cout << "0";
	cout << min << ":";

	if (sec < 10)
		cout << "0";
	cout << sec << endl;
} //end printTime

//Overload the stream insertion operator.
ostream& operator<<(ostream& osObject, const clockType& timeOut)
{
	if (timeOut.hr < 10)
		osObject << '0';
	osObject << timeOut.hr << ':';

	if (timeOut.min < 10)
		osObject << '0';
	osObject << timeOut.min << ':';

	if (timeOut.sec < 10)
		osObject << '0';
	osObject << timeOut.sec;

	return osObject;  //return the ostream object
} //end stream insertion operator overload

//overload the stream extraction operator
istream& operator>> (istream& is, clockType& timeIn)
{
	char ch;

	is >> timeIn.hr;                        

	if (timeIn.hr < 0 || timeIn.hr >= 24)     
		timeIn.hr = 0;

	is.get(ch);          

	is >> timeIn.min;                         

	if (timeIn.min < 0 || timeIn.min >= 60)   
		timeIn.min = 0;

	is.get(ch);           

	is >> timeIn.sec;                        

	if (timeIn.sec < 0 || timeIn.sec >= 60)   
		timeIn.sec = 0;

	return is;                                
} // end stream extraction operator overload