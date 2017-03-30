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

	if (fileExists(lst.getFileName())) //if the default input file exists, populate the stock object list with the data	
		lst.populateList(); //populate the list with the items in the default input file.

	else //if the default input file does not exist, display a warning message

		cout << "***Warning: the input file " << lst.getFileName() << " does not exist. " << endl <<
		"Please ensure the file is present or enter the name of a new file by selecting option 4 from the main menu." << endl << endl;


	do {

		cout << "*********   First Investor's Heaven   *********" << endl;
		cout << "*******   Financial Reporting Software   *******" << endl << endl;

		cout << "1: Print a stock reports to file" << endl;
		cout << "2: Print a stock report to screen" << endl;
		cout << "3. Print stock report to screen sorted by percentage gain" << endl;
		cout << "4. Change the input file name" << endl;
		cout << "5. Exit" << endl << endl;

		selection = getSelection("Please make a selection"); //get a valid user menu selection

		system("CLS");

		switch (selection) //run the desired function based on user input
		{
		case 1: // create file reports
			lst.createFileReport();
			lst.createFileReportByGainLoss();
			break;
		case 2: //print report to screen
			lst.printScreenReport();
			break;
		case 3: //print report to screen sorted by gain
			lst.printScreenReportByGain();
			break;
		case 4: //change input file name
			lst.clearList();
			lst.setFileName(changeFileName());
			lst.populateList();
			break;
		case 5: //exit
			exit(0);
			break;
		default:
			cout << "An Error has occured, the program will now exit" << endl;
			exit(0);
		}

		cout << endl;
		cout << "Would you like to retun to the menu? y/n" << endl; //ask the user if they want to return to the menu. If not, exit.
		cin >> goAgain;

		system("CLS");

	} while (tolower(goAgain) == 'y'); //end do/while

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
	bool valid = false;
	string tempName;
	string defaultFileName = "stocks.txt";
	string currentFileName = lst.getFileName();
	regex pattern("^[A-za-z0-9]+\.txt$");

	cout << "The current file being read is " << currentFileName << ". If you would like to keep using this file, type exit to continue." << endl;
	cout << "If you would like to change this file, enter the name of the new file, including the file extension (must be .txt), and press enter." << endl;
	cout << "If you would like to reset the file name to the default file name of " << defaultFileName << ", type default and press enter." << endl << endl;


	do {
		cout << "Make a selection: ";
		cin >> tempName;
		cout << endl;

		transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);

		if (tempName == "exit")
		{
			tempName = currentFileName;
			cout << "File name was not changed." << endl;
			valid = true;
		}
		else if (tempName == "default")
		{
			tempName = defaultFileName;
			cout << "File name was set to default." << endl;
			valid = true;
		}
		else if (!fileExists(tempName))
		{
			cout << "The file " << tempName << " does not exist. Please try again" << endl << endl;
			valid = false;
		}
		else if (regex_match(tempName, pattern))
		{
			cout << "The file name was changed to " << tempName << endl;
			valid = true;
		}
		else
		{
			cout << "This is not a valid file path. Please only enter files ending in .txt." << endl << "File Name unchanged" << endl << endl;
			valid = false;
		}
	} while (!valid);

	return tempName;
}

bool stockApp::fileExists(const string& fileName)
{
	struct stat buffer;
	return (stat(fileName.c_str(), &buffer) == 0);
}
