//Program Name: Test to Upper
//Description: Converts inputted text to upper case using dynamic arrays
//Developer: Bill Fulton of Baker College
//Date: 19 February 2017 - Winter

#include <string>
#include <iostream>

using namespace std;

int main()
{
	string str = "";
	char *p;


	cout << "Enter a string: "; //prompt for user input
	cin >> str;
	cout << endl;

	p = new char[str.length()]; //create new dynamic array with the length of the inputted string

	p = (char*)str.c_str(); //initialize the array with the characters of the inputted string


	for(int i = 0; i < str.length(); i++) //convert the characters to upper case
	{
		p[i] = toupper(p[i]);
	}
	
	for(int i = 0; i < str.length(); i++) //output the characters to screen
	{
		cout << p[i];		
	}

	cout << endl;

	system("PAUSE");
    return 0;
} //end program

