#include<iostream>
#include<mysql.h>
#include<sstream>
#include<windows.h>
#include<conio.h>
#include"staff.h"
#include"student.h"

using namespace std;


void student_insert(MYSQL* con) {

	int qstate = 0;
	stringstream ss;

	student obj;
	ss=obj.create_student();

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

void staff_insert(MYSQL* con) {

	int qstate = 0;
	stringstream ss;

	staff obj;
	ss=obj.create_staff();


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

