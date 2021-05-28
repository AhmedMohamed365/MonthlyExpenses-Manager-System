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

#include "wallet.h"
using namespace std;
namespace fs = std::filesystem;







class FileHandler {
private:
	fstream textFile;
	int nofExpenses ; // gets this number to give it to number of expenses
	int nofWallets ; // num of wallets exist in the folder



public:
	//expense section
	vector<string> split(string s, string del = ",");
	
	void countExpenses();

		
	
	void saveExpense(exspense_info info);

	void eraseExpense(Expense expense);

	void rewriteExpense(Expense expense);

	vector<Expense> loadWallet(string walletFile);
//wallet section
	void makeWallet(string name);

	Wallet findWallet(string walletName);

	void scanAllWallets();

	void deleteWallet(Wallet wallet);

	//void loadWallet(string walletName);





	FileHandler();

	virtual ~FileHandler();
};


