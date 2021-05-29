#pragma once
#include <iostream>
#include "Expense.h"
#include <vector>
#include <string>
#include "FileHandler.h"
using namespace std;

class filter
{
private:
   
public:
    vector<Expense> filter_category(vector<Expense> v, string icategory);
    vector<Expense> filter_day(vector<Expense> v, int iday);
    vector<Expense> filter_month(vector<Expense> v, int imonth);
    vector<Expense> filter_year(vector<Expense> v, int iyear);
    vector<Expense> filter_amount(vector<Expense> v, float amount);
    

    filter();
    vector<Expense> filter_all(vector<Expense> v , bool is_category , bool is_day , bool is_month , bool is_year , bool is_amount , string category = "0" , int day = -1 , int month = -1 , int year = -1 , float amount = -1);
    ~filter();
};
