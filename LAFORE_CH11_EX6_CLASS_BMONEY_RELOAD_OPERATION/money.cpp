#include "money.h"

void money::mstold() //  changing money sum to int
{
    {
        char newsumm[MAX] = {};
        unsigned long n = strlen(strsumm);
        int m = 0;
        for (unsigned long i = 0; i < n; i++)
        {
            if (isdigit(strsumm[i]) != 0 || strsumm[i] == '.')
            {
                newsumm[m] = strsumm[i];
                m++;
            }
        }
        newsumm[m] = '\0';
        summ = std::stold(newsumm);
        strcpy(strsumm, newsumm);
    }
}
//////////
money money::operator +(money &a) const // //operator + reload
{
    money temp;
    temp.summ = summ + a.summ;
    return temp;
}
/////////
money money::operator -(money &a) const //operator - reload
{
    money temp;
    temp.summ = summ - a.summ;
    return temp;
}
////////
money money::operator *(long double a) const //operator * reload
{
    money temp;
    temp.summ = summ * a;
    return temp;
}

money money::operator /(long double a) const //operator / reload
{
    money temp;
    temp.summ = summ / a;
    return temp;
}
/////////
long double money::operator / (money &a) const
{
    long double b = summ / a.summ;
    return b;
}
/////////
std::ostream& operator<< (std::ostream& s, money& f) //reloading << operation.
{

    s << f.summ;
    return s;
}
//////////
std::istream& operator>> (std::istream& s, money& f) //reloading >> operation.
{

    std::cout << "Enter mone summ in $xxx,xxx,xxx.xx format ";
    s >> std::setw(MAX) >> f.strsumm;

return s;
}
