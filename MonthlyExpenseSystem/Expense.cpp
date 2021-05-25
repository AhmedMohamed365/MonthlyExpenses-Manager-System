#include "Expense.h"
#include <string>




Expense::Expense() {
	capacity = 5;
	expenses_count = 0;
	expenses_list = new exspense_info[capacity];
}

void Expense::display_data()
{
	/*
	string name , description , category;
		float amount  , price;
		int day, month, year;
	*/
	for (int i = 0; i < 6; i++)
	{
		// needs to be modified ( date should be one coulm)
		cout << expenses_list->name << expenses_list->category <<
			expenses_list->amount << expenses_list->price << endl
		<< expenses_list->description << endl
		<< expenses_list->year;
	}
}





string Expense::get_category() {
	return expenses_list->category;
}





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
