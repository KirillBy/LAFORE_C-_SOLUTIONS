
#include <iostream>
#include <fstream>
#include <string>
class name  {
private:
    std::string WORKER_NAME;
    std::string WORKER_SURNAME;
    int WORKER_NUMBER;
public:
    int ADDINFO(std::ofstream &OUTFILE);
    int SHOWINFO(std::string const &FILE_NAME );

};

/////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
std::string FILE_NAME = "Workers.txt";

char CHOICE = 'y';
std::ofstream OUTFILE;
OUTFILE.open(FILE_NAME, std::ios::app);
if(!OUTFILE.is_open())
{
    std::cout<<"Error opening\n";
    return 1;
}
std::cout<<"Do you want to enter distance(n to exit, y to enter) ->"; std::cin>> CHOICE;
while(CHOICE == 'y')
{

       name NEWWORKER;
       NEWWORKER.ADDINFO(OUTFILE);
       std::cout<<"Do you want to enter more distance(n to exit, y to enter) ->"; std::cin>> CHOICE;
       std::cin.ignore();
}

     OUTFILE.close();

     name RECEIVEWORKER;
     RECEIVEWORKER.SHOWINFO(FILE_NAME);
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////
int name::ADDINFO(std::ofstream &OUTFILE)
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
   return 0;


    OUTFILE<<WORKER_NAME<<" "<<WORKER_SURNAME<<" "<<WORKER_NUMBER<<"\n";
    return 1;
}
////////////////////////////////////////////////////////////////////////////////////////////
int name::SHOWINFO(std::string const &FILE_NAME )
{
    int SELECTED_NUMBER;
    std::cout<<"Enter number of worker to show";
    std::cin >> SELECTED_NUMBER;
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
        return 1;
    if(SELECTED_NUMBER == WORKER_NUMBER)
    std::cout<<WORKER_NAME<<" "<<WORKER_SURNAME<<" "<<WORKER_NUMBER<<"\n";
    }
    INFILE.close();
    return 1;
}
