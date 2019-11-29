#include "distance.h"
#include <iostream>
Distance::Distance(): feet(0), inches(0)
{

}
Distance::Distance(int ft, float in): feet(ft), inches(in)
{

}
void Distance::getdist()
{
    std::cout<<"Enter a number of ft-> "; std::cin >> feet;
    std::cout<<"Enter a number of inches-> "; std::cin >> inches;
}
void Distance::showdist()
{
    std::cout<<feet<<"\'-"<<inches<<"\"\n";
}
void Distance::add_dist(Distance d2, Distance d3)
{
    inches = d2.inches + d3.inches;
    feet = 0;
    if(inches >= 12.0F)
    {
     inches -= 12.0F;
     feet++;
    }
    feet += d2.feet + d3.feet;
}
