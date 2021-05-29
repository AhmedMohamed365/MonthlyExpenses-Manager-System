
#include "Expense.h"
#include <vector>
#include <fstream>

class Wallet
{

private:
	string WalletName;
	vector<Expense>  expenses;
	float income;
public:
	Wallet();
	Wallet(string Walletname, int totalMoney);


	void saveIncome(float income);

	//float loadIncome(string walletName);
	//expenses section

	void addExpense(Expense expense);

	void editExpense(Expense expense);

	void deleteExpense(Expense expense);


	void viewExpenses(vector<Expense> allExpenses);



	//see if there is left money to buy anything
	bool checkWallet();


	~Wallet();
};