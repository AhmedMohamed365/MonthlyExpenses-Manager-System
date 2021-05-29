#include <iostream>
#include<string>
//#include "Expense.h"
//#include "FileHandler.h"
#include "filter.h"
using namespace std;
string choice = "- 1";
FileHandler handler;
bool menu();
exspense_info validData();
int main() {
	
	handler.findWallet("wallet.txt");
	vector<Expense> expenses = handler.loadWallet("wallet.txt");
	filter filter;
	expenses = filter.filter_category(expenses, "dinner");

	//expenses = filter.filter_amount(expenses, 2);

	for (int i = 0; i < expenses.size(); i++)
	{
		expenses[i].display_data();
		cout << endl;
	}
	//while (menu());
	return 0;
}
bool menu()
{
	if (choice != "- 1")
		cout << "-------------------" << endl;
	cout << "Enter 1 to enter monthly income" << endl;
	cout << "Enter 2 to enter daily expense " << endl;
	cout << "Enter 3 to view expenses" << endl;
	cout << "Enter 4 to view the remaining money " << endl;
	cout << "Enter 5 to exit " << endl;
	cin >> choice;
	if (choice == "1")
	{

		return true;
	}
	else if (choice == "2")
	{
		handler.saveExpense(validData());
		return true;
	}
	else if (choice == "3")
	{
		return true;
	}
	else if (choice == "4")
	{
		return true;
	}
	else if (choice == "5")
	{
		return false;
	}
	else
	{
		choice = "0";
		return true;
	}

}
exspense_info validData()
{
	string name, description, category;
	float amount = 0, price = 0;
	int day = 0, month = 0, year = 2020;
	cout << "Enter exspense name:";
	getline(cin, name);
	getline(cin, name);
	cout << "Enter exspense description:";
	getline(cin, description);
	cout << "Enter exspense category:";
	getline(cin, category);
	while (amount <= 0)
	{
		if (amount != 0)
			cout << "Enter valid exspense amount:";
		else
			cout << "Enter exspense amount:";
		cin >> amount;
	}
	while (price <= 0)
	{
		if (price != 0)
			cout << "Enter valid exspense price:";
		else
			cout << "Enter exspense price:";
		cin >> price;
	}
	while (day <= 0 || day > 31)
	{
		if (day != 0)
			cout << "Enter valid day:";
		else
			cout << "Enter the day:";
		cin >> day;
	}
	while (month <= 0 || month > 12)
	{
		if (month != 0)
			cout << "Enter valid month:";
		else
			cout << "Enter the month:";
		cin >> month;
	}
	while (year <= 2020 || year > 2100)
	{
		if (year != 0)
			cout << "Enter valid year:";
		else
			cout << "Enter the year:";
		cin >> year;
	}
	exspense_info info(name, description, category, amount, price, day, month, year);
	return info;
}