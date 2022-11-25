#include<iostream>
#include<mysql.h>
#include<sstream>
#include<iomanip>


using namespace std;

void PayStudentFee(MYSQL* con) {
	
	stringstream ss,a;
	string id;
	MYSQL_RES* res;
	MYSQL_ROW row;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << setw(20) << " " << "PAY STUDENT FEE" << endl;
	cout << setw(20) << " " << "---------------" << endl;
	SetConsoleTextAttribute(hConsole, 13);
	cout << "\n\tEnter Student Id: ";
	SetConsoleTextAttribute(hConsole, 15);
	cin >> id;
	


	ss << "SELECT * FROM student  WHERE Id= '" << id << "' ";


	string query = ss.str();
	const char* q = query.c_str();
	

	if (!(mysql_query(con, q))) {

		res = mysql_store_result(con);
		row = mysql_fetch_row(res);

		if (row != 0)

		{
			SetConsoleTextAttribute(hConsole, 11);
			cout <<endl<<setw(5)<<" " << "CONFIRMATION" << endl;
			char choice;
			SetConsoleTextAttribute(hConsole, 13);
			cout << "\nTution Fee:" << row[2] << endl;
			cout << "Hostel Fee:" << row[3]<<endl;
			cout << "Do you want to pay?\tEnter Y/N:" << endl;
			SetConsoleTextAttribute(hConsole, 15);
			cin >> choice;

			if (choice == 'y' || choice == 'Y') {

				a << "UPDATE student SET paid_fee = 1 WHERE Id = '" << id << "' ";
				string iquery = a.str();
				const char* iq = iquery.c_str();

				if (!(mysql_query(con, iq))) cout << "Fee paid.." << endl;
				else cout << "Query Failed" << endl;
			}
			else {
				cout << "Fee Not Paid" << endl;
				return;
			}
		}
	}

	else cout << "Query failed" << endl;


}