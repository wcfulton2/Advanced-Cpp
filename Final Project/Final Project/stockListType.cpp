#include "stockListType.h"

stockListType::stockListType() : listType<stockType>(), totalAssetsValue(0) { }

void stockListType::populateList()
{
	ifstream file;
	file.open(fileName);

	stockType temp;

	int i = 0;

	if (file.good() && file.is_open())
	{
		while (!file.eof())
		{
			file >> temp;
			addToList(temp);
			i++;
		}
	}
}

//int stockListType::getLength()
//{
//	return t.getLength();
//}

void stockListType::addToList(stockType obj)
{
	t.insertAt(obj, t.getLength());
}

void stockListType::clearList()
{
	//listType<stockType> t;
	t = new listType <stockType>;
}

//void stockListType::output()
//{
//	createFileReport();
//	displayStockData();
//}

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

	createFooter(file);


	file.flush();
	file.close();

	cout << "File created sucessfully" << endl;

	//reportWriter r;
	//r.createFileReport(t);

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
//
//void stockListType::printStockReport()
//{
//	reportWriter r;
//
//	r.printStockReport(t);
//}

//void stockListType::displayStockData()
//{
//	stockType temp;
//
//	createHeader(cout);
//
//	for (int i = 0; i < t.getLength(); i++)
//	{
//		temp = t.getAt(i);
//
//		cout << temp;
//	}
//
//	createFooter(cout);
//	cout << endl;
//}

double stockListType::calculateTotalAssetsValue()
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

double stockListType::getTotalAssetsValue()
{
	return this->totalAssetsValue;
}

void stockListType::setTotalAssetsValue(double totalAssetsValue)
{
	this->totalAssetsValue = totalAssetsValue;
}

void stockListType::setFileName(string fileName)
{
	this->fileName = fileName;
}

string stockListType::getFileName()
{
	return this->fileName;
}

//void stockListType::sortGainLoss()
//{
//	int length = t.getLength();
//	double min = 0;
//	double max;
//
//	int sortIndicesGainLoss[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10 - i - 1; j++)
//		{
//			if (t.getAt(j).getPercentGainLoss() < t.getAt(j+1).getPercentGainLoss())
//			{
//				//int temp = sortIndicesGainLoss[j];
//				//sortIndicesGainLoss[j] = sortIndicesGainLoss[j + 1];
//				//sortIndicesGainLoss[j + 1] = temp;
//
//				sortIndicesGainLoss[j] = j + 1;
//
//			}
//			else
//			{
//				sortIndicesGainLoss[j] = j;
//			}
//		}
//	}
//	
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << sortIndicesGainLoss[i] << endl;
//	}
//}
