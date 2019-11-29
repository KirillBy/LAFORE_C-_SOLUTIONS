#include <iostream>
#include <string.h>
const int LIMIT = 100;    // massive size
///////////////////////////////////////////////////////////
template<class T>
class safearray
{
  private:
    T arr [ LIMIT ];
  public:
    class OutOfMass{public: std::string errormsq; OutOfMass(std::string s){ errormsq = s;}}; //exception class
                                                                                     //with string argument
    T& operator[ ] ( int n )
      {
        if ( n < 0 || n >= LIMIT )
          { throw OutOfMass("Out of limit"); }
        return arr [ n ];
      }
};
///////////////////////////////////////////////////////////
int main ( )
{
  safearray<int> sa1;
  try {
      // set elements value
      for ( int j = 0; j < LIMIT; j++ )
        sa1[ j ] = j * 10;
      // display elements
      for ( int j = 0; j < LIMIT; j++ )
      {
        int temp = sa1 [ j ];
        std::cout << "Element " << j << " is " << temp << std::endl;
      }


  } catch (safearray<int>::OutOfMass ex1) {  //catching the mistake here
      std::cout<<ex1.errormsq<<std::endl;
  }



  return 0;
}

