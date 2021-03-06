#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strings.h"

// default constructor -- create empty string
String::String()
{
   str = new char[ 1 ];  // allocate
   *str = '\0';          // initialize to null string
   len = 0;
}

// conversion constructor
String::String( const char* cstr )
{
   // +1 to ensure room for null terminator
   str = new char[ strlen( cstr ) + 1 ];
   strcpy( str, cstr );
   len = strlen( str );
}

// copy constructor -- String ==> String
String::String( const String& strarg )
{
  // copy an existing String.str into a new
  // one after first allocating sufficient storage
  strcpy( str = new char[ strarg.len + 1 ],
          strarg.str );
  len = strarg.len;
}



// blank string constructor
String::String( const int lenarg )
{
   str = new char[ lenarg + 1 ];
   len = lenarg;
   char* ptr = str;

   for ( int i = 0; i < len; i++ )
      *ptr++ = ' ';
   *ptr = '\0';    // null terminate
}

// destructor -- deallocate storage
String::~String()
{
   delete[ ] str;
}

// write String to standard output
// with a terminating newline
int String::write()
{
   return printf( "%s\n", str );
}

// write String to specified file
int String::write( FILE * outfile )
{
   if ( !outfile )
      return WriteFail;
   else
      return fprintf( outfile, "%s\n", str );
}

// read String from standard input
int String::read()
{
   scanf( "%s", str );

   return len = strlen( str );
}

// read String from designated file
int String::read(FILE * infile )
{
   if ( !infile )
      return ReadFail;
   else {
      fscanf( infile, "%s", str );
      return len = strlen( str );
   }
}

// assignment operator
String& String::operator=( const String& strarg )
{
   // check whether String assigned to itself
   if ( this !=  &strarg ) {
      delete[ ] str;                // free current storage
      len = strarg.len;
      str = new char[ len + 1 ];    // allocate new storage
      strcpy( str, strarg.str );    // copy contents
   }
   return *this;
}

// < operator for less than comparisons
int String::operator<( const String strarg ) const
{
   return strcmp( str, strarg.str ) < 0;
}


// > operator for greater than comparisons
int String::operator>( const String strarg ) const
{
   return strcmp( str, strarg.str ) > 0;
}

// + operator for concatenations
String String::operator+( const String& strarg ) const
{
   // allocate enough storage for 2 strings + '\0'
   char* temp = new char[ len + strarg.len + 1 ];

   // copy 1st string and concatenate second
   strcpy( temp, str );
   strcat( temp, strarg.str );

   // define a variable of type String to be
   // used as a return value
   String retval( temp ); // conversion constructor

   // free temporary storage
   delete[ ] temp;

   return retval;
}

// selection sort an array of String
void sort( String a[ ], int size, int order  )
{
   int next;

   // set comparison operator based on order parm
   int ( String::*compare_op )( const String ) const;
   compare_op =
      ( order == String::Asc ) ? String::operator< :
                                 String::operator>;

   // loop thru array, picking biggest or smallest
   // element each time, depending on sort order
   for ( int i = 0; i < size - 1; i++ ) {
      next = i;  // assume ith String smallest-biggest

      // compare against remaining elements
      for ( int j = i + 1; j < size; j++ )
         if ( ( a[ j ].*compare_op )( a[ next ] ) )
            next = j;

      // put smallest-biggest at position i
      if ( i != next ) {
         String temp = a[ i ];
         a[ i ] = a[ next ];
         a[ next ] = temp;
      }
   }
}