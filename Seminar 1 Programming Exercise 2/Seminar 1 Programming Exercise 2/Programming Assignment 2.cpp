//Program Name: Student Test Grader
//Description: Grade student tests from data in a file using dynamic arrays
//Developer: Bill Fulton of Baker College
//Date: 21 February 2017 - Winter

#include <string>
#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

//function prototypes
void gradeTests();
int getNumber(string);
char getGrade(double, double);
void outputToScreen(string *IDs, string *answers, char *grades, int*);
string getData(string*, string*, int*);
void checkAnswers(string*, string*, char*, string, int*);

int main()
{
	gradeTests(); //call the gradeTests function - line 30

	system("PAUSE");
	return 0;
} //end main

void gradeTests() //program entry function
{
	string key;
	int *numOfStudents = new int; //int pointer for the number of students in the file

	*numOfStudents = getNumber("How many tests will be graded?"); //get valid user input for number of students - line 47

	//create new dynaic arrays for ID, answers, and final grades
	string *studentID = new string[*numOfStudents];
	string *answers = new string[*numOfStudents];
	char *grades = new char[*numOfStudents];

	key = getData(studentID, answers, numOfStudents); //call the getData function and get the answer key - line 69

	checkAnswers(studentID, answers, grades, key, numOfStudents); //check the student answers against the answer key - line 109
} //end gradeTests

int getNumber(string prompt) { //get a valid user input
	string input;
	bool valid = false;
	regex numPattern("(-)?[0-9]+");

	cout << prompt << endl; //prompt user for input
	do {
		cout << "Enter a positive whole number: "; //take in input
		cin >> input;
		cout << endl;

		if (regex_match(input, numPattern) && stoi(input) >= 0) { //validate
			valid = true;
		}
		else {
			cout << "You may only enter numbers." << endl; //reject bad input
		}
	} while (!valid);

	return atoi(input.c_str()); // return the valid input - line 35
} //end getNumber

string getData(string * studentID, string * answers, int *numOfStudents) //read from file and populate arrays
{
	fstream iofile; //new filestream object
	iofile.open("data.txt"); //define data.txt as the read file

	string temp; //temporary storage for input
	string key; //answer key

	iofile >> key; //read answer key

	int i = 0; //itterator for counting number of lines read and indexing arrays

	iofile.ignore(numeric_limits<streamsize>::max(), '\n'); //clear input buffer

	if (iofile.good()) //check for a good file
	{
		while (!iofile.eof() && i < *numOfStudents) //loop through file while there is still data to be read and up to the number of lines requested by the user - line 35
		{
			getline(iofile, temp);
			studentID[i] = temp.substr(0, 8); //extract studentID
			answers[i] = temp.substr(9); //extract answers
			i++;
		}
	}
	else //bad file error handling
	{
		cout << "File Error. Please Check the File and Try Again." << endl;
	}

	iofile.close(); //close file

	if (i < *numOfStudents) //modify the numberOfStudents variable should the file contain data for fewer students than the user entered
	{
		cout << "Expected " << *numOfStudents << " entries but only found " << i << ". All available entries will be graded." << endl << endl;
		*numOfStudents = i;
	}

	return key; //return the answer key - line 42
} //end getData

void checkAnswers(string * studentID, string * answers, char* grades, string key, int *numOfStudents) //check the student answers against the key
{

	string temp; //temporary variable
	int correct = 0;
	int incorrect = 0;

	for (int i = 0; i < *numOfStudents; i++) //iterate over each student
	{
		temp = answers[i]; //put each students answer in a temporary variable

		for (int j = 0; j < 20; j++) //iterate over each char in temp to compare to key
		{
			if (temp.at(j) == key.at(j)) //if answer is correct, +2 points
				correct += 2;
			else if (temp.at(j) != key.at(j) && temp.at(j) != ' ') //if answer is wrong, but not blank, add 1 to the number of incorrect
				incorrect++;
		}

		grades[i] = getGrade(correct, incorrect); //call to the getGrade function - gets letter grade and stores it in the grades array - function starts at line 136
		correct = 0; //0 the correct and incorrect variables to prepare for the next student
		incorrect = 0;
	}

	outputToScreen(studentID, answers, grades, numOfStudents); //output the studentID, answers, and grades to the screen after grading is complete - line 159
} //end checkAnswers

char getGrade(double correct, double incorrect) //get the student letter grades
{
	int const MAX_SCORE = 40; //maximum possible points at 2 pointers per question
	double score = 0;
	char grade = ' ';

	score = ((correct - incorrect) / MAX_SCORE) * 100; //get student precentage grade

	//get student letter grade
	if (score >= 90)
		grade = 'A';
	else if (score >= 80 && score <= 89.99)
		grade = 'B';
	else if (score >= 70 && score <= 79.99)
		grade = 'C';
	else if (score >= 60 && score <= 69.99)
		grade = 'D';
	else
		grade = 'F';

	return grade; //return letter grade - line 128
} //end getGrade

void outputToScreen(string *IDs, string *answers, char *grades, int *numOfStudents) //output the student id's, answers, and their letter grade to the screen
{
	for (int i = 0; i < *numOfStudents; i++)
	{
		cout << IDs[i] << " " << answers[i] << " " << grades[i] << endl;
	}
	cout << endl;
} //end outputToScreen