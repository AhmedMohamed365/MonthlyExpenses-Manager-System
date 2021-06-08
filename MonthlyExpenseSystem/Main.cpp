#include <iostream>
#include<string>
#include <stdlib.h>
//#include "Expense.h"
#include "FileHandler.h"
#include "filter.h"
using namespace std;
string choice = "-1";
FileHandler handler;
bool menu();
exspense_info validData();
void LoadWithFilter(string currentWallet);


//current wallet file
string currentWallet = "cash.txt";

// is it working ? 
int main() {

	system("Color F0");
	cout << "\t\t\t ****Welcome to Montly Expense System****\t\t\t " << endl;
	cout << "\t\t\t  ***                MENU           ***\t\t\t  " << endl;
	while (menu());
	return 0;
}



bool menu()
{
	if (choice != "-1")
		cout << "-------------------" << endl;
	cout << "Enter 1 to change your  monthly income" << endl;
	cout << "Enter 2 to enter daily expense " << endl;
	cout << "Enter 3 to view expenses" << endl;
	cout << "Enter 4 to view the remaining money " << endl;
	cout<< "Enter 5 to insert money to a wallet " << endl;
	cout << "Enter 6 to exit " << endl;
	cin >> choice;
	if (choice == "1")
	{
		// this code update the montly income to new one
		string walletName = "";
		
		cout << "Enter the wallet name to save a new wallet with it's income\n ";

		vector<string> choices = handler.scanAllWallets();
		cout << endl;

		cin >> walletName;
		int choice = stoi(walletName);
		for (int i = 1; i < choices.size()+1; i++)
			if (choice == i)
			{
				walletName = choices[i-1];

				break;
			}
		float income = 0;

		cin >> income;

		if (income > 0)
		{
			// maybe Income should be in wallet constructor ? 
			if(walletName.find(".txt")==-1)//:
				walletName = walletName + ".txt";

			Wallet wallet(walletName,income);
			wallet.saveIncome(income);

			float loaded = wallet.loadIncome(walletName);
			if (income == loaded )
			{
				cout << "\nyour income is saved and loaded correctly" << loaded;
			}
		}
	

		return true;
	}
	else if (choice == "2")
	{
		
		currentWallet = handler.chooseWalletFile();
		while (choice == "2")
		{

			handler.saveExpense(currentWallet,validData());
			cout << "if you want to add another expense enter y" << endl;
			cout << "if not enter n" << endl;
			cin >> choice;

			if (choice == "y"|| choice == "Y")
				choice = "2";
		}
		return true;
	}
	else if (choice == "3")
	{
		LoadWithFilter(currentWallet);
		return true;
	}
	else if (choice == "4")
	{
		system("Color FC");
		
		// I will add here to choose total money or  view remaining for one wallet only 
		cout << "your ramaining money is : ";
		Wallet wallet;
		cout << wallet.loadIncome(currentWallet) - handler.totalExpenses(currentWallet) << "LE" << endl;
		//This gets all money from all wallets - all expenses from all wallets 
		cout << Wallet::getTotalMoney() - handler.totalPrices()<<"LE" << endl;
		return true;
	}

	else if (choice == "5")
	{
		//this code edit the income  :  income += increase
		string walletName = "";

		cout << " choose the number of the  wallet to edit it\n";

		vector<string> walletsNames = handler.scanAllWallets();
		cout << endl;

		cin >> walletName;
		int chosenWallet = stoi(walletName);
		for (int i = 1; i < walletsNames.size()+1; i++)

			if (chosenWallet == i)
			{
				walletName = walletsNames[i - 1];

				break;
			}

		float income = 0;

		cin >> income;
	

		if (income > 0)
		{
			// maybe Income should be in wallet constructor ? 
			if (walletName.find(".txt") == -1)//:
				walletName = walletName + ".txt";

			Wallet wallet;
			wallet.increaseIncome(income, walletsNames ,chosenWallet );

			float loaded = wallet.loadIncome(walletName);
			//green color
			system("Color F2");
				cout << "\nyour income is saved and loaded correctly it's now : " << loaded;
			
		}
	}
	else if (choice == "6")
	{
		system("Color F2");
		cout << "good bye"<<endl;
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
	int day = 0, month = 0, year = 0;
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
	if ((amount*price) > (Wallet ::getTotalMoney()))
	{
		cout << "you cant compelete this, no enough money "<<endl;
		cout << "your remaining money : " << Wallet::getTotalMoney()<< " LE" <<endl;
		cout << "you need : " << ((double)amount * price) << " LE " << endl;
		exspense_info info(name, description, category, -1, price, day, month, year);
		return info;
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
		if (year !=0 )
			cout << "Enter valid year:";
		else
			cout << "Enter the year:";
		cin >> year;
	}
	exspense_info info(name, description, category, amount, price, day, month, year);
	return info;
}
void LoadWithFilter(string currentWallet) {
	char filterChoice = 'n';
	vector<Expense> expenses = handler.loadWallet(currentWallet);
	filter filter;

	cout << "if you want to apply filters enter y if not enter n?" << endl;
	cin >> filterChoice;
	filterChoice = tolower(filterChoice);
	while (filterChoice == 'y')
	{
		cout << "if you want to apply category filter enter y if not enter n?" << endl;
		cin >> filterChoice;
		while (filterChoice == 'y')
		{
			cout << "Enter the category : " << endl;
			string categoryTest;
			cin >> categoryTest;
			expenses = filter.filter_category(expenses, categoryTest);
			break;
		}
		cout << "if you want to apply amount filter enter y if not enter n?" << endl;
		cin >> filterChoice;
		while (filterChoice == 'y')
		{
			cout << "Enter the amount : " << endl;
			float  amountTest;
			cin >> amountTest;
			expenses = filter.filter_amount(expenses, amountTest,1);
			break;
		}
		cout << "if you want to apply date filter enter y if not enter n?" << endl;
		cin >> filterChoice;
		while (filterChoice == 'y')
		{
			int yearTest, monthTest, dayTest;
			cout << "enter the year" << endl;
			cin >> yearTest;
			cout << "enter the month" << endl;
			cin >> monthTest;
			cout << "enter the day" << endl;
			cin >> dayTest;
			expenses = filter.filter_day(expenses, dayTest);
			expenses = filter.filter_month(expenses, monthTest);
			expenses = filter.filter_year(expenses, yearTest);
			break;
		}
		filterChoice = 'n';
	}
	for (int i = 0; i < expenses.size(); i++)
	{
		if (i == 0)
		{
			cout << "Date" << '\t' << '\t' << "Name" << '\t' << "Category" << '\t' << "Amount" << '\t' << "Price" << '\t' << "Description" << endl;
			cout << "-------------------------------------------------------------------" << endl;
		}
		expenses[i].display_data();
		cout << endl;
	}
}
