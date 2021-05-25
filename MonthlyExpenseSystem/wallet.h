
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


	void viewExpenses(vector<Expense> allExpenses);

	//see if there is left money to buy anything
	bool checkWallet();


	~Wallet();
};