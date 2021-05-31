#include <iostream>
#include "filter.h"
#include "Expense.h"
#include <vector>
#include <string>
using namespace std;
vector<Expense> filter::filter_month(vector<Expense> v, int imonth)
{
    vector<Expense> ret;



    for (int i = 0; i < v.size(); ++i) {

        if (v[i].info.month == imonth) {
            ret.push_back(v[i]);
        }
    }
    return ret;
}

vector<Expense> filter::filter_year(vector<Expense> v, int iyear)
{
    vector<Expense> ret;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i].info.year == iyear) {
            ret.push_back(v[i]);
        }
    }
    return ret;
}

vector<Expense> filter::filter_amount(vector<Expense> v, float amount, int filter_type)
{
    // 1 -> equal
    // 2-> equal or greater than
    // 3-> greater than 
    //4-> equal or less than
    //5-> less than 
    vector<Expense> ret;

    for (int i = 0; i < v.size(); ++i) {
        if (filter_type == 1) {
            if (v[i].get_amount() == amount) {
                ret.push_back(v[i]);
            }
        }
        else if (filter_type == 2) {
            if (v[i].get_amount() >= amount) {
                ret.push_back(v[i]);
            }
        }
        else if (filter_type == 3) {
            if (v[i].get_amount() <= amount) {
                ret.push_back(v[i]);
            }
        }
    }
    return ret;
}

vector<Expense> filter::filter_price(vector<Expense> v, float price, int filter_type)
{
    // 1 -> equal
    // 2-> equal or greater than
    // 3-> greater than 
    //4-> equal or less than
    //5-> less than 
    vector<Expense> ret;

    for (int i = 0; i < v.size(); ++i) {
        if (filter_type == 1) {
            if (v[i].get_price() == price) {
                ret.push_back(v[i]);
            }
        }
        else if (filter_type == 2) {
            if (v[i].get_price() >= price) {
                ret.push_back(v[i]);
            }
        }
        else if (filter_type == 3) {
            if (v[i].get_price() <= price) {
                ret.push_back(v[i]);
            }
        }
    }
    return ret;
}
filter::filter()
{

}
vector<Expense> filter::filter_category(vector<Expense> v, string icategory) {
    vector<Expense> ret;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].get_category() == icategory) {
            ret.push_back(v[i]);
        }
    }
    return ret;
}
vector<Expense> filter::filter_day(vector<Expense> v, int iday)
{
    vector<Expense> ret;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i].info.day == iday) {
            ret.push_back(v[i]);
        }
    }
    return ret;
}

filter::~filter()
{

}
