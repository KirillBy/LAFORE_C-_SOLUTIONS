#include <iostream>
template <class T>
void swap(T& first, T& second) //template function for swapping
{
    T temp {0};
    temp = first;
    first = second;
    second = temp;
}


int main()
{

    int FIRST{5};
    int SECOND{20};
    std::cout << "FIRST = "<< FIRST << std::endl;
    std::cout << "SECOND = "<< SECOND << std::endl;
    swap(FIRST, SECOND); // checking with int
    std::cout << "SWAPPING...."<< std::endl;
    std::cout << "FIRST = "<< FIRST << std::endl;
    std::cout << "SECOND = "<< SECOND << std::endl;
    std::cout << "////////////////"<< std::endl;
    float FIRSTFLOAT{5.5F};
    float SECONDFLOAT{20.5F};
    std::cout << "FIRST = "<< FIRSTFLOAT << std::endl;
    std::cout << "SECOND = "<< SECONDFLOAT << std::endl;
    swap(FIRSTFLOAT, SECONDFLOAT); // checking with float
    std::cout << "SWAPPING...."<< std::endl;
    std::cout << "FIRST = "<< FIRSTFLOAT << std::endl;
    std::cout << "SECOND = "<< SECONDFLOAT << std::endl;
    std::cout << "////////////////"<< std::endl;
    return 0;
}
