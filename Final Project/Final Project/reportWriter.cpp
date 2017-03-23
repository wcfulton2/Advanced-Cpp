//#include "reportWriter.h"
//
//
//reportWriter::reportWriter()
//{ 
//	
//}
//
//void reportWriter::createFileReport(listType<stockType> t)
//{
//		ofstream file;
//		file.open("output.txt");
//		stockType temp;
//
//		createHeader(file);
//
//		for (int i = 0; i < t.getLength(); i++)
//		{
//			temp = t.getAt(i);
//
//			file << temp;
//		}//end for
//
//		createFooter(file);
//
//
//		file.flush();
//		file.close();
//
//	//cout << "hit";
//
//} //end createFileReport
//
//void reportWriter::printStockReport()
//{
//		stockType temp;
//	
//		createHeader(cout);
//	
//		for (int i = 0; i < t.getLength(); i++)
//		{
//			temp = t.getAt(i);
//	
//			cout << temp;
//		}//end for
//	
//		createFooter(cout);
//		cout << endl;
//}
//
//void reportWriter::createHeader(ostream& file)
//{
//	file << "*********   First Investor's Heaven   *********" << endl;
//	file << "*********      Financial Report        *********" << endl;
//	file << "Stock              Today                  Previous  Percent" << endl;
//	file << "Symbol   Open    Close    High     Low    Close     Gain        Volume" << endl;
//	file << "------   -----   -----    -----    -----  --------  -------      ------" << endl;
//} //end createHeader
//
//void reportWriter::createFooter(ostream & file)
//{
//	file << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
//} //end createFooter
