#include <iostream>
using namespace std;
const int MAX =3;
///////////////////////////////////////////////////////////
template <class Type>
class Queue
    {
    private:
      Type qu [MAX];      //massive of template type
      int head;           //index of the beggining of massive(queue)
        int tail;         //index of the end of queue
int count;                //number of elements in queue
public:
class full {};            //exception class
class empty {};
//---------------------------------------------------------
Queue()                   //constructor
    {head =-1;tail =-1;count =0;}
void put(Type var)        //add element to the end of queue
    {
    if(count >=MAX)       //if queue is full,
      throw full();       //throw exception
    qu [++tail] = var;    //save element
    ++count;
    if(tail >=MAX-1)
      tail =-1;
    }
//---------------------------------------------------------
Type get()
    {
    if(count <=0)
      throw empty();
    Type temp =qu [++head];
    --count;
    if(head >=MAX-1)
    head =-1;
    return temp;
    }
};
///////////////////////////////////////////////////////////
int main()
    {
    Queue<float>q1;
    float data;
    char choice ='p';
    do
      {
      try
        {
cout <<"\nEnter 'x' for exit,'p' to add,'g' to give element:";
        cin >>choice;
        if(choice == 'p')
          {
          cout <<"Enter element:";
          cin >>data;
          q1.put(data);
          }
        if(choice == 'g')
          cout <<"Data=" <<q1.get()<<endl;
        }
    catch(Queue<float>::full)
      {
      cout <<"Error: queue overflow." <<endl;
      }
    catch(Queue<float>::empty)
      {
      cout <<"Error: queue empty." <<endl;
      }
    }while(choice !='x');
    return 0;
    }
