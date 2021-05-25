#include "wallet.h"

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
