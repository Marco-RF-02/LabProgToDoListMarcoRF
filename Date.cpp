//
// Created by Marco on 09/08/2022.
//
#include <iostream>
#include "Date.h"
#include <ctime>
#include <sstream>

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = day;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}


bool Date::checkDate(int day, int month, int year) {
    //get current date
    time_t theTime =time(NULL);
    struct tm *aTime = localtime(&theTime);

    int cday=aTime->tm_mday;
    std::cout << cday;
    int cmonth=aTime->tm_mon+1;//month is 0 - 11, add 1 to get a jan - dec 1-12 conversion
    std::cout << cmonth;
    int cyear=aTime->tm_year+1900;//year is # years since 1900;
    std::cout << cyear;

    //check if date is valid
    if(day>31 || day<=0 || month>12 ||month<=0 || year < cyear ){
        return false;
    }
    //check if it's before current date
    if(year==cyear){
        if(month<cmonth)
            return false;
        if(month==cmonth && day<cday)
            return false;
    }
    //check if valid when months have 31 days
    if ((month ==1) || (month ==3) || (month ==5) || (month ==7) ||
        (month ==8) || (month ==10) || (month ==12))
    {
        if(day<=31)
            return true;
    }
    //check if valid when months have 30 days
    if((month == 4) || (month == 6) || (month == 9) || (month == 11))
    {
        if(day<= 30)
            return true;
    }
    //check if valid when it's leep year
    if((month == 2) && (year % 4 == 0))
    {
        if(day<=29)
            return true;
    }
    //check if valid when it's not leep year
    if((month == 2) && (year % 4 != 0))
    {
        if(day<=28)
            return true;
    }

    return false;
}

Date Date::deparseDate(const std::string& parsedDate) {

    Date date;

    std::stringstream test(parsedDate);
    std::string segment;


    std::getline(test, segment, '^');
    date.setDay(std::stoi(segment));
    std::getline(test, segment, '^');
    date.setMonth(std::stoi(segment));
    std::getline(test, segment, '^');
    date.setYear(std::stoi(segment));


    return date;
}


