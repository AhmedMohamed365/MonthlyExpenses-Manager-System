


#include "wallet.h"

#include <fstream>



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

float Wallet::loadIncome(string walletName)
{

	fstream textFile;
	textFile.open("Data\\incomes.txt");
	
	string line;
	if (textFile.is_open())
	{
		
		while (getline(textFile, line, ';') )
		{
			
			vector<string>text = FileHandler::split(line, "  ");

			
				if (text[0] == walletName)
				{
					
					line = text[1];  // gets last thing before ; which is the number

					break;
				}

			
			

			
			
		}


		textFile.close();

		return stof(line);

	}


	return(1);

    


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
