#include<iostream>
#include<mysql.h>
#include<sstream>

using namespace std;

void update(MYSQL* con) {
	MYSQL_ROW row;

	stringstream ss, a;
	//string table;
	MYSQL_RES* res;
	string id, name;
	int hf, tf, cd,choice;
	string iquery;
	const char* iq;
	string table;
	int choice1;

	cout << "1.Student Update\n2.Staff update" << endl; 
	cin >> choice1;
	if (choice1 == 1) {
		table = "student";
		cout << "1.Update Name\n2.Update Tution fee\n3.Update Hostel fee\n4.Update Caution deposit\n5.Update all" << endl;
		cin >> choice;

	}

	else table = "staff";
	

	cout << "Enter Id" << endl;
	cin >> id;
	
	a << "SELECT * FROM " << table << " WHERE Id = '" << id << "' ";
	string b = a.str();
	const char* query = b.c_str();


	if (!(mysql_query(con, query))) {


		res = mysql_store_result(con);
		row = mysql_fetch_row(res);
		if (row != 0)

		{
			switch (choice) {

			case 1:
				cout << "\n\n Enter User Name -> " << endl;
				cin.ignore();
				getline(cin, name);

				ss << "UPDATE " << table << "  SET name = '" << name << "'   WHERE Id='" << id << "' ";

				iquery = ss.str();
				iq = iquery.c_str();
				mysql_query(con, iq);

				break;

			case 2:
				cout << "\n\n Enter Tution Fee -> " << endl;
				cin >> tf;

				ss << "UPDATE " << table << " SET Tution_fee = " << tf << "   WHERE Id='" << id << "' ";

				iquery = ss.str();
				iq = iquery.c_str();
				mysql_query(con, iq);


				break;

			case 3:
				cout << "\n\n Enter Hostel Fee -> " << endl;
				cin >> hf;

				ss << "UPDATE " << table << "  SET Hostel_fee = '" << hf << "'  WHERE Id='" << id << "' ";

				iquery = ss.str();
				iq = iquery.c_str();
				mysql_query(con, iq);


				break;

			case 4:
				cout << "\n\n Enter Caution deposit -> " << endl;
				cin >> cd;

				ss << "UPDATE " << table << "  SET Caution_deposit = '" << cd << "'    WHERE Id='" << id << "' ";

				iquery = ss.str();
				iq = iquery.c_str();
				mysql_query(con, iq);


				break;

			case 5:

				cout << "\n\n Enter User Name -> " << endl;
				cin.ignore();
				getline(cin, name);

				cout << "\n\n Enter Hostel fee -> " << endl;

				cin >> hf;

				cout << "\n\n Enter Tution fee -> " << endl;

				cin >> tf;

				cout << "\n\n Enter caution deposit -> " << endl;

				cin >> cd;

				ss << "UPDATE " << table << "  SET name = '" << name << "', Hostel_fee = " << hf << ", Tution_fee = " << tf << ", Caution_deposit = " << cd << "  WHERE Id='" << id << "' ";

				string query = ss.str();
				const char* q = query.c_str();

				mysql_query(con, q);

				break;



			}

		}
	}
	else cout << "Query failed" << endl;
}

