//Rohan Panuganti
//Samantha Fisher
//AppointmentDiary.cpp
//4/16/17

#include <iostream>
#include <string>
#include "AppointmentDiary.h"
#include "Appointment.h"
#include "Time.h"
#include "Date.h"

AppointmentDiary::AppointmentDiary(int cap) {
  capacity = cap;
  size = 0;
  diary = new Appointment[capacity];
}

AppointmentDiary::AppointmentDiary(const AppointmentDiary &obj) {
  capacity = obj.capacity;
  size = obj.size;
  diary = new Appointment[capacity];
  for (int i = 0; i < size; i++) {
    diary[i] = obj.diary[i];
  }
}

AppointmentDiary::~AppointmentDiary() {
  delete [] diary;
}

AppointmentDiary& AppointmentDiary::operator=(const AppointmentDiary &obj) {
  if (this != &obj) {
    delete [] diary;
    capacity = obj.capacity;
    size = obj.size;
    diary = new Appointment[capacity];
    for (int i = 0; i < size; i++) {
      diary[i] = obj.diary[i];
    }
  }
  return *this;
}

void AppointmentDiary::addAppointment(Date d, Time start, Time end, string p) {
  if (size == capacity) {
    resize();
  }
  diary[size].changeDate(d);
  diary[size].changeStartTime(start);
  diary[size].changeEndTime(end);
  diary[size].setPurpose(p);
  size++;
}

void AppointmentDiary::cancelAppointment(Date d, Time start) {
  int index = findAppointment(d, start);
  if (index != -1) {
    Appointment * tempArray = new Appointment[capacity];
    for (int i = 0; i < index; i++) {
      tempArray[i] = diary[i];
    }
    for (int i = index + 1; i < size; i++) {
      tempArray[i-1] = diary[i];
    }
    delete [] diary;
    size--;
    diary = tempArray;
  }
}

void AppointmentDiary::reschedule(Date d, Time start, Date newDate, Time newStartTime, Time newEndTime){
  int index = findAppointment(d, start);
  if (index != -1) {
    diary[index].changeDate(newDate);
    diary[index].changeStartTime(newStartTime);
    diary[index].changeEndTime(newEndTime);
  }
}

bool AppointmentDiary::findClash(Date d, Time start, Time end){
	for (int i = 0; i < size; i++){
      if (diary[i].getDate() == d && ((start > diary[i].getStartTime()&& diary[i].getEndTime() > start)||
                                      (end > diary[i].getStartTime() && diary[i].getEndTime() > end )
                                      || start == diary[i].getStartTime())){
            return true;
          }
    }
	return false;
}

int AppointmentDiary::findAppointment(Date d, Time start) {
  for (int i = 0; i < size; i++) {
    if (diary[i].getDate() == d && diary[i].getStartTime() == start) {
      return i;
    }
  }

  //cout << "This time slot is vacant." << endl;
 
  return -1;
}

string AppointmentDiary::getPurpose(Date d, Time start) {
  int index = findAppointment(d, start);
  return diary[index].getPurpose();
}

void AppointmentDiary::resize() {
  int newCapacity = capacity * 2;
  Appointment * tempArray = new Appointment[newCapacity];
  for (int i = 0; i < size; i++) {
    tempArray[i] = diary[i];
  }
  delete [] diary;
  diary = tempArray;
  capacity = newCapacity;
} 

    
    
 
  
