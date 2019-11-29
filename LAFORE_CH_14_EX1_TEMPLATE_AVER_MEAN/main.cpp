#include <iostream>
template <class T>
double average(T* mass, int size)
{
    double summ{0};
    for(int i =0; i < size; i++)
        summ += mass[i];
    return summ/size;
}


int main()
{
    int massi[] = {1, 2 , 3, 5, 8};
    std::cout << average(massi, 5)<< std::endl;
    long massl[] = {15, 22 , 36, 15, 8};
    std::cout << average(massl, 5)<< std::endl;
    double massd[] = {1.2, 2.3 , 3.8, 5.5, 8.1};
    std::cout << average(massd, 5)<< std::endl;
    char massc[] = {1, 2 , 3, 5, 8};
    std::cout << average(massc, 5)<< std::endl;
    return 0;
}
