#include <iostream>
#include "filter.h"
#include "Expense.h"
#include <vector>
#include <string>
using namespace std;

filter::filter()
{

}
vector<Expense> filter::filter_category(vector<Expense> v , string icategory) {
    vector<Expense> ret;
    for (int i = 0 ; i<v.size() ; ++i) {
        if (v[i].get_category() == icategory) {
            ret.push_back(v[i]);
        }
    }
    return ret;
}
vector<Expense> filter::filter_day(vector<Expense> v , int iday) {
    vector<Expense> ret;
    for (int i = 0 ; i<v.size() ; ++i) {
        if (v[i].get_day() == iday) {
            ret.push_back(v[i]);
        }
    }
    return ret;
}
vector<Expense> filter::filter_month(vector<Expense> v , int imonth) {
    vector<Expense> ret;
    for (int i = 0 ; i<v.size() ; ++i) {
        if (v[i].get_month() == imonth) {
            ret.push_back(v[i]);
        }
    }
    return ret;
}
vector<Expense> filter::filter_year(vector<Expense> v , int iyear) {
    vector<Expense> ret;
    for (int i = 0 ; i<v.size() ; ++i) {
        if (v[i].get_year() == iyear) {
            ret.push_back(v[i]);
        }
    }
    return ret;
}
vector<Expense> filter::filter_amount(vector<Expense> v , float iamount) {
    vector<Expense> ret;
    for (int i = 0 ; i<v.size() ; ++i) {
        if (v[i].get_amount() == iamount) {
            ret.push_back(v[i]);
        }
    }
    return ret;
}
vector<Expense> filter::filter_all(vector<Expense> v , bool is_category , bool is_day , bool is_month , bool is_year , bool is_amount , string icategory , int iday , int imonth , int iyear , float iamount) {
    vector<Expense> ret = v;
    if (is_category) {
        ret = filter::filter_category(ret , icategory);
    }
    if (is_day) {
        ret = filter::filter_day(ret , iday);
    }
    if (is_month) {
        ret = filter::filter_month(ret , imonth);
    }
    if (is_year) {
        ret = filter::filter_year(ret , iyear);
    }
    if (is_amount) {
        ret = filter::filter_amount(ret , iamount);
    }
    return ret;
}
filter::~filter()
{

}
