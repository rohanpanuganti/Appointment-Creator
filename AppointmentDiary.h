// Rohan Panuganti
// Samantha Fisher
// AppointmentDiary.h
// 4/16/17

/*
PURPOSE: The purpose of this file it to initialize and hold 
all the member functions in AppointmentDiary class.
*/
#ifndef APPOINTMENTDIARY_H
#define APPOINTMENTDIARY_H

#include "Time.h"
#include "Date.h"
#include "Appointment.h"

class AppointmentDiary {

private:
	// an array of appointments
	Appointment * diary;

	// number of appointments
	int size;

	// size of the array
	int capacity;

	// PRE: size = capacity
	// POST: size < capacity 
	void resize();

public:
	// default constructor
	AppointmentDiary(int cap = 10);

	// copy constructor
	AppointmentDiary(const AppointmentDiary &obj);

	// destructor
	~AppointmentDiary();

	// overloaded assignment operator
	AppointmentDiary& operator=(const AppointmentDiary &obj);

	// PRE: search for name 
	// POST: appointment added to appdiary array
	void addAppointment(Date d, Time start, Time end, string p);

	// PRE: find date and time and remove the element
	// POST: number of used element is a little smaller in the array
	void cancelAppointment(Date d, Time start);

	// PRE: find person, time, and date and replace the time and date
	// POST: nothing really 
	void reschedule(Date d, Time start, Date newDate, Time newStartTime, Time newEndTime);

	// PRE: appdiary needs to be filled
	// POST: index returned
	int findAppointment(Date d, Time start);

	// PRE: search for app 
	// POST: return string
	string getPurpose(Date d, Time start);

	// PRE: search for app
	// POST: return whether or not clash
	bool findClash(Date d, Time start, Time end);
};  
#endif
