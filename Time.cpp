//Rohan Panuganti
//Samantha Fisher
#include <iostream>
#include "Time.h"
using namespace std;

Time::Time() {
  hours = 12;
  minutes = 0;
  ampm = 'P';
}

Time::Time(int h, int m, char ap) {
  hours = h;
  minutes = m;
  ampm = ap;
}

bool Time::operator == (const Time &right){
  if (hours == right.hours && 
      minutes == right.minutes &&
      ampm == right.ampm){
    return true;
  }
  else {
    return false;
  }
}

bool Time::operator>(const Time &right) {
	if ((toupper(ampm) == toupper(right.ampm) && hours > right.hours) || 
		(toupper(ampm) == toupper(right.ampm) && hours == right.hours && minutes > right.minutes) ||
		(toupper(ampm) == 'A' && toupper(right.ampm) == 'P') ||
		(toupper(ampm) == toupper(right.ampm) && right.hours == 12 && hours < 12)){
		return true;
}
else {
	return false;
  }
}                                                    
  

void Time::setTime(int h, int m, char ap) {
  hours = h;
  minutes = m;
  ampm = ap;
}

void Time::printTime() const{
  cout << "Time: " << hours << ":" << minutes << " " << ampm << endl;
}

int Time::returnHours() const{
  return hours;
}

int Time::returnMinutes() const{
  return minutes;
}

char Time::returnAMPM() const {
  return ampm;
}

