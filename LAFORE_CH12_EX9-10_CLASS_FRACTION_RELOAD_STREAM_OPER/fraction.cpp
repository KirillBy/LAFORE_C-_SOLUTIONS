#include "fraction.h"
#include "string.h"
//////////////////////////////////////////////////////////////////////////////////////
template<class T>
Fraction<T>::Fraction()
{
numerator = 0; denomenator = 0;
}
///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
template<class T>
void Fraction<T>::showFract()
{

    std::cout << numerator << "/" << denomenator;
}
///////////////////////////////////////////////////////////////////////////////////////
template<class T>
Fraction<T>::Fraction (const char s[])
{
    strcpy(str, s);
    int i = 0;
    numerator = 0;
    denomenator = 0;
    int minus = 1;
    if (str[i] == '-')
    {
        minus = -1;
        i++;
    }
    while (isdigit(str[i]))
    {
        numerator = numerator * 10 + str[i] - 0x30;
        i++;
    }
    if (str[i] != '/')
    {
        std::cout << "Incorrect format of number!!! ";

    }
    i++;
    if (str[i] == '-')
    {
        minus = -1;
        i++;
    }
    while (isdigit(str[i]))
    {
        denomenator = denomenator * 10 + str[i] - 0x30;
        i++;
    }
    numerator *= minus;
}
/////////////////////////////////////////////////////////////////////////////////
template<class T>
Fraction<T> Fraction<T>::operator+(Fraction fr1) //reloading + operation
{
    Fraction fr;
    int nod;
    fr.numerator = numerator * fr1.denomenator + fr1.numerator * denomenator;
    fr.denomenator = denomenator * fr1.denomenator;
    nod = NOD(fr.numerator, fr.denomenator);
    fr.numerator /= nod; fr.denomenator /= nod;
    if (fr.denomenator < 0)
    {
        fr.denomenator += fr.denomenator * (-2);
        fr.numerator -= fr.numerator * 2;
    }
    return fr;
}
////////////////////////////////////////////////////////////////////////////////////
template<class T>
Fraction<T> Fraction<T>::operator-(Fraction fr1) //reloading - operation
{
    Fraction fr;
    int nod;
    fr.numerator = numerator * fr1.denomenator - fr1.numerator * denomenator;
    fr.denomenator = denomenator * fr1.denomenator;
    nod = NOD(fr.numerator, fr.denomenator);
    fr.numerator /= nod; fr.denomenator /= nod;
    if (fr.denomenator < 0)
    {
        fr.denomenator += fr.denomenator * (-2);
        fr.numerator -= fr.numerator * 2;
    }
    return fr;
}
///////////////////////////////////////////////////////////////////////////////////////
template<class T>
Fraction<T> Fraction<T>::operator*(Fraction fr1) //reloading * operation
{
    Fraction fr;
    int nod;
    fr.numerator = numerator *  fr1.numerator ;
    fr.denomenator = denomenator * fr1.denomenator;
    nod = NOD(fr.numerator, fr.denomenator);
    fr.numerator /= nod; fr.denomenator /= nod;
    if (fr.denomenator < 0)
    {
        fr.denomenator += fr.denomenator * (-2);
        fr.numerator -= fr.numerator * 2;
    }
    return fr;
}
//////////////////////////////////////////////////////////////////////////////////////
template<class T>
Fraction<T> Fraction<T>::operator/(Fraction fr1) //reloading / operation
{
    Fraction fr;
    int nod;
    fr.numerator = numerator * fr1.denomenator;
    fr.denomenator = denomenator * fr1.numerator;
    nod = NOD(fr.numerator, fr.denomenator);
    fr.numerator /= nod; fr.denomenator /= nod;
    if (fr.denomenator < 0)
    {
        fr.denomenator += fr.denomenator * (-2);
        fr.numerator -= fr.numerator * 2;
    }
    return fr;
}
///////////////////////////////////////////////////////////////////////////////////////
template<class T>
void Fraction<T>::operator=( const char s[])
{

    strcpy(str, s);
    int i = 0;
    numerator = 0;
    denomenator = 0;
    int minus = 1;
    if (str[i] == '-')
    {
        minus = -1;
        i++;
    }
    while (isdigit(str[i]))
    {
        numerator = numerator * 10 + str[i] - 0x30;
        i++;
    }
    if (str[i] != '/')
    {
        std::cout << "Incorrect format of number!!! ";
        exit(1);
    }
    i++;
    if (str[i] == '-')
    {
        minus = -1;
        i++;
    }
    while (isdigit(str[i]))
    {
        denomenator = denomenator * 10 + str[i] - 0x30;
        i++;
    }
    numerator *= minus;

}
////////////////////////////////////////////////////////////////////////////////////////
template<class T>
std::ostream& operator<< (std::ostream& s, Fraction<T>& f) //reloading << operation.
{
    s << f.numerator << "/" << f.denomenator;
    return s;
}
//////////////////////////////////////////////////////////////////////////////////////
template<class T>
std::istream& operator>> (std::istream& s, Fraction<T>& f) //reloading >> operation.
{
    char fract1[MAX];
    std:: cin.get(fract1, MAX);
    f = fract1;

return s;
}
