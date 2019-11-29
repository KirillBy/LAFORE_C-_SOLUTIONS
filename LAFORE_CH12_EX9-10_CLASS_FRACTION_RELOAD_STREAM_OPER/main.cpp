#include <iostream>
#include "fraction.h"




int main()
{

    std::cout << "Enter first fraction in x/y format: ";

    Fraction<int> number1;
    std::cin >> number1;
    std::cout << std::endl;
    std::cin.ignore();
    std::cout << "Enter second fraction in x/y format: ";
    Fraction<int> number2;
    std::cin>>number2;
    std::cout << std::endl;
    Fraction<int> number3 = number1 + number2;
    std::cout<<number1; std::cout << " + ";std::cout<< number2; std::cout << " = ";
    std::cout<< number3;
    std::cout << std::endl;
    number3 = number1 - number2;
    std::cout<<  number1; std::cout << " - "; std::cout<< number2; std::cout << " = ";
    std::cout<< number3;
    std::cout << std::endl;
    number3 = number1 * number2;
    std::cout<< number1; std::cout << " * "; std::cout<< number2; std::cout << " = ";
    std::cout<< number3;
    std::cout << std::endl;
    number3 = number1 / number2;
    std::cout<< number1; std::cout << " / "; std::cout<< number2; std::cout << " = ";
    std::cout<<  number3;
    std::cout << std::endl;

    return 0;
}
