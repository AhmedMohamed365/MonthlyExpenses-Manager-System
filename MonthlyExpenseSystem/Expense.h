#pragma once
#include <iostream>
#include <ctime>
#include<string>
#include <string.h>
#include<vector>
using namespace std;


struct exspense_info {
	string name, description, category;
	float amount, price;
	int day, month, year;
	string date;

	exspense_info()
	{

	}

	exspense_info(vector<string> info)
	{
		this->name = info[0];
		this->description = info[1];

		this->category = info[2];

		this->amount = stof(info[3]);

		this->price = stof(info[4]);
	}
	exspense_info(string name, string description, string category, float amount, float price, int day , int month,int year)
	{
		this->name = name;
		this->description = description;

		this->category = category;

		this->amount = amount;

		this->price = price;

		date = to_string(day) + '-' + to_string(month) + '-' + to_string(year);


	}
};
class Expense
{
public:
	
	//int capacity;
	//informations of expense 
	exspense_info info;


	 // int expenses_count;
public:
	Expense();

	Expense(exspense_info info);
	void display_data();
	string get_category();
	string get_data();
	//void expand();
	
	//void add_expense(string icategory, int idate, int imonth, int iyear);

};

