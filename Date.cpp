// Rohan Panuganti
// Date.cpp
// 4/3/17

#include "Date.h"
#include <string>
#include <iostream>

using namespace std;

Date::Date() {
  year = month = day = 0;
}

Date::Date(int y, int m, int d) {
  setDate(y, m, d);
}

bool Date::operator == (const Date &right){
  if (year == right.year && 
      month == right.month &&
      day == right.day){
    return true;
  }
  else{
    return false;
  }
}

void Date::setDate(int y = 0, int m = 0, int d = 0){
  year = y;
  month = m;
  day = d;
}

void Date::displayDate() const{
  cout << month << "/" <<  day << "/" << year << endl;
}

int Date::returnYear() const{
  return year;
}

int Date::returnMonth() const{
  return month;
}

int Date::returnDay() const{
  return day;
}