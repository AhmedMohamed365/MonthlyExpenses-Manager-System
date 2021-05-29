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
		date = info[0];
		description = info[1];

		category = info[2];

		amount = stof(info[3]);

		price = stof(info[4]);
		name = info[5];
		
		vector<string> dateInfo(3);
		dateInfo = FileHandler::split(info[6],"-");

		day = stoi(dateInfo[0]);

		month = stoi(dateInfo[1]);

		year = stoi(dateInfo[2]);

		
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
	string get_date();
	int get_amount();
	
	//void add_expense(string icategory, int idate, int imonth, int iyear);

};

