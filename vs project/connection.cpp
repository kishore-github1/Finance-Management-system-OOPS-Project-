#include<mysql.h>
#include<iostream>
using namespace std;

MYSQL* connect(MYSQL* con) {


	con = mysql_init(0);
	con = mysql_real_connect(con, "localhost", "root", "", "chanakya_base", 8111, NULL, 0);

	if (con) {
		cout << "succesfull connection" << endl;

	}
	else {
		cout << "failed connection" << endl;
	}
	return con;
}
