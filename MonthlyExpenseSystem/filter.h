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
    vector<Expense> filter_date(vector<Expense> v, int iyear, string filter_type);
    vector<Expense> filter_category(vector<Expense> v, string icategory);
    vector<Expense> filter_day(vector<Expense> v, int iday, string  filter_type);
    vector<Expense> filter_month(vector<Expense> v, int imonth, string  filter_type);
    vector<Expense> filter_year(vector<Expense> v, int iyear, string  filter_type);
    vector<Expense> filter_amount(vector<Expense> v, float amount, string  filter_type);
    vector<Expense> filter_price(vector<Expense> v, float price, string  filter_type);
    filter();
};

