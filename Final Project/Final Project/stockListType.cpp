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
	file.open("output.txt");
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

	cout << "File created sucessfully" << endl;
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