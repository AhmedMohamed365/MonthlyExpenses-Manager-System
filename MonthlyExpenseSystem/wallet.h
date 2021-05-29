
#include "Expense.h"
#include <vector>

class Wallet
{

private:
	string WalletName;
	vector<Expense>  expenses;
	int income;
public:
	Wallet();
	Wallet(string Walletname, int totalMoney);

	//expenses section

	void addExpense(Expense expense);

	void editExpense(Expense expense);

	void deleteExpense(Expense expense);


	void viewExpenses(vector<Expense> allExpenses);



	//see if there is left money to buy anything
	bool checkWallet();


	~Wallet();
};