
#include<iostream>
#include<mysql.h>
#include<sstream>

using namespace std;

void search(MYSQL* con) {
	string id;
	int choice;
	string table;
	stringstream ss;
	MYSQL_RES* res;
	MYSQL_ROW row;
	cout << "1.Search in Student" << endl;
	cout << "2.Search in Staff" << endl;
	cin >> choice;
	cout << "Enter id" << endl;
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

			cout << "\n\n  Id -> " << row[0];	
			cout << "\n\n  Name -> " << row[1];
			cout << "\n\n  Tution Fee -> " << row[2];
			cout << "\n\n  Hostel Fee -> " << row[3];
			cout << "\n\n  Caution Deposit -> " << row[4] << endl;
			char *paid = row[5];
			if (*paid == '1') {
				cout << "Fee paid" << endl;
			}
			else cout << "Not paid" << endl;

			

		}
	}
	else
	{
		
		cout << "\n\n *** Query Failed ****";
	}

	
	

}