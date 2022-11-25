#pragma once


#include<string>
#include<mysql.h>
#include"fixedAssets.h"
#include"expFunds.h"



using namespace std;

class funds:private expFunds,private fixedAssets {

public:
	stringstream createFund(int choice,string month);

};