#pragma once
#include<string>
#include<mysql.h>
#include "member.h"
using namespace std;


class student: private member
{
private:

	int tution_fee;
	int hostel_fee;
	int caution_deposit;
	string date;
	int paid_fee;

public:
	stringstream create_student();
	

};


