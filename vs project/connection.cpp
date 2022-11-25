#include<mysql.h>
#include<iostream>
using namespace std;

MYSQL* connect(MYSQL* con) {


	con = mysql_init(0);
	con = mysql_real_connect(con, "localhost", "root", "kishore", "chanakya_base", 3306, NULL, 0);

	if (con) {
		cout << "Succesfull Database connection" << endl;

	}
	else {
		cout << "failed connection" << endl;
	}
	return con;
	
}
