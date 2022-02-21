//this is the file strings.h
// Use an #ifndef to guard against the
// case in which this header file is
// inadvertently #included more than once
// in some other file
// compiler directives : ifndef, define
// compiler guards
#ifndef StringHeaderLoaded_Version_1_0
#define StringHeaderLoaded_Version_1_0
#include <iostream>

class String {
    char* str;      // data member -- private
    int   len;      // actual
  public:
    enum SortOrder { Asc, Desc };
    enum ErrorsIO { ReadFail, WriteFail };
    // constructors-destructor
    String();                 // default constructor
    String( const String& );  // copy constructor
    String( const int );      // string initialized to blanks
    String( const char* );    // from a C string, char*
    ~String();                // destructor
    // other methods as functions
    int write();
    int write( FILE* out );
    int read();
    int read( FILE* in );
    // operators
    String operator+( const String& ) const;
    int operator<( const String ) const;
    int operator>( const String ) const;
    String& operator=( const String& );
    // friends
    friend void sort( String*, int, int ); // selection sort
};

#endif  // StringHeaderLoaded_Version_1_0