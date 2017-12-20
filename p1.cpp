// Rohan Panuganti
// Samantha Fisher
// User.cpp
// 4/16/2017
/*
  PURPOSE: The purpose of this program is to allow a user to enter and manage appointments.
  Multiple users can be entered and each user can have multiple appointments.

  INPUT: The user enters options given on the screen, names, dates, and purposes for their
  appointments.

  PROCESS: The data entered by the user is stored in a date and time
  classes. These are then accesses by other classes.
  A user can be added to an array of appointment diaries.
  A user can be deleted from the array.
  All the users' names can be printed.
  An appointment can be added to the array of appointments in appointmentdiary class
  an appointment can be canceled by deleting from the array
  An appointment can be searched fro with its date time and user name
  An appointment's purpose can be retrieved by pulling it from the appointment class
  An appointment can be rescheduled by going into the appointment class and changing the time

  OUTPUT: anything the user requests will be outputted
*/

#include <iostream>
#include <string>
#include "AppointmentDiary.h"
#include "Appointment.h"
#include "Time.h"
#include "Date.h"
#include "User.h"

using namespace std;


// INPUT: time class object
// OUTPUT: bool stating if time is valid
bool isValidTime(Time t);

// INPUT: date class object
// OUTPUT: bool stating if date is valid
bool isValidDate(Date d);

// INPUT: two time objects
// OUTPUT: whether or not the times are valid
bool illogicalTime(Time start, Time end);
    
int main() {
  char ans = 'k';
  User users;
  
  do {

    cout << "Welcome to the appointment scheduling system!" << endl << endl;
   
    cout << endl << "Please select one of the following options: " << endl << endl;
    cout << "[a] Add new user " << endl;
    cout << "[d] Delete an existing user" << endl;
    cout << "[l] List existing users" << endl;
  	cout << "[s] Schedule an appointment" << endl;
  	cout << "[c] Cancel an appointment" << endl;
  	cout << "[f] Check for appointment on certain date and time" << endl;
  	cout << "[p] Retrieve purpose of an appointment" << endl;
  	cout << "[r] Reschedule an existing appointment" << endl;
  	cout << "[x] Exit the system" << endl;
      
    cin >> ans;

    cin.ignore();

    // add user
    if(tolower(ans) == 'a') {
      string name;
      cout << "Enter the name of the user you would like to add.  ";
      getline(cin, name);
      users.addUser(name);
    }

    // delete user
    else if(tolower(ans) == 'd') {
      string name;
      cout << "Enter the name of the user you would like to delete.  ";
      getline(cin, name);
      users.deleteUser(name);
    }

    // lists user
    else if(tolower(ans) ==  'l') {
      cout << "The users in the system are:" << endl << endl;
      users.printUsers();
    }

    // schedule appointment
    else if(tolower(ans) == 's') {
      string name;
      cout << "Enter the name of the user you would like to schedule an appointment for:  ";
      getline(cin, name);
      int year, month, day;
      cout << "Enter the date you world like to schedule an appointment for (YYYY-MM-DD):  " << endl;
      cin >> year >> month >> day;
      month = abs(month);
      day = abs(day);
      
      int startHour, startMin, endHour, endMin;
      char startMer, endMer;
      cout << "Enter the start time you would like to schedule the appointment for:  " << endl;
      cout << "Hr: ";
      cin >> startHour;
      cout << "Min: "; 
      cin >> startMin;
      cout << "A/P: ";
      cin >> startMer;

      cout << "Enter the end time you would like to schedule the appointment for: " << endl;
      cout << "Hr: ";
      cin >> endHour;
      cout << "Min: "; 
      cin >> endMin;
      cout << "A/P: ";
      cin >> endMer;

      cin.ignore();

      string p;
      cout << "Enter the purpose of the appointment:  ";
      getline(cin, p);
      
      Date d(year, month, day);
      Time start(startHour, startMin, startMer);
      Time end(endHour, endMin, endMer);
      bool isValidStart = isValidTime(start);
      bool isValidEnd = isValidTime(end);
      bool isValidD = isValidDate(d);
      bool illogical = illogicalTime(start, end);
      bool clash = users.findClash(d, start, end);
      bool hasApp = users.findSpecificAppointment(name, d, start);
      if (!isValidStart || !isValidEnd || !isValidD || hasApp || clash || illogical) {
        cout << "Your schedule attempt is not valid." << endl;
      }
      else {
      	users.addAppointment(name, d, start, end, p);
      }
    }

    // cancels appointment
    else if(tolower(ans) ==  'c') {
      string name;
      int year, month, day;
      cout << "Please enter the user you would like to cancel an appointment for:  ";
      getline(cin, name);
      cout << "Enter the date you world like to cancel an appointment for (YYYY-MM-DD):  ";
      cin >> year >> month >> day;
      month = abs(month);
      day = abs(day);

      Date d(year, month, day);
      int startHour, startMin;
      char startMer;
      cout << "Enter the start time you would like to cancel the appointment for (HR MIN A/P): " << endl;
      cout << "Hr: ";
      cin >> startHour;
      cout << "Min: "; 
      cin >> startMin;
      cout << "A/P: ";
      cin >> startMer;
      Time start(startHour, startMin, startMer);

      bool isValidStart = isValidTime(start);
      bool isValidD = isValidDate(d);
      bool hasApp = users.findSpecificAppointment(name, d, start);
      if (!isValidStart || !isValidD || !hasApp ) {
        cout << "Your cancellation attempt was invalid" << endl;
      }
      else {
      	users.cancelAppointment(name, d, start);
      }
    }

    // says if there is an appointment
    else if(tolower(ans) == 'f') {
      string name;
      int year, month, day;
      cout << "Enter the name of the user you'd like to find an appointment for:  ";
      getline(cin, name);
      cout << "Enter the date of the appointment you're looking for (YYYY-MM-DD):  ";
      cin >> year >> month >> day;
      month = abs(month);
      day = abs(day);
      Date d(year, month, day);

      int startHour, startMin;
      char startMer;
      cout << "Enter the start time of the appointment you're looking for (HR MIN A/P):  " << endl;
      cout << "Hr: ";
      cin >> startHour;
      cout << "Min: "; 
      cin >> startMin;
      cout << "A/P: ";
      cin >> startMer;
      Time start(startHour, startMin, startMer);
      bool isValidStart = isValidTime(start);
      bool isValidD = isValidDate(d);
      if (!isValidStart || !isValidD) {
        cout << "You've attempted to find an invalid date or time." << endl;
      }
      else {
        bool hasApp = users.findSpecificAppointment(name, d, start);
        if (hasApp) {
          cout << "User " << name << " has an appointment scheduled for the given time." << endl;
        }
        else {
          cout << "User " << name << " does not have an appointment scheduled for the given time." << endl;
        }
      }
    }

    // retrieves purpose
    else if(tolower(ans) ==  'p') {
      string name;
      int year, month, day;
      cout << "Enter the name of the user you'd like to find an appointment purpose for:  ";
      getline(cin, name);
      cout << "Enter the date of the appointment you're looking for (YYYY MM DD):  ";
      cin >> year >> month >> day;
      month = abs(month);
      day = abs(day);
      Date d(year, month, day);

      int startHour, startMin;
      char startMer;
      cout << "Enter the start time of the appointment you're looking for (HR MIN A/P):  " << endl;
      cout << "Hr: ";
      cin >> startHour;
      cout << "Min: "; 
      cin >> startMin;
      cout << "A/P: ";
      cin >> startMer;
      Time start(startHour, startMin, startMer);

      bool isValidStart = isValidTime(start);
      bool isValidD = isValidDate(d);
      bool hasApp = users.findSpecificAppointment(name, d, start);
      if (!isValidStart || !isValidD || !hasApp) {
        cout << "You've attempted to find an invalid date or time." << endl;
      }
      else {
        string p = users.getPurpose(d, start, name);
        cout << "The purpose of the appointment is " << p << "." << endl;
      }
    }
    
    // reschedule option
    else if(tolower(ans) == 'r') {
      string name;
      int year, month, day;
      cout << "Please enter the user you would like to reschedule an appointment for:  ";
      getline(cin, name);
      cout << "Enter the date of your existing appointment: (YYYY-MM-DD):   ";
      cin >> year >> month >> day;
      month = abs(month);
      day = abs(day);
      Date d(year, month, day);

      int startHour, startMin;
      char startMer;
      cout << "Enter the start time of your existing appointment: " << endl;
      cout << "Hr: ";
      cin >> startHour;
      cout << "Min: "; 
      cin >> startMin;
      cout << "A/P: ";
      cin >> startMer;
      Time start(startHour, startMin, startMer);

      bool isValidStart = isValidTime(start);
      bool isValidD = isValidDate(d);
     
      
      cout << "Enter the date you would like to move your appointment to: (YYYY-MM-DD):  ";
      cin >> year >> month >> day;
      month = abs(month);
      day = abs(day);


	  int endHour, endMin;
	  char endMer;
      cout << "Enter the start time you would like to move your appointment to (HR MIN A/P):" << endl;
      cout << "Hr: ";
      cin >> startHour;
      cout << "Min: ";
      cin >> startMin;
      cout << "A/P";
      cin >> startMer;
      cout << "Enter the end time you would like to move your appointment to " << endl;
      cout << "Hr: ";
      cin >> endHour;
      cout << "Min: "; 
      cin >> endMin;
      cout << "A/P: ";
      cin >> endMer;
    
      Date newDate(year, month, day);
      Time newStart(startHour, startMin, startMer);
      Time newEnd(endHour, endMin, endMer);
      bool isValidNewStart = isValidTime(newStart);
      bool isValidNewEnd = isValidTime(newEnd);
      bool isValidNewDate = isValidDate(newDate);
      bool illogical = illogicalTime(newStart, newEnd);
      bool clash = users.findClash(newDate, newStart, newEnd);
      
      if (!isValidStart || !isValidD ||  !isValidNewStart || !isValidNewEnd || !isValidNewDate || clash || illogical) {
        cout << "You've attempted to reschedule for an invalid date or time." << endl;
      }
      else {
      	users.reschedule(name, d, start, newStart, newEnd, newDate);
      }
    } 
  } while (tolower(ans) != 'x');

  cout << "Thank you for using the appointment scheduling system!" << endl;
    
  return 0;
}


bool isValidTime(Time t) {
  if (t.returnHours() < 1 || t.returnHours() > 12 || t.returnMinutes() < 0
      || t.returnMinutes() > 59 || (toupper(t.returnAMPM())!= 'A' && toupper(t.returnAMPM()) != 'P')) {
    return false;
  }
  else {
    return true;
  }
}

bool isValidDate(Date d) {
  if (d.returnYear() != 2017 || d.returnMonth() < 1 || d.returnMonth() > 12 || d.returnDay() < 1
      || d.returnDay() > 31) {
    return false;
  }
  return true;
}
  
  bool illogicalTime(Time start, Time end) {
    if (start > end) {
      return true;
    }
    else {
      return false;
    }
  }
  
