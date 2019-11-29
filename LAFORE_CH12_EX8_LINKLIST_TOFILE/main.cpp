#include <iostream>
#include <fstream>
struct link
{
    int data;
    link* next;
};
//////////////////////
class linklist
{
private:
    link* first;
    std::fstream FILE; // for writing and reading our link
public:
    linklist() {first = nullptr;} //constructur withour arguments
    void additem(int d); //add element
    void display(); // show info
    int save_to_file(); //saving link to file
    int reading_from_file(); // reading link from file

};

int main()
{

    linklist li;

   /* li.additem(76);
    li.additem(77);
    li.additem(78);
    li.additem(79);
    li.additem(80);
    li.save_to_file();*/
   li.reading_from_file();
    li.display();

    return 0;
}
////////////////////////////////////
void linklist::additem(int d)
{
    link * newlink = new link; //new elem in list
    newlink->data = d; //put our data to element
    newlink->next = first; // remember previous address
    first = newlink; // remember this address
}

void linklist::display()
{
    link* current = first; // start from the beggining
    while(current) // while we have elements
    {
        std::cout<<current->data<<std::endl; // show info
        current = current->next; // move to next element
    }
}
/////////////////////////////////////
int linklist::save_to_file()
{
    FILE.open("link.txt", std::ios::app);
    if(!FILE.is_open()) // open file to write data
    {
        std::cout<<"Error opening file"<<std::endl;
        return 1;
    }
    if(nullptr == first) //if link is empty
    {
        std::cout<<"Link is empty"<<std::endl;
        return 1;
    }



   link * current = first; // start from the beggining
    while(current) // while we have elements
    {
        FILE<<current->data<<" "; // write data to file
        current = current->next; // move to next element
    }
    FILE.close();
    return 0;
}

int linklist::reading_from_file()
{
    FILE.open("link.txt");

    if(!FILE.is_open()) // open file to read data
    {
        std::cout<<"Error opening file!!!!!!!"<<std::endl;
        return 1;
    }

while(!FILE.eof())
{

    link * newlink = new link; //new elem in list
    FILE >> newlink->data; //put our data to element
    if(FILE.eof())
    {

    delete  newlink; //delete last 0 element
    FILE.close();

    return 0;
    }
    newlink->next = first; // remember previous address
    first = newlink; // remember this address

}

    return 0;
}
