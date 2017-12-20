// Rohan Panuganti
// Samantha Fisher
// Appointment.h
// 4/16/17
/*
PURPOSE: The purpose of this file is to initialize and hold all
the member functions of the class, Appointment.
*/

#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include "Time.h"
#include "Date.h"

using namespace std;

class Appointment {
 private:
  Date d;
  Time startTime;
  Time endTime;
  string purpose;
 public:
 	// default constructor
 	Appointment();

 	// constructor
 	Appointment(Date d, Time start, Time end, string p);

 	// PRE: constructor must be initialized
 	// POST: private values are changed
 	void changeDate(Date da);

 	// PRE: start values are taken in
 	// POST: start values are changed
 	void changeStartTime(Time start);

 	// PRE: end values are taken in
 	// POST: end values are changed
 	void changeEndTime(Time end);

 	// Date object returned
 	Date getDate() const;

 	// Time object returned
 	Time getStartTime() const;

 	// Time object returned
 	Time getEndTime() const;

 	// string is set
 	void setPurpose(string p);

 	// string is returned
 	string getPurpose() const;
};

#endif
   
