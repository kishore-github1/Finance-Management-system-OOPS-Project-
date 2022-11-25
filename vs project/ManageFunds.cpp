#include<iostream>
#include<mysql.h>
#include<sstream>
#include"funds.h"

using namespace std;

void ManageFunds(MYSQL *con) {
	MYSQL_ROW row;
	stringstream ss, a;
	MYSQL_RES* res;
	string table,month;
	int choice,choice1;


	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);

	cout <<endl<< "Manage Funds of the Month:\n1.Jan\n2.Feb\n3.Mar\n4.Apr\n5.May\n6.Jun\n7.Jul\n8.Aug\n9.Sep\n10.Oct\n11.Nov\n12.Dec" << endl;
	cout << "\nEnter here: ";
	SetConsoleTextAttribute(hConsole, 15);
	cin >> choice1;

	if (choice1 == 1) month = "1.JAN";
	else if (choice1 == 2) month = "2.FEB";
	else if (choice1 == 3) month = "3.MAR";
	else if (choice1 == 4) month = "4.APR";
	else if (choice1 == 5) month = "5.MAY";
	else if (choice1 == 6) month = "6.JUN";
	else if (choice1 == 7) month = "7.JUL";
	else if (choice1 == 8) month = "8.AUG";
	else if (choice1 == 9) month = "9.SEP";
	else if (choice1 == 10) month = "A.OCT";
	else if (choice1 == 11) month = "B.NOV";
	else month = "C.DEC"; 

	SetConsoleTextAttribute(hConsole, 15);
	cout << "\n1.Staff Payments\n2.Projects Expenditures\n3.Repairs and Maintenance\n4.Other Expenses" << endl;
	cout << "5.Office Equipment\n6.Library Costs\n7.Sports Equipment\n8.Buildings" << endl;

	SetConsoleTextAttribute(hConsole, 13);
	cout << "\nEnter here: ";
	
	SetConsoleTextAttribute(hConsole, 15);
	cin >> choice;
	SetConsoleTextAttribute(hConsole, 13);
	if (choice == 1 || choice == 2 || choice == 3 || choice == 4) {
		table = "expenditure_funds";
	}
	else {
		table = "fixed_assets";

	}

	funds obj;
	ss = obj.createFund(choice, month);

	a << "SELECT * FROM " << table << " WHERE Month = '" << month << "' ";
	string query = a.str();
	const char* q = query.c_str();


	if (!(mysql_query(con, q))) {

		res = mysql_store_result(con);
		row = mysql_fetch_row(res);
		if (row != 0)

		{
			string iquery = ss.str();
			const char* iq = iquery.c_str();
			mysql_query(con, iq);
			cout << "\nRecord inserted...." << endl;


		}
	}


	
}