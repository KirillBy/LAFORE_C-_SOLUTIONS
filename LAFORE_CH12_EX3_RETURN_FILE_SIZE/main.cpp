#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    if(argc != 2)
      {
      std::cout<<"Incorrect arguments.\n";
      return 0;
      }
     std::string ORIG_FILE = argv[1];
     std::ifstream infile;
     infile.open(ORIG_FILE, std::ios::in);
     if(!infile.is_open())
     {
         std::cout<<"Error opening file "<<ORIG_FILE<<std::endl;
         return 1;
     }
     long int END_OF_FILE=0;
     infile.seekg(0, std::ios::end);
     END_OF_FILE = infile.tellg();
     std::cout<<"Size of file: "<<END_OF_FILE<<" bytes\n";
     infile.close();
    return 0;
}
