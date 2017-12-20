//Rohan Panuganti
//Samantha Fisher
//User.cpp
//4/16/17

#include <iostream>
#include <string>
#include "User.h"
#include "AppointmentDiary.h"
#include "Appointment.h"
#include "Time.h"
#include "Date.h"

User::User(int cap) {
  capacity = cap;
  size = 0;
  userArray = new Info[capacity];
}

User::User(const User &obj) {
  capacity = obj.capacity;
  size = obj.size;
  userArray = new Info[capacity];
  for (int i = 0; i < size; i++) {
    userArray[i] = obj.userArray[i];
  }
}

User::~User() {
  delete [] userArray;
}

User & User::operator=(const User &obj) {
  if (this != &obj) {
    delete [] userArray;
    capacity = obj.capacity;
    size = obj.size;
    userArray = new Info[capacity];
    for (int i = 0; i < size; i++) {
      userArray[i] = obj.userArray[i];
    }
  }
  return *this;
}

void User::addUser(string n) {
  userArray[size].name = n;
  size++;
}

int User::findUser(string n) {
  int index = -1;
  for (int i = 0; i < size; i++) {
    if (userArray[i].name == n) {
      index = i;
    }
  }
  if (index == -1){
    cout << "This user does not exist" << endl;
  }
  return index;
}

void User::deleteUser(string n) {
  int index = findUser(n);
  if(index != -1) {
    Info * tempArray = new Info[capacity];
  
    for (int i = 0; i < index; i++) {
      tempArray[i] = userArray[i];
    }
    
    for (int i = index + 1; i < size; i++) {
      tempArray[i-1] = userArray[i];
    }
    
    delete [] userArray;
    size--;
    userArray = tempArray;
  }  
}


void User::printUsers() {
  for (int i = 0; i < size; i++) {
    cout << userArray[i].name << endl;
  }
}
    
  
void User::addAppointment(string n, Date d, Time start , Time end, string p) {
  int index = findUser(n);
  if (index != -1) {
    if (size == capacity) {
        resize();
    }
    userArray[index].diary.addAppointment(d, start, end, p);
  }
}

void User::cancelAppointment(string n, Date d, Time start) {
  int index = findUser(n);
  if (index != -1) {
    userArray[index].diary.cancelAppointment(d, start);
  }
}

void User::reschedule(string n, Date d, Time start, Time newStart, Time newEnd, Date newDate){
  int index = findUser(n);
  if (index != -1) {
    userArray[index].diary.reschedule(d, start, newDate, newStart, newEnd);
  }
}

bool User::findClash(Date d, Time start, Time end) {
  for (int i = 0; i < size; i++) {
    if(userArray[i].diary.findClash(d, start, end)) {
    	return true;
    	cout << "There was a clash with scheduling.";
    }
  } 
  return false;
}

bool User::findSpecificAppointment(string n, Date d, Time start) {
  int index = findUser(n);
  if (index != -1) {
    int appIndex = userArray[index].diary.findAppointment(d, start);
    if (appIndex == -1) {
      return false;
    }
    else {
      return true;
    }
  }
  return false;
}    

  

string User::getPurpose(Date d, Time start, string n) {
	int index = findUser(n);
	return userArray[index].diary.getPurpose(d, start);
}
  
void User::resize() {
  int newCapacity = capacity * 2;
  Info * tempArray = new Info[newCapacity];
  for (int i = 0; i < size; i++) {
    tempArray[i] = userArray[i];
  }
  delete [] userArray;
  userArray = tempArray;
  capacity = newCapacity;
}    

  
