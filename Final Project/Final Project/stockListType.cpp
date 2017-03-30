#include "stockListType.h"

stockListType::stockListType() : listType<stockType>(), totalAssetsValue(0) { }

void stockListType::populateList()
{
	ifstream file;
	file.open(fileName);

	int lines = countLines();
	int i = 0;

	stockType temp;	

	if (file.good() && file.is_open())
	{	
		while (!file.eof() && i < lines)
		{
			file >> temp;
			addToList(temp);
			i++;
		}
	}
	file.close();

	t.sort();
}

int stockListType::countLines()
{
	int lines = 0;
	string s = "";

	ifstream file;
	file.open(fileName);

	if (file.good() && file.is_open())
	{

		while (!file.eof())
		{
			getline(file, s);
			s.erase(remove_if(s.begin(), s.end(), isspace), s.end()); //eliminate all spaces from the read lines

			if (!s.empty())
			{
				lines++;
				s = "";
			}
		}
	}

	return lines;
}

void stockListType::addToList(stockType obj)
{
	t.insertAt(obj, t.getLength());
}

void stockListType::clearList()
{
	t.clear();
}

string stockListType::getFileName()
{
	return this->fileName;
}

double stockListType::getTotalAssetsValue()
{
	stockType temp;
	double totalAssetsValue = 0;

	for (int i = 0; i < t.getLength(); i++)
	{
		temp = t.getAt(i);

		totalAssetsValue += (temp.getNumOfShares() * temp.getClosingPrice());
	}

	return totalAssetsValue;
}

void stockListType::setFileName(string fileName)
{
	this->fileName = fileName;
}

void stockListType::createFileReport()
{	
	ofstream file;
	file.open("Stock Report - By Symbol.txt");
	stockType temp;

	createHeader(file);

	for (int i = 0; i < t.getLength(); i++)
	{
		temp = t.getAt(i);

		file << temp;
	}//end for

	file << "Closing Assets: $" << getTotalAssetsValue() << endl;

	createFooter(file);


	file.flush();
	file.close();

	cout << "Files created sucessfully" << endl;
}

void stockListType::printScreenReport()
{
	stockType temp;

	createHeader(cout);

	for (int i = 0; i < t.getLength(); i++)
	{
		temp = t.getAt(i);

		cout << temp;
	}//end for

	cout << "Closing Assets: $" << getTotalAssetsValue() << endl;

	createFooter(cout);
}

void stockListType::createFileReportByGainLoss() //create a report file from the stock data sorted by gain/loss. By Bill Fulton
{
	ofstream file;
	file.open("Stock Report - By Gain.txt");
	stockType temp;

	int* sortIndicesGainLoss = new int[t.getLength()];

	sortIndicesGainLoss = sortGainLoss(); //create a list of indices for the stock data sorted by percentage gain

	createHeader(file); //create the file header

	for (int i = 0; i < t.getLength(); i++) //iterate over the stock data objects sorted by their gain
	{
		temp = t.getAt(sortIndicesGainLoss[i]);

		file << temp; //output to file using the overloaded stream insertion operator
	}//end for

	file << "Closing Assets: $" << getTotalAssetsValue() << endl; //add the value of all stock assets to the report

	createFooter(file); //create the file footer


	file.flush(); //flush the file stream
	file.close(); //close the file
} //end createFileReportByGainLoss

void stockListType::printScreenReportByGain()
{
	stockType temp;
	
	int* sortIndicesGainLoss = new int[t.getLength()];

	sortIndicesGainLoss = sortGainLoss();

	createHeader(cout);

	for (int i = 0; i < t.getLength(); i++)
	{
		temp = t.getAt(sortIndicesGainLoss[i]);

		cout << temp;
	}//end for	

	cout << "Closing Assets: $" << getTotalAssetsValue() << endl;

	createFooter(cout);
}

void stockListType::createHeader(ostream & file)
{
	file << "*********   First Investor's Heaven   *********" << endl;
	file << "*********      Financial Report        *********" << endl;
	file << "Stock              Today                  Previous  Percent" << endl;
	file << "Symbol   Open    Close    High     Low    Close     Gain        Volume" << endl;
	file << "------   -----   -----    -----    -----  --------  -------      ------" << endl;
}

void stockListType::createFooter(ostream & file)
{
	file << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
}

int* stockListType::sortGainLoss()
{
	double min = 0;
	double max;

	int* sortIndicesGainLoss = new int[t.getLength()];

	for (int i = 0; i < t.getLength(); i++)
		sortIndicesGainLoss[i] = i;


	for (int i = 0; i < t.getLength(); i++)
	{
		for (int j = 0; j < t.getLength() - 1; j++)
		{
			if (t.getAt(sortIndicesGainLoss[j]).getPercentGainLoss() < t.getAt(sortIndicesGainLoss[j + 1]).getPercentGainLoss())
			{
				int temp = sortIndicesGainLoss[j];
				sortIndicesGainLoss[j] = sortIndicesGainLoss[j + 1];
				sortIndicesGainLoss[j + 1] = temp;
			}
		}
	}

	return sortIndicesGainLoss;
}