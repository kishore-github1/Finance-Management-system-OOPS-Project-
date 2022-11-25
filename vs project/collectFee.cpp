#include<iostream>
#include<mysql.h>
#include<sstream>

using namespace std;

void collectFee(MYSQL *con) {
	stringstream a;
	int ttf, thf;
	MYSQL_RES* res;
	
	a << " SELECT SUM(Tution_fee) AS collect_fee FROM student WHERE paid_fee = 1 ";
	string b = a.str();
	const char* query = b.c_str();     

	
	cout << mysql_query(con, query) << endl;
	res = mysql_store_result(con) ;
	cout<<mysql_fetch_row(res)<<endl;
}