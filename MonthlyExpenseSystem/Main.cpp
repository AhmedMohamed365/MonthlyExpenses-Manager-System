#include <iostream>
#include<string>
#include "Expense.h"
#include "FileHandler.h"
#include "filter.h"
using namespace std;
int main() {

	filter filter;
	exspense_info info("EGGS", "I bought it to to make omlets \n  I want to help in making that", "mufin",2, 1, 5 , 11 , 2020);
	Expense expense(info);
	
	
	
	FileHandler handler;
	
	
	handler.saveExpense(info);
	handler.saveExpense(info);
	handler.saveExpense(info);
	handler.countExpenses();
	vector<Expense> expenses = handler.loadWallet("wallet.txt");

	expenses = filter.filter_category(expenses, "dinner");

	for (int i = 0; i < expenses.size(); i++)
	{
		expenses[i].display_data();
		cout << endl;
	}
	
	return 0;
}



/*
it was test




cout << "Hello" << endl;
	Expense exsystem;
	char exit = 'f';
	while (exit != 't') {
		cout << endl; cout << endl;
		string name;
		int day, month, year;
		cout << "please add exspense name" << endl;
		cin >> name;
		cout << "please add day" << endl;
		cin >> day;
		cout << "please add month" << endl;
		cin >> month;
		cout << "please add year" << endl;
		cin >> year;
		exsystem.add_expense(name, day, month, year);
		cout << "if you want to display exspenses press 1 else press 2 " << endl;
		int ans;
		cin >> ans;
		if (ans == 1)
			exsystem.display_data();
		cout << "if you want to add exspenses press a" << endl;
		cout << "if you want to exit press t" << endl;
		cin >> exit;
	}


*/