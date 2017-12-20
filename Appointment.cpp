// Rohan Panuganti
// Samantha Fisher
// Appointment.cpp
// 4/16/17

#include <iostream>
#include <string>
#include "Appointment.h"
#include "Date.h"
#include "Time.h"
using namespace std;

Appointment::Appointment() {
  d.setDate(2017, 4, 16);
  startTime.setTime(12,0,'A');
  endTime.setTime(12,0,'P');
  purpose = "";
}

Appointment::Appointment(Date d, Time start, Time end, string p){
  changeStartTime(start);
  changeEndTime(end);
  changeDate(d);
  purpose = p;
}

void Appointment::changeDate(Date da) {
  d.setDate(da.returnYear(), da.returnMonth(), da.returnDay());
}

void Appointment::changeStartTime(Time start) {
  startTime.setTime(start.returnHours(), start.returnMinutes(), start.returnAMPM());
}

void Appointment::changeEndTime(Time end) {
  endTime.setTime(end.returnHours(), end.returnMinutes(), end.returnAMPM());
}

Date Appointment::getDate() const {
  return d;
}

Time Appointment::getStartTime() const {
  return startTime;
}

Time Appointment::getEndTime() const {
  return endTime;
}

void Appointment::setPurpose(string p) {
  purpose = p;
}

string Appointment::getPurpose() const {
  return purpose;
}
