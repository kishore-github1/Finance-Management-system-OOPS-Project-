#include<iostream>
#include<mysql.h>
#include<sstream>

using namespace std;

void update(MYSQL* con) {
	MYSQL_ROW row;

	stringstream ss, a;
	string table;
	MYSQL_RES* res;
	string id, name;
	int hf, tf, cd;
	cin >> id;

	//ss<<"UPDATE student "

	a << "SELECT * FROM student WHERE id =  '"<< id<<"' ";
	string b = a.str();

	const char* query = b.c_str();

	if (!(mysql_query(con, query)))

	{

		res = mysql_store_result(con);
		row = mysql_fetch_row(res);
		if (row != 0)

		{
			cout << "\n\n Enter User Name -> " << endl;
			cin.ignore();
			getline(cin, name);

			cout << "\n\n Enter Hostel fee -> " << endl;

			cin >> hf;

			cout << "\n\n Enter Tution fee -> " << endl;

			cin >> tf;

			cout << "\n\n Enter caution deposit -> " << endl;

			cin >> cd;

			ss << "UPDATE student  SET name = '" << name << "', Hostel_fee = " << hf << ", Tution_fee = " << tf << ", Caution_deposit = " << cd << "  WHERE Id='" << id << "' ";

			string query = ss.str();
			const char* q = query.c_str();

			mysql_query(con, q);

		}

	}
}