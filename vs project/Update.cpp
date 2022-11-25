#include<iostream>
#include<mysql.h>
#include<sstream>
#include<iomanip>

using namespace std;

void update(MYSQL* con) {


	MYSQL_ROW row;
	stringstream ss, a;
	MYSQL_RES* res;
	string id, name;
	int hf, tf, cd,bs,choice;
	string iquery;
	const char* iq;
	string table;
	int choice1;
	int qstate = 0;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	cout <<endl<< setw(30) << " " << "UPDATE" << endl;
	cout << setw(30) << " " << "------" << endl << endl;

	SetConsoleTextAttribute(hConsole, 13);

	cout << setw(30) << " " << "1.Student Update" << endl;
	cout << setw(30) << " " << "2.Staff update" << endl;
	cout << "Enter choice: ";
	SetConsoleTextAttribute(hConsole, 15);
	cin >> choice1;
	SetConsoleTextAttribute(hConsole, 13);
	if (choice1 == 1) {
		table = "student";
		cout << "\n\t1.Update Name\n\t2.Update Tution fee\n\t3.Update Hostel fee\n\t4.Update Caution deposit\n\t5.Update all" << endl;
		cout << "\nEnter choice: ";
		SetConsoleTextAttribute(hConsole, 15);
		cin >> choice;

	}


	else {
		table = "staff";
		cout << "\n\t1.Update Name\n\t2.Update Total Salary\n\t3.Update Provident Fund\n\t4.Health Insurance\n\t5.Basic Salary\n\t6.Update all " << endl;
		cout << "\nEnter choice: ";
		SetConsoleTextAttribute(hConsole, 15);
		cin >> choice;
	}
	
	SetConsoleTextAttribute(hConsole, 13);
	cout << "\nEnter Id: ";
	SetConsoleTextAttribute(hConsole, 15);
	cin >> id;
	SetConsoleTextAttribute(hConsole, 13);
	
	a << "SELECT * FROM " << table << " WHERE Id = '" << id << "' ";
	string b = a.str();
	const char* query = b.c_str();	


	if (!(mysql_query(con, query))) {

		res = mysql_store_result(con);
		row = mysql_fetch_row(res);
		if (row != 0)

		{
			if (choice1 == 1) {

				switch (choice) {
				
				case 1:
					cout << "\nEnter Student Name -> " << endl;
					SetConsoleTextAttribute(hConsole, 15);
					cin.ignore();
					getline(cin, name);

					ss << "UPDATE " << table << "  SET name = '" << name << "'   WHERE Id='" << id << "' ";

					iquery = ss.str();
					iq = iquery.c_str();
					qstate=mysql_query(con, iq);

					break;

				case 2:
					cout << "\nEnter Tution Fee -> " << endl;
					SetConsoleTextAttribute(hConsole, 15);
					cin >> tf;

					ss << "UPDATE " << table << " SET Tution_fee = " << tf << "   WHERE Id='" << id << "' ";

					iquery = ss.str();
					iq = iquery.c_str();
					qstate = mysql_query(con, iq);


					break;

				case 3:
					cout << "\nEnter Hostel Fee -> " << endl;
					SetConsoleTextAttribute(hConsole, 15);
					cin >> hf;

					ss << "UPDATE " << table << "  SET Hostel_fee = '" << hf << "'  WHERE Id='" << id << "' ";

					iquery = ss.str();
					iq = iquery.c_str();
					qstate = mysql_query(con, iq);


					break;

				case 4:
					cout << "\nEnter Caution deposit -> " << endl;
					SetConsoleTextAttribute(hConsole, 15);
					cin >> cd;

					ss << "UPDATE " << table << "  SET Caution_deposit = '" << cd << "'    WHERE Id='" << id << "' ";

					iquery = ss.str();
					iq = iquery.c_str();
					qstate = mysql_query(con, iq);


					break;

				case 5:

					cout << "\nEnter Student Name -> " << endl;
					SetConsoleTextAttribute(hConsole, 15);
					cin.ignore();
					getline(cin, name);
					SetConsoleTextAttribute(hConsole, 13);

					cout << "\nEnter Hostel fee -> " << endl;
					SetConsoleTextAttribute(hConsole, 15);

					cin >> hf;
					SetConsoleTextAttribute(hConsole, 13);
					cout << "\nEnter Tution fee -> " << endl;
					SetConsoleTextAttribute(hConsole, 15);
					cin >> tf;
					SetConsoleTextAttribute(hConsole, 13);
					cout << "\nEnter caution deposit -> " << endl;
					SetConsoleTextAttribute(hConsole, 15);
					cin >> cd;

					ss << "UPDATE " << table << "  SET name = '" << name << "', Hostel_fee = " << hf << ", Tution_fee = " << tf << ", Caution_deposit = " << cd << "  WHERE Id='" << id << "' ";

					 iquery = ss.str();
					 iq = iquery.c_str();

					 qstate = mysql_query(con, iq);

					break;

				
					

				}
				

			}

			else {

				switch (choice) {

				case 1:
					cout << "\nEnter Staff Name -> " << endl;
					cin.ignore();
					SetConsoleTextAttribute(hConsole, 15);
					getline(cin, name);

					ss << "UPDATE " << table << "  SET Name = '" << name << "'   WHERE Id='" << id << "' ";

					iquery = ss.str();
					iq = iquery.c_str();
					qstate = mysql_query(con, iq);

					break;

				case 2:
					cout << "\nEnter Total Salary -> " << endl;
					SetConsoleTextAttribute(hConsole, 15);
					cin >> tf;

					ss << "UPDATE " << table << " SET Total_salary = " << tf << "   WHERE Id='" << id << "' ";

					iquery = ss.str();
					iq = iquery.c_str();
					qstate = mysql_query(con, iq);


					break;

				case 3:
					cout << "\nEnter Provident Fund -> " << endl;
					SetConsoleTextAttribute(hConsole, 15);
					cin >> hf;

					ss << "UPDATE " << table << "  SET Provident_fund = '" << hf << "'  WHERE Id='" << id << "' ";

					iquery = ss.str();
					iq = iquery.c_str();
					qstate = mysql_query(con, iq);


					break;

				case 4:
					cout << "\nEnter Health Insurance -> " << endl;
					SetConsoleTextAttribute(hConsole, 15);
					cin >> cd;

					ss << "UPDATE " << table << "  SET Health_insurance = '" << cd << "'    WHERE Id='" << id << "' ";

					iquery = ss.str();
					iq = iquery.c_str();
					qstate = mysql_query(con, iq);


					break;

				case 5:
					cout << "\nEnter Basic Salary -> " << endl;
					SetConsoleTextAttribute(hConsole, 15);
					cin >> bs;

					ss << "UPDATE " << table << "  SET Basic_salary = '" << bs << "'    WHERE Id='" << id << "' ";

					iquery = ss.str();
					iq = iquery.c_str();
					qstate = mysql_query(con, iq);

					break;

				case 6:
					cout << "\nEnter Staff Name -> " << endl;
					SetConsoleTextAttribute(hConsole, 15);
					cin.ignore();
					getline(cin, name);
					SetConsoleTextAttribute(hConsole, 13);
					cout << "\nEnter Total Salary -> " << endl;
					SetConsoleTextAttribute(hConsole, 15);
					cin >> hf;
					SetConsoleTextAttribute(hConsole, 13);
					cout << "\nEnter Provident Fund -> " << endl;
					SetConsoleTextAttribute(hConsole, 15);
					cin >> tf;
					SetConsoleTextAttribute(hConsole, 13);
					cout << "\nEnter Health Insurance -> " << endl;
					SetConsoleTextAttribute(hConsole, 15);
					cin >> cd;
					SetConsoleTextAttribute(hConsole, 13);
					cout << "\nEnter Basic Salary -> " << endl;
					SetConsoleTextAttribute(hConsole, 15);
					cin >> bs;



					ss << "UPDATE " << table << "  SET Name = '" << name << "', Total_salary = " << hf << ", Provident_fund = " << tf << ", Health_insurance = " << cd << ", Basic_salary="<<bs<<"  WHERE Id = '" << id << "' ";

					 iquery = ss.str();
					 iq = iquery.c_str();

					 qstate = mysql_query(con, iq);

					break;


				

				}

			}
			if (qstate == 0) cout << "\nUpdated succesfully..." << endl;
		}
	}


	else cout << "Query failed" << endl;
}

