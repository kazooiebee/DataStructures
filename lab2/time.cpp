//File date.cpp
//Purpose: Implement time class

#include "time.h"
#include <iostream>


Time::Time(){
     sec = 0;
     hour = 0;
     min = 0;
}

Time::Time(int ahour, int amin, int asec){
     hour = ahour;
     min = amin;
     sec = asec;
}

int Time::getHour() const{
     return hour;
}

int Time::getMinute() const{
     return min;
}

int Time::getSecond() const{
     return sec;
}

void Time::setHour(int ahour){
     hour = ahour;
}

void Time::setMinute(int amin){
     min = amin;
}

void Time::setSecond(int asec){
     sec = asec;
}

void Time::PrintAMPM(){
     if(sec==0&&hour==0&&min==0){
          std::cout << "12:00:00 am"<<std::endl;
     }
     else if(sec==0&&hour==12&&min==0){
          std::cout << "12:00:00 pm" <<std::endl;
     }
     else{

          int tempHour;
          std::string ampm;

          if(hour > 12){
               tempHour = hour - 12;
               ampm = "pm";
          }
          else{
               ampm = "am";
               tempHour = hour;
          }

          std::cout << tempHour << ':';
          if(min < 10){
               std::cout << 0;
          }
          std::cout << min << ':';
          if(sec < 10){
               std::cout << 0;
          }
          std::cout << sec << ' ' << ampm << std::endl;
     }
}

bool IsEarlierThan(const Time& a, const Time& b){
     if((a.getHour() < b.getHour()) ||
        (a.getHour() ==b.getHour() && a.getMinute() < b.getMinute()) ||
        (a.getHour() ==b.getHour() && a.getMinute() ==b.getMinute() && a.getSecond() < b.getSecond())
   ){
        return true;
   }
   else{
        return false;
   }
}
