/*******************************************
COURSE: CSCI689
NAME: SAHITHI KAMIREDDY
ZID: z1831177
INSTRUCTOR: KIRK DUFFIN
TA : NITHIN DEVANG
*******************************************/

/*********** ASSIGNMENT 5 *************/

#ifndef STRING_H
#define STRING_H

#include <iostream>

/* C++ implementation of a Sting
  String buffer points to NULL or a valid address.
 String _length shows amount of allocated space.
 */
class String
{
    char*    buffer;    //< The ASCII characters which have Strings //
    unsigned _length;  //No. of characters allocated in buffer //

public:

    
      // String Constructor ,where String _length is set equal to 0.
     
    String ( );

    // String constructor where buffer =ch and string length =1
     
    String (char ch);

    /*
      char* String Constructor where  ch a char* null-terminated string.
     String buffer = ch allocated values, except the null-terminator.
     */
    String (const char* ch);

    /* string copy Constructor having an s String instance.
        This String will be identical to String s.
     */
    String (const String& s);

    /*
     String Destructor where 
    String buffer is deleted here 
     */
    ~String ( );


    bool empty() const;		//Checking whether  string is empty or not

    /* String _length.
        return Value in String ch _length.
     */
    unsigned length ( ) const;

    unsigned size ( ) const;

    /* String index of  ch.
    returns the index of  ch in String, if exists else  returns -1
     */
    int index (char ch) const;

    
    /*
     * Stream operators with stream object and string object
       returns Stream object which contains  String content.
     */
    
    friend std::ostream& operator<< (std::ostream& so, const String& s);
    friend std::istream& operator>> (std::istream& so,       String& s);
    

    
    /* For retreiving the  String character.   
      k Index value in String and  k is less than String _length
      returns  character at k index of String buffer with return datatype int
      */
    char  operator[] (unsigned k) const;
    char& operator[] (unsigned k);


    /* The  String value with a String object s and a
     String referencing to the current instance *this.
     String = s.
     */
    String& operator= (const String& s);

    /* String concatenation with string object s by itself 
     returning String referencing to current instance *this.
     */
    String& operator+= (const String& s);

    /* String concatenation operator  with lhs and rhs where lhs is left hand operand 
    and rhs is right hand operand
    returning  Copy of a String object.
    */
    friend String operator+ (const String& lhs, const String& rhs);
    friend String operator+ (const String& lhs, char          rhs);
    /*String assignment operator
    returning  True if lhs and rhs have the same _length, and each character
    in the buffer  are same with  both value and index
    */
    friend bool operator== (const String& lhs, const String& rhs);
   
    /*
      String Greater-than operator which 
     returns true, if lhs is in dictionary order to
     rhs when comparing alphabetical characters or lhs is
      greater in ASCII value rhs, in the String
       buffer indices.
     */
    friend bool operator> (const String& lhs, const String& rhs);
    
    /* String not=equal operator which 
     returns true, if lhs is not equal to rhs.
     

     */
    friend bool operator!= (const String& lhs, const String& rhs);
    /* String inequality: Less-than.
      which returns True, if lhs is neither equal to, nor greater-than rhs.
     */
    friend bool operator< (const String& lhs, const String& rhs);
    

    
    /* String  Less-than or equal operator which 
     returns True, if  lhs is not greater than  rhs
      */
    friend bool operator<= (const String& lhs, const String& rhs);
    
    /* String  Greater-than or equal operator  which 
    returns True, if  lhs is greater-than or equal to rhs
    */
    friend bool operator>= (const String& lhs, const String& rhs);
    
};

#endif // STRING_H
