
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

	ss << "SELECT * FROM student WHERE id= '"<<id<<"' ";

	string query = ss.str();
	const char* q = query.c_str();

	if (!(mysql_query(con, q))) {
		res = mysql_store_result(con);

		
		while (row = mysql_fetch_row(res))

		{

			cout << "\n\n Your Id -> " << row[0];
			/*
			cout << "\n\n Your Name -> " << row[1];
			cout << "\n\n Your Email -> " << row[2];
			cout << "\n\n Your Password -> " << row[3];
			*/


		}
	}
	else
	{
		
		cout << "\n\n *** Query Failed ****";
	}

	
	

}