#include <iostream>
#include "distance.h"
#include <fstream>
int main()
{
Distance dist;
std::fstream file;
char choice = 'y';
file.open( "DIST_BASE", std::ios::app | std::ios::binary | std::ios::in | std::ios::out);
if(!file.is_open())
{
    std::cout<<"Error open file.Bye bye....\n";
    exit(1);
}

do
{
    dist.getdist();
    file.write(reinterpret_cast<char*>(&dist), sizeof(dist));
    std::cout<<"Do you want to enter more distance(n to exit, y to enter) ->"; std::cin>> choice;
} while(choice == 'y');
file.seekg(0);
file.read(reinterpret_cast<char*>(&dist), sizeof(dist));
while(!file.eof())
{
    dist.showdist();
    file.read(reinterpret_cast<char*>(&dist), sizeof(dist));
}
file.close();
    return 0;
}
