/*
 * FileHandler.h
 *
 *  Created on: May 25, 2021
 *      Author: mercy
 * 
 * 
#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_
 */



#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>

#include "Expense.h"

using namespace std;
namespace fs = std::filesystem;





class Wallet
{

};

class FileHandler {
private:
	fstream textFile;
	int noflines ; // gets this number to give it to number of expenses
	int nofWallets ; // num of wallets exist in the folder




public:
	//expenses section

	void addExpense(Expense expense);

	void editExpense(Expense expense);

	void deleteExpense(Expense expense);

//wallet section
	void makeWallet(string name);

	Wallet findWallet(string walletName);

	void readAllWallets();

	void deleteWallet(Wallet wallet);

	void loadWallet(string walletName);





	FileHandler();

	virtual ~FileHandler();
};


