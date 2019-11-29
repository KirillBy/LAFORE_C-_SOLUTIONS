#ifndef MONEY_H
#define MONEY_H
#include "iostream"
#include "string.h"
#include <iomanip>
const int MAX = 20;

class money
{
private:
    double long summ;
    char  strsumm[MAX];

public:
    money() {  static_cast<void>(strsumm[0] = {'\0'}) , summ = 0; } // empty constructor
    money(long double a) {static_cast<void>(strsumm[0] = {'\0'}), summ = a;}
    void getsumm() // getting sum of money from user
    {
        std::cout << "Enter mone summ in $xxx,xxx,xxx.xx format ";
        std::cin >> std::setw(MAX) >> strsumm;
    }


    void showsumm() const //dispaly sum
    {
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2); std::cout << "Money summ:  " << summ << std::endl;
    }

    void mstold(); // converting  string to ing
    money operator + (money &a) const; //operator + reload
    money operator - (money &a) const; //operator - reload
    money operator * (long double a) const; //operator * reload
    money operator / (long double a) const; //operator / reload
    long double operator / (money &a) const; //operator / reload

    friend money operator * (money a, money b); // for reloading long double * money
    friend money operator / (money const a, money const b); // for reloading long double / money
    friend std::ostream& operator<< (std::ostream& s, money& f); // nessesery for reloading of <<
    friend std::istream& operator>> (std::istream& s, money& f); // nessesery for reloading of >>
};
#endif // MONEY_H
