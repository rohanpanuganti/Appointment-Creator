// Rohan Panuganti
// Samantha Fisher
// Date.h
// 4/16/17
/*
PURPOSE: The purpose of this file is to initialize and hold all the member 
functions in the Date class. 
*/
#ifndef DATE_H
#define DATE_H

using namespace std;

class Date {
private:
  int year;
  int month;
  int day;

public: 
    // default constructor
	Date();

	// constructor
	Date(int, int, int);

	// overloaded comparison operator
	bool operator == (const Date &right);

	// PRE: constructor initialized
	// POST: private values set
	void setDate(int, int, int);

	// PRE: constructor initialized
	// POST: prints date
	void displayDate() const;

	// returns values
	int returnYear() const;
	int returnMonth() const;
	int returnDay() const;
};

#endif



