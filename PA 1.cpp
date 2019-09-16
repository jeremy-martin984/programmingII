/******************************
   Team Name: "Don't Panic (*Panic intensifies*)"
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
void setInfo(/*long*/);     // write record to file
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
	
	//flag to autocreate data files if they do not exist
	tempFile.open("tempfile.dat", ios::app);
	tempFile.close();
	custFile.open("custfile.dat", ios::app);
	custFile.close();

	//This is my menu, validates menu input through switch statements.
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
		case '1':
			setInfo(/*long*/); //Calls program to write data to dat file at the end of the file
			// Need to figure out flags for old record vs new record
			cout << endl << "Thank you, your data has been saved, returning to the main menu.\n";
			system("pause");
			system("CLS");
			main();
			break;
		case '2': //search and display a record
			//search(); Needs to load function to search the dat file and find file position for structure. Should search by name
			//display(fp); load the found file position into memory as struct record and display
			cout << endl << "When finished viewing, push any key to return to the main menu.\n";
			system("pause");
			system("CLS");
			main();
			break;
		case '3': // search and delete a record
			//search(); Needs to load function to search the dat file and find file position for structure. Should search by name
			//deleteRec(fp); Delete record from dat file from the found file position
			cout << endl << "The Record has been deleted, returning to the main menu.\n";
			system("pause");
			system("CLS");
			main();
			break;
		case '4': // search and edit a record
			//search(); Needs to load function to search the dat file and find file position for structure. Should search by name
			//setInfo(mod); Needs to modify the record at the found file position. This can either modify at the located file postition
			// or delete the record at the located file position then call function to create to record.
			cout << endl << "The record has been modified, returning to the main menu.\n";
			system("pause");
			system("CLS");
			main();
			break;
		case '5': // display the entire file
			//showAll(); Read and display the contents of the entire date file
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
		case '7': //search test and debug
			search();
		default: // Stop invalid input** catches any incorrect character, multiple characters will cause it to break
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
void setInfo(/*long fp These flags are in here to find specific file position and write to it. This isn't working yet*/)
{
	char choice;
	Customer record;
	/*
	To be done still - save info, reject no entry
	*/
	cin.get();
	cout << "Enter customer name (First and Last)\n";
	cin.getline(record.name, SIZE);
	cout << endl << "Enter customer Address: \n";
	cin.getline(record.address, SIZE);
	cout << endl << "Enter customer City: \n";
	cin.getline(record.city, SIZE);
	cout << endl << "Enter Customer State: \n";
	cin.getline(record.state, SIZE);
	cout << endl << "Enter customer Zipcode: \n";
	cin.getline(record.zip, SIZE);
	cout << endl << "Enter customer phone number: \n";
	cin.getline(record.phone, SIZE);
	cout << endl << "Enter customer balance: \n";
	cin >> record.balance;
	while (record.balance < 0)
	{
		cout << endl << "Negative balances are not allowed, please enter a positive number";
		cout << endl;
		cin >> record.balance;
	};
	cout << endl << "Enter the last date the customer has paid their balance: \n";
	cin >> record.lastPay;
	cout << "You have entered the following information: \n\n";
	cout << "Name: " << record.name << endl 
		<< "Address: " << record.address << endl 
		<< "City: " << record.city << endl 
		<< "State: " << record.state << endl 
		<< "Zip code: " << record.zip << endl 
		<< "Phone Number:  "<< record.phone << endl 
		<< fixed << setprecision(2) << "Balance: " << record.balance << endl
		<< "Date of last payment: " << record.lastPay << endl;

	cout << endl << endl << "Is the information above correct? (y/n) \n";
	cin >> choice;
	switch (choice)
	{
	case 'y':
		custFile.open("custfile.dat", ios::in | ios::out | ios::ate | ios::binary);
		custFile.write(reinterpret_cast<char*>(&record), sizeof(record));
		custFile.close();
		break;
	case 'Y':
		custFile.open("custfile.dat", ios::in | ios::out | ios::ate | ios::binary);
		custFile.write(reinterpret_cast<char*>(&record), sizeof(record));
		custFile.close();
		break;
	case 'n':
		cout << "Please enter the info again \n";
		setInfo();
	case 'N':
		cout << "Please enter the info again: \n";
		setInfo();
	default:
		cout << endl;
		cout << "That is not a valid selection, please try again\n Y/N: ";
		cin >> choice;
	};
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
//not working yet, push 7 at menu to test/debug
	custFile.open("custfile.dat", ios::in | ios::binary);
	cin.get();
	char name[SIZE];
	cout << "Enter the full name of the customer record you are trying to retrieve.\n Name: ";
	cin.getline(name, SIZE);
	
	while (!custFile.eof())
	{
		//search the record
		custFile.seekg(sizeof(name[SIZE]), ios::beg);
		long fp = custFile.tellp();
		cout << fp; // supposed to return file position. for testing only.
	}
	//End of file, no record found
	cout << "No record with that name was found, please try your search again.\n";
	

	return 0; // lets me run program without search function working (yet) This will not be in final code
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