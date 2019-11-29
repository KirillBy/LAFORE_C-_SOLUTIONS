#include <iostream>

#include "money.h"


money operator * (money const a, money const b) ; //reload long double * money
money operator / (money const a, money const b) ; //reload long double / money
////////////
int main()
{
    money choice;
    money choice1;
    money choice2;
    std::cin >> choice;
    choice.mstold();
    std::cin >> choice1;
    choice1.mstold();
    choice2 = choice + choice1;
    std::cout << " + "; std::cout << choice2 << std::endl;
    choice2 = choice - choice1;
    std::cout << " - ";std::cout << choice2 << std::endl;
    choice2 = choice * static_cast<long double>(2.2);
    std::cout << " *2.2 ";std::cout << choice2 << std::endl;
    choice2 = choice / static_cast<long double>(2.2);
    std::cout << " /2.2 ";std::cout << choice2 << std::endl;
    choice2 = choice / choice1;
    std::cout << " / ";std::cout << choice2 << std::endl;
    choice2 = static_cast<long double>(2.2) * choice ;
    std::cout << " 2.2* ";std::cout << choice2 << std::endl;
    choice2 = static_cast<long double>(100.25) / choice ;
    std::cout << " 100.25/ ";std::cout << choice2 << std::endl;

    return 0;
}
money operator * (money const a, money const b)//reload long double * money
{
    money c;
    c.summ = a.summ * b.summ;
    return c;
}
money operator / (money const a, money const b)//reload long double / money
{
    money c;
    c.summ = a.summ / b.summ;
    return c;
}
