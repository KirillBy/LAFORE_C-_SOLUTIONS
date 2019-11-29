#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <string.h>
#include <cctype>
#include "NOD.h"
const int MAX = 10;
template<class T>
class Fraction
{
private:
    T numerator;
    T denomenator;
    char str[MAX];
public:
    Fraction();
    Fraction (const char s[]);
    void showFract();
    Fraction operator+(Fraction fr1);
    Fraction operator-(Fraction fr1);
    Fraction operator*(Fraction fr1);
    Fraction operator/(Fraction fr1);
    void operator=( const char s[]);
    friend std::ostream& operator<< (std::ostream& s, Fraction& f); // nessesery for reloading of <<
    friend std::istream& operator>> (std::istream& s, Fraction& f); // nessesery for reloading of >>
};

#endif // FRACTION_H
