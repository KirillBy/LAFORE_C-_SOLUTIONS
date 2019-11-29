
#include <iostream>

#include <string.h>
#include <stdlib.h>
///////////////////////////////////////////////////////////
class String
{
  private:
   enum { SZ = 80 };
    char str [ SZ ];
  public:
class OvrFlwEx{public: std::string errmsg; OvrFlwEx(std::string s) {errmsg = s;}};
    String ( )
      { strcpy ( str, "" );  }

    String ( char s [ ] )
      { strcpy ( str, s );if(strlen(str) >= SZ){throw (OvrFlwEx("Oversized string"));}}

    void display ( ) const
      { std::cout << str; }

    String operator+ ( String ss ) const
      {
        String temp;
        if ( strlen ( str ) + strlen ( ss.str ) >= SZ )
        {
            throw (OvrFlwEx("Oversized new string"));

        }
        strcpy ( temp.str, str );
        strcat ( temp.str, ss.str );
        return temp;
      }
};
///////////////////////////////////////////////////////////
int main ( )
{
    try {
        String s1 = "\nMerry Cristmas mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm";
        String s2 = "Happy New Year";
        String s3;

        s1.display ( );
        s2.display ( );
        s3.display ( );
        s3 = s1 + s2;
        s3.display ( );
        std::cout << std::endl;
    } catch (String::OvrFlwEx ex) {
        std::cout << std::endl << ex.errmsg << std::endl;
    }

  return 0;
}
