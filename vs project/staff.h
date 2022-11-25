#pragma once
#include<string>
#include "member.h"
using namespace std;

class staff:private member
{
private:

		int total_salary;
		int provident_fund;
		int health_insurance;
		int basic_salary;
		string date;
public:

	    stringstream create_staff();

};

