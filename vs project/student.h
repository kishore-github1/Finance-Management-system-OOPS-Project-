#pragma once
#include<string>
#include<mysql.h>
using namespace std;


class student
{
public:
	string id;
	string name;
	int tution_fee;
	int hostel_fee;
	int caution_deposit;
	string date;
	int paid_fee;


	void create_student();
	

};


