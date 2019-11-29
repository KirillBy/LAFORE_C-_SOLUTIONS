// empl_io.cpp
// Input/output object's employee to file
// Supporting objects with different size
#include <fstream>      // for file stream functions
#include <iostream>
#include <typeinfo>     // for typeid()
using namespace std;


const int LEN = 32;     // Max length of surname
const int MAXEM = 100;  // Max number of employees

enum employee_type {tmanager, tscientist, tlaborer, tunknown};
///////////////////////////////////////////////////////////
class employee                // class employee
  {
  private:
    char name[LEN];           // surname of employees
    unsigned long number;     // № of employee
    static int n;             // current number of workers
    static employee* arrap[]; // array of pointers
                              // on employee class
  public:
    virtual void getdata()
      {
      cin.ignore(10, '\n');
      cout << "  Enter a surname: "; cin >> name;
      cout << "  Enter a №: ";    cin >> number;
      }
    virtual void putdata()
      {
      cout << "\n  Surname: " << name;
      cout << "\n  №: " << number;
      }
    virtual employee_type get_type(); // get type
    static void add();                // add employee
    static void display();            // show info about all employees
    static void read();               // reading from file
    static void write();              // writing to file
  };
//---------------------------------------------------------
//static variables
int employee::n;                  // current number of employees
employee* employee::arrap[MAXEM]; // array of pointers
                                  // on employee class
///////////////////////////////////////////////////////////
//class manager
class manager : public employee
  {
  private:
    char title[LEN];  // title ("vice-president" etc.)
    double dues;      // Taxes of golf-club
  public:
    void getdata()
      {
      employee::getdata();
      cout << "  Enter title: ";       cin >> title;
      cout << "  Enter taxes for golf-club: ";       cin >> dues;
      }
    void putdata()
      {
      employee::putdata();
      cout << "\n  Title: " << title;
      cout << "\n  Golf-club taxes: " << dues;
      }
  };
///////////////////////////////////////////////////////////
//class scientist
class scientist : public employee
  {
  private:
    int pubs;              // number of publications
  public:
    void getdata()
      {
      employee::getdata();
      cout << "  Enter a number of publications: "; cin >> pubs;
      }
    void putdata()
      {
      employee::putdata();
      cout << "\n  Number of publications: " << pubs;
      }
  };
///////////////////////////////////////////////////////////
//class laborer
class laborer : public employee
  {
  };
///////////////////////////////////////////////////////////
//add employee to list (storage in RAM)
void employee::add()
  {
  char ch;
  cout << "'m' for adding manager"
        "\n's' for adding scientist"
        "\n'l' for adding laborer"
        "\nYour choice: ";
  cin >> ch;
  switch(ch)
    {          //creating new object of choisen type
    case 'm': arrap[n] = new manager;  break;
    case 's': arrap[n] = new scientist; break;
    case 'l': arrap[n] = new laborer;  break;
    default: cout << "\nUnknoun type\n"; return;
    }
  arrap[n++]->getdata();  //Get info from user

  }
//---------------------------------------------------------
//Show info about all employees
void employee::display()
  {
  for(int j=0; j<n; j++)
    {
    cout  << (j+1);                // show number
    switch( arrap[j]->get_type() ) //show type
      {
      case tmanager:  cout << ". Type: Manger";  break;
      case tscientist: cout << ". Type: Scientist"; break;
      case tlaborer:   cout << ". Type: Laborer";  break;
      default: cout << ". Unknown type";
      }
    arrap[j]->putdata();           // Show info
    cout << endl;
    }
  }
//---------------------------------------------------------
//Returning type of object
employee_type employee::get_type()
  {
  if( typeid(*this) == typeid(manager) )
    return tmanager;
  else if( typeid(*this)==typeid(scientist) )
    return tscientist;
  else if( typeid(*this)==typeid(laborer) )
    return tlaborer;
  else
    { cerr << "\nUnknown employee type";  }
  return tunknown;
  }
//---------------------------------------------------------
//Write objects from RAW to file
void employee::write()
  {
    int size{};
  ofstream ouf;           // open ofstream in binary
  employee_type etype{};   // type of each employee object

  ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
  if(!ouf.is_open())
    { cout << "\nError opening file\n"; return; }
  for(int j=0; j<n; j++)  // for each object
    {                     // get the type
    etype = arrap[j]->get_type();
                          // write info to file
    ouf.write( reinterpret_cast<char*>(&etype), sizeof(etype) );
    switch(etype)         // find its size
      {
      case tmanager:  size=sizeof(manager); break;
      case tscientist: size=sizeof(scientist); break;
      case tlaborer:  size=sizeof(laborer); break;
      case tunknown: break;
      }
    ouf.write( reinterpret_cast<char*>(arrap[j]), size ); //writing employee object to file
    arrap[j]->display();
    if(!ouf)
      { cout << "\nError writing file\n"; return; }

    }
  cout << "Writed  " << n << " employees.\n";
  }
//---------------------------------------------------------
//reading all info from file to RAM
void employee::read()
  {
  int size;               // employee object size
  employee_type etype;    // employee type
  ifstream inf;           // open ifstream in binary
  inf.open("EMPLOY.DAT", ios::binary);
  if(!inf.is_open())
    { cout << "\nError opening file\n"; return; }
  n = 0;                  // No employees in file
  while(true)
    {                     // reading next employee
    inf.read( reinterpret_cast<char*>(&etype), sizeof(etype) );
    if( inf.eof() )       // exit from EOF cicle
      break;
    if(!inf)              // Reading error
      { cout << "\nError opening file\n"; return; }
    switch(etype)
      {                   // Create new employee
      case tmanager:      //with correct type
        arrap[n] = new manager;
        size=sizeof(manager);
        break;
      case tscientist:
        arrap[n] = new scientist;
        size=sizeof(scientist);
        break;
      case tlaborer:
        arrap[n] = new laborer;
        size=sizeof(laborer);
        break;
      default: cout << "\nUnknown type in fi"
                       "le \n"; return;
      }                   // reading info from file
    inf.read( reinterpret_cast<char*>(arrap[n]), size);
    cout << etype << endl;
    arrap[n]->putdata();
    if(!inf)              // not EOF error
      { cout << "\nError reading info from file\n"; return; }
    n++;                  // get up counter of workers
    }  //end while
  cout << "Reading of" << n << " employees\n";
  }
///////////////////////////////////////////////////////////
int main()
  {
  char ch{};
  while(ch != 'x')
    {
    cout << "'a' - add info about employee "
          "\n'd' - show info about all employees"
          "\n'w' - write all info to file"
          "\n'r' - read all info from file"
          "\n'x' - exit"
          "\nYou choice: ";
    cin >> ch;
    switch(ch)
      {
      case 'a':           // add employee
        employee::add(); break;
      case 'd':           // show all info
        employee::display(); break;
      case 'w':           // write to file
        employee::write(); break;
      case 'r':           // read all info from file
        employee::read(); break;
      case 'x': break;  // exit
      default: cout << "\nUnknown command";
      }  //end switch
    }  //end while

  return 0;
  }  //end main()

