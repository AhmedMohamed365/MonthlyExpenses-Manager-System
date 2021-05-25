#pragma once
#include <iostream>
#include <ctime>
#include<string>
#include <string.h>

using namespace std;

class Expense
{
public:
	struct exspense_info {
		string name , description , category;
		float amount  , price;
		int day, month, year;
	};
	int capacity;

	exspense_info* expenses_list;

	static  int expenses_count;
public:
	Expense();
	void display_data();
	string get_category();
	void get_date();
	//void expand();

	//void add_expense(string icategory, int idate, int imonth, int iyear);

};

