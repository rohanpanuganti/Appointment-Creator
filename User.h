// Rohan Panuganti
// Samantha Fisher
// User.h
// 4/16/17

/*
PURPOSE: The purpose of this file is to initialize and hold the member functions 
of the User class.
*/

#ifndef USER_H
#define USER_H

#include "AppointmentDiary.h"
#include "Time.h"
#include "Date.h"
#include "Appointment.h"

class User {
private:

  // array of Appointment Diaries 	
  	struct Info {
  		AppointmentDiary diary;
  		string name;
    };

    // struct array
    Info * userArray;
    // number of users
    int size;

    // size of the array
    int capacity;

public:
    // default constructor
	User(int cap = 10);

	// copy constructor
	User(const User &obj);

    // overloaded assignment operator
	User& operator=(const User &obj);
    // destructor 
	~User();

    // PRE: requires a string
    // POST: add one user to the array
	void addUser(string n);

	// PRE: searches through array for similar string
	// POST: returns an index
	int findUser(string n);

	// PRE: finds index
	// POST: deletes index and moves all the other elements up
	void deleteUser(string n);

	// PRE: needs the array 
	// POST: prints content of the array
	void printUsers();

	// PRE: searches for user and then appointment 
	// POST:appointment data is replaced
	void  reschedule(string n, Date d, Time start, Time newStart, Time newEnd, Date newDate);

	// PRE: searches for user  
	// POST: adds app to the appdiary array
	void addAppointment(string n, Date d, Time start , Time end, string p);

	// PRE: searches for user and date and time
	// POST: removes appointment from array
	void cancelAppointment(string n, Date d, Time start);

    //Pre: None
	bool findClash(Date d, Time start, Time end);

	// PRE: finds if a specific appointment exists
	// POST: returns if found or not
	bool findSpecificAppointment(string n, Date d, Time start);

	// PRE: finds user and date and time
	// POST: returns string purpose
	string getPurpose(Date d, Time start, string n);

	// PRE: constructor initialized
	// POST: the capacity is doubled
	void resize();
};
#endif
