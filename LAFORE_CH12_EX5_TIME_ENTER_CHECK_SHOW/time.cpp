#include "time.h"
#include <iostream>
TIME::TIME(): HOUR(0), MINUTE(0), SECOND(0)
{

}
int TIME::get_time()
{
    std::cout<<"Enter an hour(0-23)->";
    std::cin>>HOUR;
    if(!std::cin.good())
    {
    std::cout<<"Incorrect hour\n";
    return 1;
    }
    if(HOUR  > 23)
    {
    std::cout<<"Hour should be between 0 and 23\n";
    return 1;
    }
    std::cout<<"Enter a minute(0-59)->";
    std::cin>>MINUTE;
    if(!std::cin.good())
    {
    std::cout<<"Incorrect minute\n";
    return 1;
    }
    if(MINUTE  > 59)
    {
    std::cout<<"Minute should be between 0 and 59\n";
    return 1;
    }
    std::cout<<"Enter a second(0-59)->";
    std::cin>>SECOND;
    if(!std::cin.good())
    {
        std::cout<<"Incorrect second\n";
        return 1;
    }
    if(SECOND  > 59)
    {
    std::cout<<"Second should be between 0 and 59\n";
    return 1;
    }
}
int TIME::put_time()
{
    std::cout<<"Your time:\n";
    if(HOUR < 10)
              std::cout<<"0"<<HOUR<<":";
    else
              std::cout<<HOUR<<":";
    if(MINUTE < 10)
              std::cout<<"0"<<MINUTE<<":";
    else
              std::cout<<MINUTE<<":";
    if(SECOND < 10)
              std::cout<<"0"<<SECOND<<":";
    else
              std::cout<<SECOND<<"\n";
}
