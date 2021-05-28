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

filter::~filter()
{

}
