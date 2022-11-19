#include<iostream>
#include<mysql.h>
#include<sstream>

using namespace std;

void PayStudentFee(MYSQL* con) {
	
	stringstream ss,a;
	string id;
	MYSQL_RES* res;
	MYSQL_ROW row;

	cout << "Enter Student Id" << endl;
	cin >> id;


	ss << "SELECT * FROM student  WHERE Id= '" << id << "' ";


	string query = ss.str();
	const char* q = query.c_str();
	

	if (!(mysql_query(con, q))) {

		res = mysql_store_result(con);
		row = mysql_fetch_row(res);

		if (row != 0)

		{
			char choice;
			cout << "Tution Fee:" << row[2] << endl;
			cout << "Hostel Fee:" << row[3]<<endl;
			cout << "Pay?\nEnter y/Y" << endl;
			cin >> choice;

			if (choice == 'y' || choice == 'Y') {

				a << "UPDATE student SET paid_fee = 1 WHERE Id = '" << id << "' ";
				string iquery = a.str();
				const char* iq = iquery.c_str();

				if (!(mysql_query(con, iq))) cout << "Fee paid" << endl;
				else cout << "Query Failed" << endl;
			}
		}
	}

	else cout << "Query failed" << endl;


}