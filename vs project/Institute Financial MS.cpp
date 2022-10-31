#include <iostream>
#include <conio.h>
#include<windows.h>
#include<mysql.h>
#include<sstream>
#include "connection.h"
#include "login.h"

using namespace std;



void insert(MYSQL* con) {

	int qstate = 0;
	stringstream ss;

	string name; 
	string password;
	cin >> name;
	cin >> password;
	

	ss << "INSERT INTO login_system (Username,password) VALUES ('" << name << "','" << password << "')";
	string query = ss.str();

	const char* q = query.c_str();

	qstate = mysql_query(con, q);


	if (qstate == 0) {
		cout << "Record Inserted..." << endl;
	}
	else {
		cout << "Failed" << endl;
	}

}


int main()
		{
				MYSQL* con = nullptr;
				MYSQL* connected;
				connected = connect(con);
				insert(connected);	
				login(connected);


	


	return 0;
}
