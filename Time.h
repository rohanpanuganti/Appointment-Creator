// Rohan Panuganti
// Samantha Fisher
// Time.h
// 4/16/17

/*
PURPOSE: The purpose of this header file is to initialize and hold all the 
the memember functions of the Time class
*/
#ifndef TIME_H
#define TIME_H

class Time {
 private:
  int hours;
  int minutes;
  char ampm;
 public:
  // default constructor
  Time();
  
  // constructor
  Time(int h, int m, char ap);

  // overloaded comparison operator
  bool operator == (const Time &right);

  bool operator >  (const Time &right);

  // PRE: constructor initialized
  // POST: class has new values
  void setTime(int h, int m, char ap);

  // PRE: all values must be filled
  // POST: values displayed
  void printTime() const;

  // PRE: constructor initialized
  // POST: hours returned
  int returnHours() const;

  // PRE: constructor initialized
  // POST: minutes returned
  int returnMinutes() const;

  // PRE: constructor initialized
  // POST: meridiem returned 
  char returnAMPM() const;
};

#endif
