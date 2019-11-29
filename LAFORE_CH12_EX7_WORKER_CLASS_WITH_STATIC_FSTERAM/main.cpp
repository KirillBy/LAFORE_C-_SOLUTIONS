#include <iostream>
#include <fstream>
#include <string>
class name  {
private:
    std::string WORKER_NAME;
    std::string WORKER_SURNAME;
    int WORKER_NUMBER;
    std::fstream INOUTFILE;
public:
    int OPENFILE_TOWRITE(std::string const &FILE_NAME);
    int OPENFILE_TOREAD(std::string const &FILE_NAME);
    int ADDINFO();
    int SHOWINFO();

};

/////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
std::string FILE_NAME = "Workers.txt";
name NEWWORKER;
NEWWORKER.OPENFILE_TOWRITE(FILE_NAME);
NEWWORKER.ADDINFO();
NEWWORKER.OPENFILE_TOREAD(FILE_NAME);
NEWWORKER.SHOWINFO();
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////
int name::OPENFILE_TOWRITE(const std::string &FILE_NAME)
{
    INOUTFILE.open(FILE_NAME, std::ios::app );
    if(!INOUTFILE.is_open())
    {
        std::cout<<"Error opening\n";
        return 1;
    }
    return 0;
}

int name::OPENFILE_TOREAD(const std::string &FILE_NAME)
{
    INOUTFILE.open(FILE_NAME);
    if(!INOUTFILE.is_open())
    {
        std::cout<<"Error opening\n";
        return 1;
    }
    INOUTFILE.seekg(0);
    return 0;
}

int name::ADDINFO()
{
    char CHOICE = 'y';
    if(!INOUTFILE.is_open())
    {
        std::cout<<"File isn't open\n";
        return 1;
    }
    std::cout<<"Do you want to enter distance(n to exit, y to enter) ->"; std::cin>> CHOICE; std::cin.ignore();
    while(CHOICE == 'y')
    {

    std::cout << "Enter name of the worker " << std::endl;
    try { std::getline(std::cin, WORKER_NAME);}
    catch (std::fstream::failure e)
    {
        std::cout << "Error (incorrect name of worker)" << std::endl;
        std::cin.clear();
        std::cin.ignore();
        return 0;
    }

    std::cout << "Enter surname of the worker " << std::endl;
    try { std::getline(std::cin, WORKER_SURNAME);}
    catch (std::fstream::failure e)
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
    INOUTFILE<<WORKER_NAME<<" "<<WORKER_SURNAME<<" "<<WORKER_NUMBER<<"\n";
    std::cout<<"Do you want to enter more distance(n to exit, y to enter) ->"; std::cin>> CHOICE;
    std::cin.ignore();
}
INOUTFILE.close();
    return 01;
}
////////////////////////////////////////////////////////////////////////////////////////////
int name::SHOWINFO( )
{
    if(!INOUTFILE.is_open())
    {
        std::cout<<"File isn't open\n";
        return 1;
    }
    int SELECTED_NUMBER;
    std::cout<<"Enter number of worker to show";
    std::cin >> SELECTED_NUMBER;

    while(!INOUTFILE.eof())
    {
    INOUTFILE>>WORKER_NAME>>WORKER_SURNAME>>WORKER_NUMBER;
    if(INOUTFILE.eof())
        return 1;
    if(SELECTED_NUMBER == WORKER_NUMBER)
    std::cout<<WORKER_NAME<<" "<<WORKER_SURNAME<<" "<<WORKER_NUMBER<<"\n";
    }

    return 0;
}
