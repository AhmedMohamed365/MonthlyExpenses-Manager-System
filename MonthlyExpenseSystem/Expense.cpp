#include "Expense.h"
#include <string>




Expense::Expense()
{

}



Expense::Expense(exspense_info info)
{
	this->info = info;
}

void Expense::display_data()
{
	/*
	string name , description , category;
		float amount  , price;
		int day, month, year;
	*/
	
		// needs to be modified ( date should be one coulm)
	cout << endl <<"*********************\n";
	
		cout << info.name +'\t' << info.category + '\t' <<
			info.amount + '\t' << info.price  << endl
			<< info.description << endl
			<< info.date;
	
}




//
string Expense::get_category() {
	return info.category;
}


string Expense::get_data()
{
	return info.name + ',' + info.category + ',' + ',' + to_string((info.amount)) + ',' + to_string(info.price)
		+ '\n' +
		info.description
		+ '\n' +
		to_string(info.day) + '-' + to_string(info.month) + '-' + to_string(info.year );

}







string Expense::get_date() {

	return info.date;
}


//@Ahmed Huessin continue these last getters from the Expense.h defintion 







