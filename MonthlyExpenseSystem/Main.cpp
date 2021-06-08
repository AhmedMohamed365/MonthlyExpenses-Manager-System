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
string filterType();

void loadAll(string currentWallet, int number);
//current wallet file
string currentWallet = "cash.txt";

// is it working ? 
int main() {
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

		int input = -1;

		cout << "please choose wallet file :  \n";
		vector<string> walletsNames = handler.scanAllWallets();
		cout << endl;

		cout << "or enter :" << handler.getNumberOfWallets() + 1 << " to see  expenses from all wallets\n";
		cin >> input;

		//load all wallets' expenses
		if (input == handler.getNumberOfWallets() + 1)
			loadAll(currentWallet, 2);
		else
		{
			//load the chosen wallet
			
			for (int i = 1; i < walletsNames.size() + 1; i++)

				if (input == i)
				{
					currentWallet = walletsNames[i - 1];

					break;
				}

			LoadWithFilter(currentWallet);
		}
			
		
		return true;
	}
	else if (choice == "4")
	{

		//needs to review
		system("Color FC");
		
		cout << "\n Enter 1: choose your current wallet remaining " << currentWallet << "\n or Enter 2 : choose to see remaining from all wallets\n";
		int input = -1;
		Wallet wallet;
		if (input == 1)
		{
			currentWallet = handler.chooseWalletFile();
			// I will add here to choose total money or  view remaining for one wallet only 
			cout << "your ramaining money is : ";
			
			cout << wallet.loadIncome(currentWallet) - handler.totalExpenses(currentWallet) << "LE" << endl;
		}
			

		else if (input == 2)
		{
			//This gets all money from all wallets - all expenses from all wallets 
			cout << Wallet::getTotalMoney() - handler.totalPrices() << "LE" << endl;
		}
		
		
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
	cout << "Enter exspense amount:" << endl;
	while (!(cin >> amount) || amount < 0) {
		cout << "Enter exspense amount:" << endl;
		cin.clear();
		cin.ignore(123, '\n');
	}
	cout << "Enter price amount:" << endl;
	while (!(cin >> price) || price < 0) {
		cout << "Enter price amount:" << endl;
		cin.clear();
		cin.ignore(123, '\n');
	}
	
	if ((amount*price) > (Wallet ::getTotalMoney()))
	{
		cout << "you cant compelete this, no enough money "<<endl;
		cout << "your remaining money : " << Wallet::getTotalMoney()<< " LE" <<endl;
		cout << "you need : " << ((double)amount * price) << " LE " << endl;
		exspense_info info(name, description, category, -1, price, day, month, year);
		return info;
	}
	cout << "Enter the day:" << endl;
	while (!(cin >> day) || day <= 0 || day >= 31) {
		cout << "Enter the day:" << endl;
		cin.clear();
		cin.ignore(123, '\n');
	}
	cout << "Enter the month:" << endl;
	while (!(cin >> month) || month <= 0 || month >= 31) {
		cout << "Enter the month:" << endl;
		cin.clear();
		cin.ignore(123, '\n');
	}
	cout << "Enter the year:" << endl;
	while (!(cin >> year) || year <= 2020 || year >= 2100) {
		cout << "Enter the year:" << endl;
		cin.clear();
		cin.ignore(123, '\n');
	}
	exspense_info info(name, description, category, amount, price, day, month, year);
	return info;
}
void LoadWithFilter(string currentWallet) {
	char filterChoice = 'n';
	vector<Expense> expenses = handler.loadWallet(currentWallet);
	filter filter;

	cout << "if you want to apply filters enter y else enter anything " << endl;
	cin >> filterChoice;
	filterChoice = tolower(filterChoice);
	while (filterChoice == 'y')
	{
		cout << "in filter type you will be able to enter this choices" << endl;
		cout << "1) = if u want to show equal to " <<   endl;
		cout << "2) <> if u want to show not equal to " <<   endl;
		cout << "3) <= if u want to show greater than or equal to " <<   endl;
		cout << "4) >= if u want to show less than or equal to " <<   endl;
		cout << "5) < if u want to show greater than " <<   endl;
		cout << "6) > if u want to show greater than " <<  endl;
		cout << "if you want to apply category filter enter y " << endl;
		cin >> filterChoice;
		filterChoice = tolower(filterChoice);
		while (filterChoice == 'y')
		{
			cout << "Enter the category : " << endl;
			string categoryTest;
			cin >> categoryTest;
			expenses = filter.filter_category(expenses, categoryTest);
			break;
		}
		cout << "if you want to apply amount filter enter y if " << endl;
		cin >> filterChoice;
		filterChoice = tolower(filterChoice);
		while (filterChoice == 'y')
		{
			cout << "Enter the amount : " << endl;
			float  amountTest;
			cin >> amountTest;
			expenses = filter.filter_amount(expenses, amountTest, filterType());
			break;
		}
		cout << "if you want to apply date filter enter y if not enter n?" << endl;
		cin >> filterChoice;
		while (filterChoice == 'y')
		{
			int yearTest, monthTest, dayTest;
			cout << "Enter the year" << endl;
			while (!(cin >> yearTest) || yearTest <= 2020 || yearTest >= 2100) {
				cout << "Enter the year:" << endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
			
			cout << "Enter the Month" << endl;
			while (!(cin >> monthTest) || monthTest <= 0 || monthTest >= 31) {
				cout << "Enter the month:" << endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
			
			cout << "Enter the day" << endl;
			while (!(cin >> dayTest) || dayTest <= 0 || dayTest >= 31) {
				cout << "Enter the day:" << endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
			expenses = filter.filter_date(expenses, yearTest, monthTest, dayTest, filterType());
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


void loadAll(string currentWallet,int number) {
	char filterChoice = 'n';

	vector<string> wallets = handler.scanAllWallets();
	int k = 0;
	vector<Expense> expenses(50);
	if (number == 2)
	{
	
		for (int i = 0; i < wallets.size(); i++)
		{
			vector<Expense> temp = handler.loadWallet(wallets[i]);

			for (int j = 0; j < temp.size(); j++)
			{
				expenses[k] = temp[j];
				k++;
			}
		}
		filter filter;

		cout << "if you want to apply filters enter y else enter anything " << endl;
		cin >> filterChoice;
		filterChoice = tolower(filterChoice);
		while (filterChoice == 'y')
		{
			cout << "in filter type you will be able to enter this choices" << endl;
			cout << "1) = if u want to show equal to " << endl;
			cout << "2) <> if u want to show not equal to " << endl;
			cout << "3) <= if u want to show greater than or equal to " << endl;
			cout << "4) >= if u want to show less than or equal to " << endl;
			cout << "5) < if u want to show greater than " << endl;
			cout << "6) > if u want to show greater than " << endl;
			cout << "if you want to apply category filter enter y " << endl;
			cin >> filterChoice;
			filterChoice = tolower(filterChoice);
			while (filterChoice == 'y')
			{
				cout << "Enter the category : " << endl;
				string categoryTest;
				cin >> categoryTest;
				expenses = filter.filter_category(expenses, categoryTest);
				break;
			}
			cout << "if you want to apply amount filter enter y if " << endl;
			cin >> filterChoice;
			filterChoice = tolower(filterChoice);
			while (filterChoice == 'y')
			{
				cout << "Enter the amount : " << endl;
				float  amountTest;
				cin >> amountTest;
				expenses = filter.filter_amount(expenses, amountTest, filterType());
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
				expenses = filter.filter_date(expenses, yearTest, monthTest, dayTest, filterType());
				break;
			}
			filterChoice = 'n';
		}
		for (int i = 0; i < k; i++)
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
	

	
}
string filterType()
{
	string expression;
	cout << "Enter filter type : ";
	cin >> expression;
	while (expression !="<>"&&expression != ">" && expression != "<" && expression != "<=" &&  expression != ">=" && expression != "=")
	{
		cout << "Enter valid choice :";
		cin >> expression;
	}
	return expression;
}