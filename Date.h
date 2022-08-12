//
// Created by Marco on 09/08/2022.
//

#ifndef LABPROGTODOLISTMARCORF_DATE_H
#define LABPROGTODOLISTMARCORF_DATE_H


class Date {
public:
    Date(int day, int month, int year);

    Date() = default;

    Date deparseDate(const std::string& parsedDate);

    bool checkDate(int day, int month, int year);

    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);

    bool operator==(const Date &rhs) const;

    bool operator!=(const Date &rhs) const;

    bool operator<(const Date &rhs) const;

    bool operator>(const Date &rhs) const;

    bool operator<=(const Date &rhs) const;

    bool operator>=(const Date &rhs) const;

private:
int day{};
int month{};
int year{};
};




#endif //LABPROGTODOLISTMARCORF_DATE_H
