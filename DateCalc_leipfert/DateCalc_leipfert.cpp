/*
Author:			Christopher Leipfert
Date:			4/5/14
Filename:		DateCalc_leipfert.cpp
Purpose:		Calculate the day number of a specific date in the given year
Error Checking:	None Yet.
Assumptions:	None Yet.
Input/Output:	Output sent to file, input from keyboard.
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

void Greeting();
bool IsLeap (int yr);
int MonthDay(int month, int day, bool leap);
string MonthName(int month);

const int JAN = 31;
const int FEB = 28;
const int FEB_LEAP = 29;
const int MAR = 31;
const int APR = 30;
const int MAY = 31;
const int JUNE = 30;
const int JULY = 31;
const int AUG = 31;
const int SEPT = 30;
const int OCT = 31;
const int NOV = 30;
const int DEC = 31;





int main()
{
	ifstream din;	// Input File variable
	ofstream dout;	// Output File variable
	string	inputFileName;	// Variable for input file name
	string	outputFileName;	// Variable for output file name
	int totalDays; // Number of days in that year
	bool leapYear = false; // bool for leap year
	int month;		// month variable
	int	day;		// day variable
	int year;		// year variable
	string monthName;
	
	
	Greeting();		// Call to void function Greeting.

	cout << "Please input the name of the input file:" << endl;
	cin >> inputFileName;
	cout << "Please input the name of the output file:" << endl;
	cin >> outputFileName;

	din.open(inputFileName.c_str());
	dout.open(outputFileName.c_str());

	system ("pause");
	system ("cls");

	if(din) // Testing for file
	{
		// File Found
		din >> month;
		din >> day;
		din >> year;
		
		while(din)
		{
			if(IsLeap(year)) // Test for leap year
			{
				leapYear = true;
				totalDays = MonthDay(month, day, leapYear);	// Call to function MonthDay.
				monthName = MonthName(month);	// Call to function MonthName.
				cout << monthName << ' ' << day << " is day number " << totalDays << " in " << year << '.' << '\n' << endl;
				dout << monthName << ' ' << day << " is day number " << totalDays << " in " << year << '.' << '\n' << endl;
			}
			else if(month == 2 && day == 29)
			{
				monthName = MonthName(month);

				cout << monthName << ' ' << day << " is not a vaild date " << totalDays << " in " << year << '.' << '\n' << endl;
				dout << monthName << ' ' << day << " is not a valid date " << totalDays << " in " << year << '.' << '\n' << endl;
			}
			else
			{
				totalDays = MonthDay(month, day, leapYear);
				monthName = MonthName(month);
				cout << monthName << ' ' << day << " is day number " << totalDays << " in " << year << '.' << '\n' << endl;
				dout << monthName << ' ' << day << " is day number " << totalDays << " in " << year << '.' << '\n' << endl;
			}
		din >> month;
		din >> day;
		din >> year;
		}
	}
	else
	{
		cout << inputFileName << " was not found!" << endl;
	}

	din.close();
	dout.close();

	return 0;
}

void Greeting()
{
	// Purpose: Print a greeting to the screen
	// Pre: None
	// Post: Greeting Printed to screen
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "$                                                                             $" << endl;
	cout << "$                                                                             $" << endl;
	cout << "$                                                                             $" << endl;
	cout << "$         Welcome to the day of the year calculator 2014                      $" << endl;
	cout << "$                                                                             $" << endl;
	cout << "$                                                                             $" << endl;
	cout << "$                                                                             $" << endl;
	cout << "$                                                                             $" << endl;
	cout << "$                                                                             $" << endl;
	cout << "$         by: Christopher Joseph Leipfert                                     $" << endl;
	cout << "$                                                                             $" << endl;
	cout << "$                                                                             $" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;

	system ("pause");
	system ("cls");
}
bool IsLeap (int yr)
{
	//Purpose: Determines if a given year is a leap year.
	//Pre:  yr contains a value representing a year
	//Post: Returns true if yr is a leap year, else false is returned.

	// Variable(s) local to IsLeap:
	bool isLeap = false;			// Assume yr is not a leap year.
	if (yr / 4)
	{
		if(yr / 100)
		{
			if(yr / 400)
			{
				isLeap = true;
			}
		}
		else
		{
			isLeap = true;
		}
	}
	// RETURN isLeap to the calling function
	return isLeap;

} // End function IsLeap()

int MonthDay(int month, int day, bool leap)
{
	//Purpose: Determines the total number of days.
	//Pre:  The month and day given by the user.
	//Post: Returns the total number of days.
	int totalDays;

	if(month == 1)
	{
		totalDays = day;
	}
	else if(leap == true)
	{
		if(month == 2)
		{
			totalDays = JAN + day;
		}
		else if(month == 3)
		{
			totalDays = JAN + FEB_LEAP + day;
		}
		else if(month == 4)
		{
			totalDays = JAN + FEB_LEAP + MAR + day;
		}
		else if(month == 5)
		{
			totalDays = JAN + FEB_LEAP + MAR + APR + day;
		}
		else if(month == 6)
		{
			totalDays = JAN + FEB_LEAP + MAR + APR + MAY + day;
		}
		else if(month == 7)
		{
			totalDays = JAN + FEB_LEAP + MAR + APR + MAY + JUNE + day;
		}
		else if(month == 8)
		{
			totalDays = JAN + FEB_LEAP + MAR + APR + MAY + JUNE + JULY + day;
		}
		else if(month == 9)
		{
			totalDays = JAN + FEB_LEAP + MAR + APR + MAY + JUNE + JULY + AUG + day;
		}
		else if(month == 10)
		{
			totalDays = JAN + FEB_LEAP + MAR + APR + MAY + JUNE + JULY + AUG + SEPT + day;
		}
		else if(month == 11)
		{
			totalDays = JAN + FEB_LEAP + MAR + APR + MAY + JUNE + JULY + AUG + SEPT + OCT + day;
		}
		else if(month == 12)
		{
			totalDays = JAN + FEB_LEAP + MAR + APR + MAY + JUNE + JULY + AUG + SEPT + OCT + NOV + day;
		}
	}
	else
	{
		if(month == 2)
		{
			totalDays = JAN + day;
		}
		else if(month == 3)
		{
			totalDays = JAN + FEB + day;
		}
		else if(month == 4)
		{
			totalDays = JAN + FEB + MAR + day;
		}
		else if(month == 5)
		{
			totalDays = JAN + FEB + MAR + APR + day;
		}
		else if(month == 6)
		{
			totalDays = JAN + FEB + MAR + APR + MAY + day;
		}
		else if(month == 7)
		{
			totalDays = JAN + FEB + MAR + APR + MAY + JUNE + day;
		}
		else if(month == 8)
		{
			totalDays = JAN + FEB + MAR + APR + MAY + JUNE + JULY + day;
		}
		else if(month == 9)
		{
			totalDays = JAN + FEB + MAR + APR + MAY + JUNE + JULY + AUG + day;
		}
		else if(month == 10)
		{
			totalDays = JAN + FEB + MAR + APR + MAY + JUNE + JULY + AUG + SEPT + day;
		}
		else if(month == 11)
		{
			totalDays = JAN + FEB + MAR + APR + MAY + JUNE + JULY + AUG + SEPT + OCT + day;
		}
		else if(month == 12)
		{
			totalDays = JAN + FEB + MAR + APR + MAY + JUNE + JULY + AUG + SEPT + OCT + NOV + day;
		}
	} // End MonthDay
		
	return totalDays;
}
string MonthName(int month)
{
	//Purpose: Determines the name of the month given.
	//Pre:  The month as an interger.
	//Post: Returns the name of the month.
	string monthName;


		if(month == 1)
		{
			monthName = "January";
		}
		else if(month == 2)
		{
			monthName = "February";
		}
		else if(month == 3)
		{
			monthName = "March";
		}
		else if(month == 4)
		{
			monthName = "April";
		}
		else if(month == 5)
		{
			monthName = "May";
		}
		else if(month == 6)
		{
			monthName = "June";
		}
		else if(month == 7)
		{
			monthName = "July";
		}
		else if(month == 8)
		{
			monthName = "August";
		}
		else if(month == 9)
		{
			monthName = "September";
		}
		else if(month == 10)
		{
			monthName = "October";
		}
		else if(month == 11)
		{
			monthName = "November";
		}
		else if(month == 12)
		{
			monthName = "December";
		}

	return monthName;
} // End MonthName