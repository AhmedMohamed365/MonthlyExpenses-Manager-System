#include <iostream>
#include "filter.h"
#include "Expense.h"
#include <vector>
#include <string>
using namespace std;
filter::filter()
{

}
vector<Expense> filter::filter_amount(vector<Expense> v, float amount, string filter_type)
{
    vector<Expense> ret;
    for (int i = 0; i < v.size(); ++i) {
        if (filter_type == "=")
        {
            if (v[i].info.amount == amount)
                ret.push_back(v[i]);
        }

        else if (filter_type == "<>") {
            if (v[i].info.amount != amount)
                ret.push_back(v[i]);
        }
        else if (filter_type == ">=") {
            if (v[i].info.amount >= amount)
                ret.push_back(v[i]);
        }
        else if (filter_type == "<=") {
            if (v[i].info.amount <= amount)
                ret.push_back(v[i]);
        }
        else if (filter_type == "<")
        {
            if (v[i].info.amount < amount)
                ret.push_back(v[i]);
        }
        else if (filter_type == ">")
        {
            if (v[i].info.amount > amount)
                ret.push_back(v[i]);
        }
        }
    return ret;
}
vector<Expense> filter::filter_price(vector<Expense> v, float price, string filter_type)
{
    vector<Expense> ret;
        for (int i = 0; i < v.size(); ++i) {
            if (filter_type == "=")
                if (v[i].info.price == price)
                    ret.push_back(v[i]);
            if (filter_type == "<>") 
                if (v[i].info.price != price)
                    ret.push_back(v[i]);
            else if (filter_type == ">=") 
                if (v[i].info.price >= price)
                    ret.push_back(v[i]);
            else if (filter_type == "<=") 
                if (v[i].info.price <= price)
                    ret.push_back(v[i]);
            
            else if (filter_type == "<") 
                if (v[i].info.price < price)
                    ret.push_back(v[i]);

            else if (filter_type == ">") 
                if (v[i].info.price > price)
                    ret.push_back(v[i]);
        }
        return ret;
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
vector<Expense> filter::filter_day(vector<Expense> v, int iday, string filter_type)
{
    vector<Expense> ret;

    for (int i = 0; i < v.size(); ++i) {
        if (filter_type == "=")
            if (v[i].info.day == iday)
                ret.push_back(v[i]);
        if (filter_type == "<>")
            if (v[i].get_price() != iday)
                ret.push_back(v[i]);
        else if (filter_type == ">=")
             if (v[i].get_price() >= iday)
                 ret.push_back(v[i]);
         else if (filter_type == "<=")
             if (v[i].get_price() <= iday)
                   ret.push_back(v[i]);
         else if (filter_type == "<")
             if (v[i].get_price() < iday)
                   ret.push_back(v[i]);
         else if (filter_type == ">")
             if (v[i].get_price() > iday)
                   ret.push_back(v[i]);
    }
    return ret;
}
vector<Expense> filter::filter_month(vector<Expense> v, int imonth, string filter_type)
{
    vector<Expense> ret;
    for (int i = 0; i < v.size(); ++i) {

        if (v[i].get_month() == imonth) {
            ret.push_back(v[i]);
        }
    }
    return ret;
}
vector<Expense> filter::filter_year(vector<Expense> v, int iyear, string filter_type)
{
    vector<Expense> ret;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i].get_year() == iyear) {
            ret.push_back(v[i]);
        }
    }
    return ret;
}
