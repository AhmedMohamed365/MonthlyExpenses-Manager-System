#include "wallet.h"

Wallet::Wallet()
{
}

Wallet::Wallet(string Walletname, int totalMoney)
{
    this->WalletName = WalletName;
    income = totalMoney;
}

void Wallet::saveIncome(float income)
{

    fstream incomes("Data\\incomes.txt", ios::app);

    incomes << WalletName <<' ' << income << endl;
}

void Wallet::viewExpenses(vector<Expense> allExpenses)
{

    system("CLS");

    for (int expense = 0; expense < allExpenses.size(); expense++)
    {
       allExpenses[expense].display_data();
        
    }
}

// Do I have money to buy or I have borrowed ? 
bool Wallet::checkWallet()
{

    if (income > 0)
        return true;

    return false;
}

Wallet::~Wallet()
{
}
