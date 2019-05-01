// File: time.h
//Purpose: to represent time

class Time{
public:

     //CONSTRUCTORS
     Time();
     Time(int ahour, int amin, int asec);

     //ACCESSORS
     int getHour() const;
     int getMinute() const;
     int getSecond() const;

     //MUTATORS
     void setHour(int ahour);
     void setMinute(int amin);
     void setSecond(int asec);

     //MORE MEMBER FUNCTIONS
     void PrintAMPM();



private:
     //MEMBER VARIABLES
     int hour, min, sec;

};

bool IsEarlierThan(const Time& a, const Time& b);
