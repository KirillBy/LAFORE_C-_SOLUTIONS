#include <iostream>
#include <fstream>
#include <string>

int main()
{
std::string FILE_NAME = "Workers.txt";
std::string WORKER_NAME;
std::string WORKER_SURNAME;
int WORKER_NUMBER;
char CHOICE = 'y';
std::ofstream OUTFILE;
OUTFILE.open(FILE_NAME);
if(!OUTFILE.is_open())
{
    std::cout<<"Error opening\n";
    return 1;
}
do
{
       std::cout << "Enter name of the worker " << std::endl;
       try { std::getline(std::cin, WORKER_NAME);}
       catch (std::istream::failure e)
       {
           std::cout << "Error (incorrct name of worker)" << std::endl;
           std::cin.clear();
           std::cin.ignore();
           return 0;
       }

       std::cout << "Enter surname of the worker " << std::endl;
       try { std::getline(std::cin, WORKER_SURNAME);}
       catch (std::istream::failure e)
       {
           std::cout << "Error (incorrect surname of worker)" << std::endl;
           std::cin.clear();
           std::cin.ignore();
           return 0;
       }
       std::cout << "Enter number of the worker " << std::endl;
        std::cin>>WORKER_NUMBER;
       if(!std::cin.good())
       break;


       OUTFILE<<WORKER_NAME<<" "<<WORKER_SURNAME<<" "<<WORKER_NUMBER<<"\n";

       std::cout<<"Do you want to enter more distance(n to exit, y to enter) ->"; std::cin>> CHOICE;
       std::cin.ignore();
}while(CHOICE == 'y');
     OUTFILE.close();
     std::ifstream INFILE;
     INFILE.open(FILE_NAME);
     if(!INFILE.is_open())
     {
         std::cout<<"Error opening\n";
         return 1;
     }
     while(!INFILE.eof())
     {
         INFILE>>WORKER_NAME>>WORKER_SURNAME>>WORKER_NUMBER;
         if(INFILE.eof())
             break;
         std::cout<<WORKER_NAME<<" "<<WORKER_SURNAME<<" "<<WORKER_NUMBER<<"\n";
     }

    return 0;
}
