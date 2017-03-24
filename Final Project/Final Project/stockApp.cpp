#include "stockApp.h"

stockApp::stockApp() { }

void stockApp::execute()
{
	menu();
}

void stockApp::menu()
{
	char goAgain = ' ';
	int selection;

	lst.populateList();

	do {

		system("CLS");

		cout << "*********   First Investor's Heaven   *********" << endl;
		cout << "*******   Financial Reporting Software   *******" << endl << endl;

		cout << "1: Print a stock report to file" << endl;
		cout << "2: Print a stock report to screen" << endl;
		cout << "3. Print stock report to screen sorted by percentage gain" << endl;
		cout << "4. Change the input file name" << endl;
		cout << "5. Exit" << endl << endl;

		selection = getSelection("Please make a selection");
		
		system("CLS");

		switch (selection)
		{
		case 1:					
			lst.createFileReport();
			break;
		case 2:				
			lst.printScreenReport();
			break;
		case 3:
			lst.printScreenReportByGain();
			break;
		case 4:		
			lst.clearList();
			lst.setFileName(changeFileName());
			lst.populateList();
			break;		
		case 5:
			exit(0);
			break;
		default:
			cout << "An Error has occured, the program will now exit" << endl;
			exit(0);
		}

		cout << endl;
		cout << "Would you like to retun to the menu? y/n" << endl;
		cin >> goAgain;

	} while (tolower(goAgain) == 'y');

	system("CLS");
	cout << "The program will now exit" << endl << endl;
}

int stockApp::getSelection(string prompt)
{
	bool valid = false;
	string input;
	regex pattern ("^[+]?[1-5]$");
	
	do
	{
		cout << prompt << endl;
		cin >> input;

		if (!regex_match(input, pattern))
		{
			cout << "This is not a valid selection, please try again" << endl;
		}
		else
			valid = true;
	} while (!valid);

	return stoi(input);
}

string stockApp::changeFileName()
{
	string defaultFileName = "stocks.txt";
	string currentFileName = lst.getFileName();
	regex pattern("^[a-z]+\.txt$");

	cout << "The current file being read is " << currentFileName << ". If you would like to keep using this file, type exit to continue." << endl;
	cout << "If you would like to change this file, enter the name of the new file, including the file extension (must be .txt), and press enter." << endl;
	cout << "If you would like to reset the file name to the default file name of " << defaultFileName << ", type default and press enter." << endl << endl;
	cout << "Make a selection: ";
	cin >> currentFileName;
	cout << endl;

	transform(currentFileName.begin(), currentFileName.end(), currentFileName.begin(), ::tolower);

	if (currentFileName == "exit")
	{
		cout << "File name was not changed." << endl;
		return lst.getFileName();
	}
	else if (currentFileName == "default")
	{
		cout << "File name was set to default." << endl;
		return defaultFileName;
	}
	else if (regex_match(currentFileName, pattern))
	{
		cout << "The file name was changed to " << currentFileName << endl;
		return currentFileName;
	}
	else
		cout << "This is not a valid file path. Please only enter files ending in .txt." << endl << "File ame unchanged, returning to the menu" << endl;
}
