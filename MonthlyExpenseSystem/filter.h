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
    vector<Expense> filter_amount(vector<Expense> v, float amount, int filter_type);
    vector<Expense> filter_price(vector<Expense> v, float price, int filter_type);
    filter();
    ~filter();
};
