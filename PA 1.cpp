/******************************
   Team Name: "Don't Panic
   Date: 9/11/2019
   File Name spc12-16.cpp
   Description: Programming assignment 1 group assignment
********************************/
// Chapter 12, Programming Challenge 16: Customer Accounts
// Headers
//#include"pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


// Constant for array sizes
const int SIZE = 45;

fstream custFile;      // Customer file
fstream tempFile;      // For deletion swap

struct Customer
{
	char name[SIZE];
	char address[SIZE];
	char city[SIZE];
	char state[SIZE];
	char zip[SIZE];
	char phone[SIZE];
	double balance;
	char lastPay[SIZE];
};

// Function prototypes
void setInfo(long);     // write record to file
void display(long);     // display one record
long search();          // find a record & return file position
void deleteRec(long);   // delete one record
void showAll();         // display all records

// flags to signal setInfo()
bool rnew = false;      // To signal if the record is new  
bool mod = false;       // To signal if the record is being modified

int main()
{
	//Main menu JMM
		char choice;

		cout << "Welcome to the fancy pants customer data collections system.\nPlease Select from one of the options below:\n\n";
		cout << "1. Enter a new record\n"
			<< "2. Display a record\n"
			<< "3. Delete a record\n"
			<< "4. Edit a record\n"
			<< "5. Display all records in list\n"
			<< "6. Exit";
		cout << "\n Enter Choice: ";
		cin >> choice;

		switch (choice)
		{
		case '1': //New record
			//setInfo(rnew);
			cout << endl << "Thank you, your data has been saved, returning to the main menu.\n";
			system("pause");
			system("CLS");
			main();
			break;
		case '2': //search and display a record
			//search();
			//display(fp);
			cout << endl << "When finished viewing, push any key to return to the main menu.\n";
			system("pause");
			system("CLS");
			main();
			break;
		case '3': // search and delete a record
			//search();
			//deleteRec(fp);
			cout << endl << "The Record has been deleted, returning to the main menu.\n";
			system("pause");
			system("CLS");
			main();
			break;
		case '4': // search and edit a record
			//search();
			//setInfo(mod);
			cout << endl << "The record has been modified, returning to the main menu.\n";
			system("pause");
			system("CLS");
			main();
			break;
		case '5': // display the entire file
			//showAll();
			cout << endl << "This is the end of the record, returning to the main menu.\n" << endl;
			system("pause");
			system("CLS");
			main();
			break;
		case '6': // exit the program
			cout << endl << "Thank you for using the fancy pants customer data collections system\nHave a nice day! \n";
			system("pause");
			system("CLS");
			return 0;
			break;
		default:
			cout << "\nThat is not a valid selection, please try again\n";
			system("pause");
			system("CLS");
			main();
		}
	//End of main menu JMM


}
// *****************************************************************
// The setInfo function write record to the file.                  *
// *****************************************************************
void setInfo(long fp)
{


}
// *****************************************************************
// The display function displays a single record.                  *
// *****************************************************************
void display(long fp)
{

}

// *****************************************************************
// The search function returns the file pointer position.          *
// *****************************************************************
long search()
{
	return 0;
}

// *****************************************************************
// The showAll function shows all the customer records.            *
// *****************************************************************
void showAll()
{
	//read from file
	//display contents of file, meke them pretty
}

// *****************************************************************
// This function marks a record for deletion by placing            *
// the null terminator at the beginning of the name member.        *
// The contents of the file are then copied to a temporary file,   *
// then the temporary file is copied back to the Customer file     *
// -- without the deleted record.                                  *
// Ideally, this function would be expanded to allow multiple      *
// record deletions before the final file swap takes place.        *
// *****************************************************************
void deleteRec(long fp)
{

}