/*
 * FileHandler.cpp
 *
 *  Created on: May 25, 2021
 *      Author: Us
 */

#include "FileHandler.h"
//expenses section

	void FileHandler:: addExpense(Expense expense)

	{

	}

	void  FileHandler:: editExpense(Expense expense)
	{

	}

	void  FileHandler:: deleteExpense(Expense expense)
	{

	}

//wallet section


	Wallet FileHandler::findWallet(string walletName)
	{

		string foundedWallet = "";

		// this gets all the wallets names
		string path = "C:\\Users\\Ahmed\\source\\repos\\MonthlyExpenseSystem\\MonthlyExpenseSystem\\Data";
		for (const auto& entry : fs::directory_iterator(path))
		{
			foundedWallet = entry.path().filename().string();
			if ( foundedWallet == walletName)
			{
				foundedWallet = entry.path().filename().string();

				cout << "the wallet     : " << foundedWallet << " has ben found";
				break;
			}
			
			foundedWallet = "";

		}



		Wallet wallet;

		if (foundedWallet == "")
			return wallet;


		else
		{
			
			return  wallet;
		}
		
	

	}

	void FileHandler::  readAllWallets()
	{

		// this gets all the wallets names
		string path = "C:\\Users\\Ahmed\\source\\repos\\MonthlyExpenseSystem\\MonthlyExpenseSystem\\Data";
		for (const auto& entry : fs:: directory_iterator(path))
			std::cout << entry.path().filename() << std::endl;
	}

	void FileHandler::   deleteWallet(Wallet wallet)
	{

	}

	void FileHandler::loadWallet(string walletFile)
	{
		walletFile = "Data\\" + walletFile;

		//const char* WalletName = fileDestination.c_str();



		textFile.open(walletFile);

		string line;
		if (textFile.is_open())
		{
			while (getline(textFile, line))
			{
				cout << line << '\n';
			}

			textFile.close();
		}


	}


void FileHandler::  makeWallet( string name)
{
//output the txt file with wallet name
	name = "Data\\" + name;
	//const char * WalletName = name.c_str();


	//should check here if the file is already there
	 ofstream WalletFile(name,ios::app);
}

FileHandler::FileHandler() {
	// TODO Auto-generated constructor stub

	nofWallets = 0;
	noflines = 0;

}

FileHandler::~FileHandler() {
	// TODO Auto-generated destructor stub
}

