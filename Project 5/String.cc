/*******************************************
COURSE: CSCI689
NAME: SAHITHI KAMIREDDY
ZID: z1831177
INSTRUCTOR: KIRK DUFFIN
TA : NITHIN DEVANG
*******************************************/

/*********** ASSIGNMENT 5 *************/

#include "String.h"

String::String ()
{
    _length = 0;
    buffer   = new char[0];
}

String::String (char ch)
{
    _length = 1;
    buffer   = new char(ch);
}

String::String (const char* ch)
{
    if (ch)
    {
        unsigned n = 0;
        while (ch[n] != '\0') n++;
        _length = n;
        buffer   = new char[n];
        for (unsigned k=0; k < n; k++)
            buffer[k] = ch[k];
    } else
    {
        _length = 0;
        buffer   = new char[0];
    }
}

String::String (const String& s)
{
    _length = s.length();
    buffer   = new char[_length];
    for (unsigned k=0; k < _length; k++)
        buffer[k] = s[k];
}



String::~String ( )
{
    delete[] buffer;
}

bool String::empty() const
{
	//Checks size of string to determine if empty
	if (_length == 0)
		return true;
	else
		return false;
}

unsigned String::length ( ) const
{
    return _length;
}

unsigned String::size ( ) const
{
    return _length;
}

int String::index (char ch) const
{
    for (unsigned k=0; k < _length; k++)
        if (buffer[k] == ch) return (int)k;
    return -1;
}





std::ostream& operator<< (std::ostream& os, const String& s)
{
    if (s.length() > 0)
    {
        for (unsigned k=0; k < s.length(); k++)
            os << s[k];
    } else os << "";

    return os;
}

std::istream& operator>> (std::istream& is, String& s)
{
    char* ch = new char[1000];
    is >> ch;
    s = String(ch);
    delete[] ch;

    return is;
}



char String::operator[] (unsigned k) const
{
    if (k >= _length) throw 1;
    return buffer[k];
}

char& String::operator[] (unsigned k)
{
    if (k >= _length) throw 1;
    return buffer[k];
}



String& String::operator= (const String& s)
{
    if(this == &s) return *this;

    delete buffer;
    _length = s.length();
    buffer   = new char[_length];
    for (unsigned k=0; k < _length; k++)
        buffer[k] = s[k];
    return *this;
}



String& String::operator+= (const String& s)
{
    unsigned length = _length + s.length();
    char*    str = new char[length];

    for (unsigned k=0; k < _length; k++)
        str[k] = buffer[k];

    for (unsigned i=0; i < s.length(); i++)
        str[_length+i] = s[i];

    delete buffer;
    _length = length;
    buffer   = str;
    return *this;
}



String operator+ (const String& lhs, const String& rhs)
{
    return String(lhs) += rhs;
}

String operator+ (const String& lhs, char rhs)
{
    return String(lhs) += String(rhs);
}

String operator+ (const String& lhs, const char* rhs)
{
    return String(lhs) += String(rhs);
}

String operator+ (char lhs, const String& rhs)
{
    return String(lhs) += rhs;
}
String operator+ (const char* lhs, const String& rhs)
{
    return String(lhs) += rhs;
}



bool operator== (const String& lhs, const String& rhs)
{
    if (lhs.length() != rhs.length()) return false;

    unsigned cap = lhs.length();
    unsigned   n = 0;
    while ((n < cap) && (lhs[n] == rhs[n])) n++;
    return (n == cap);
}

bool operator== (const String& lhs, char rhs)
{
    return (lhs == String(rhs));
}

bool operator== (const String& lhs, const char* rhs)
{
    return (lhs == String(rhs));
}

bool operator== (char lhs, const String& rhs)
{
    return (String(lhs) == rhs);
}

bool operator== (const char* lhs, const String& rhs)
{
    return (String(lhs) == rhs);
}



bool operator> (const String& lhs, const String& rhs)
{
    unsigned cap = (lhs.length() < rhs.length()) ? lhs.length() : rhs.length();
    unsigned n = 0;
    while ((n < cap) && (lhs[n] == rhs[n])) n++;
    if (n == cap) return (lhs.length() > rhs.length());

    if ( (('A'<=lhs[n]&&lhs[n]<='Z') || ('a'<=lhs[n]&&lhs[n]<='z')) &&
         (('A'<=rhs[n]&&rhs[n]<='Z') || ('a'<=rhs[n]&&rhs[n]<='z')) )
    {
        char A = (lhs[n] & ~32);
        char B = (rhs[n] & ~32);
        if (A != B) return (A > B);
    }
    return lhs[n] > rhs[n];
}

bool operator> (const String& lhs, char rhs)
{
    return (lhs > String(rhs));
}

bool operator> (const String& lhs, const char* rhs)
{
    return (lhs > String(rhs));
}

bool operator> (char lhs, const String& rhs)
{
    return (String(lhs) > rhs);
}

bool operator> (const char* lhs, const String& rhs)
{
    return (String(lhs) > rhs);
}



bool operator!= (const String& lhs, const String& rhs)
{
    return !(lhs == rhs);
}

bool operator!= (const String& lhs, char rhs)
{
    return !(lhs == rhs);
}

bool operator!= (const String& lhs, const char* rhs)
{
    return !(lhs == rhs);
}

bool operator!= (char lhs, const String& rhs)
{
    return !(lhs == rhs);
}

bool operator!= (const char* lhs, const String& rhs)
{
    return !(lhs == rhs);
}



bool operator< (const String& lhs, const String& rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (const String& lhs, char rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (const String& lhs, const char* rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (char lhs, const String& rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (const char* lhs, const String& rhs)
{
    return !(lhs == rhs) && !(lhs > rhs);
}



bool operator<= (const String& lhs, const String& rhs)
{
    return !(lhs > rhs);
}

bool operator<= (const String& lhs, char rhs)
{
    return !(lhs > rhs);
}

bool operator<= (const String& lhs, const char* rhs)
{
    return !(lhs > rhs);
}

bool operator<= (char lhs, const String& rhs)
{
    return !(lhs > rhs);
}

bool operator<= (const char* lhs, const String& rhs)
{
    return !(lhs > rhs);
}



bool operator>= (const String& lhs, const String& rhs)
{
    return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (const String& lhs, char rhs)
{
    return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (const String& lhs, const char* rhs)
{
    return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (char lhs, const String& rhs)
{
    return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (const char* lhs, const String& rhs)
{
    return (lhs == rhs) || (lhs > rhs);
}




