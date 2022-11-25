
#include<iostream>
#include<mysql.h>
#include<sstream>
#include<iomanip>

using namespace std;

void search(MYSQL* con) {
	string id;
	int choice;
	string table;
	stringstream ss;
	MYSQL_RES* res;
	MYSQL_ROW row;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	cout << endl << setw(30) << " " << "SEARCH" << endl;
	cout << setw(30) << " " << "------" << endl;
	SetConsoleTextAttribute(hConsole, 13);
	cout << endl << setw(25) << " " << "1.Search in Student\n" << endl;
	cout << setw(25) << " " << "2.Search in Staff" << endl << endl;

	cout << setw(25) << " " << "Enter choice: ";

	SetConsoleTextAttribute(hConsole, 15);
	cin >> choice;

	SetConsoleTextAttribute(hConsole, 13);
	cout <<endl<< setw(25) << " " << "Enter id: ";
	SetConsoleTextAttribute(hConsole, 15);
	cin >> id;

	if (choice == 1) table = "student";
	else table = "staff";

	ss << "SELECT * FROM " << table << " WHERE id= '"<<id<<"' ";

	string query = ss.str();
	const char* q = query.c_str();

	if (!(mysql_query(con, q))) {
		res = mysql_store_result(con);
		
		while (row = mysql_fetch_row(res))

		{
			cout << setw(10) << " " << "DATA" << endl;
			cout << setw(10) << " " << "____" ;

			SetConsoleTextAttribute(hConsole, 2);
			if (choice == 1) {
				
				cout << "\n\n  Id -> " << row[0];
				cout << "\n\n  Name -> " << row[1];
				cout << "\n\n  Tution Fee -> " << row[2];
				cout << "\n\n  Hostel Fee -> " << row[3];
				cout << "\n\n  Caution Deposit -> " << row[4] << endl;
				char* paid = row[5];
				if (*paid == '1') {
					cout << "\n  Fee paid" << endl;
				}
				else cout << "\n Fee not paid" << endl;

			}
			else {
				

				cout << "\n\n  Id -> " << row[0];
				cout << "\n\n  Name -> " << row[1];
				cout << "\n\n  Total Salary -> " << row[2];
				cout << "\n\n  Provident Fund -> " << row[3];
				cout << "\n\n  Health Insurance -> " << row[4] ;
				cout << "\n\n  Basic Salary -> " << row[5] << endl;
			}

			

		}
	}
	else
	{
		
		cout << "\n\n *** Query Failed ****";
	}

	
	

}