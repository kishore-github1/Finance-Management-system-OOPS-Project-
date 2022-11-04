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
	obj.create_student();


	ss << "INSERT INTO student (Id,Name,Tution_fee,Hostel_fee,Caution_deposit) VALUES ('" << obj.id << "','" << obj.name << "'," << obj.tution_fee << "," << obj.hostel_fee << "," << obj.caution_deposit << ")";

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
	obj.create_staff();
	

	ss << "INSERT INTO staff (Id,Name,Total_salary,Provident_fund,Health_insurance,Basic_salary) VALUES ('" <<obj.id << "','" << obj.name << "',"<<obj.total_salary<<","<<obj.provident_fund<<","<<obj.health_insurance<<"," << obj.basic_salary << ")";

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

