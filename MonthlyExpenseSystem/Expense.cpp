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
//string Expense::get_category() {
//	return expenses_list->category;
//}
//
//
//string Expense::get_data()
//{
//	return expenses_list->name + ',' + expenses_list->category + ',' + ',' + to_string((expenses_list->amount)) + ',' + to_string(expenses_list->price)
//		+ '\n' +
//		expenses_list->description
//		+ '\n' +
//		to_string(expenses_list->day) + '-' + to_string(expenses_list->month) + '-' + to_string(expenses_list->year );
//
//}
//




/*

void Expense::get_date(int i) {
	cout << expenses_list[i].day << " / " << expenses_list[i].month << " / " << expenses_list[i].year << endl;
}
void Expense::add_expense(string icategory, int iday, int imonth, int iyear) {
	if (expenses_count == capacity) {
		expand();
	}

	expenses_list[expenses_count].category = icategory;
	expenses_list[expenses_count].day = iday;
	expenses_list[expenses_count].month = imonth;
	expenses_list[expenses_count].year = iyear;
	expenses_count++;

}
void Expense::expand() {
	exspense_info* new_expenses_list = new exspense_info[capacity + 2];
	for (int i = 0; i < expenses_count; i++) {
		new_expenses_list[i] = expenses_list[i];
	}
	capacity = capacity + 2;
	delete[] expenses_list;
	expenses_list = new_expenses_list;
}

 Expense::display_data() {
	for (int i = 0; i < expenses_count; i++) {
		cout << "category :" << expenses_list[i].category << " ";
		cout << "date : ";
		get_date(i);
	}
}



*/
