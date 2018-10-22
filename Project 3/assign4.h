
S::S(int i1,string s1)
{
	i=i1;
	s=s1;
}
string S::  operator [] ( int a)const
{
	return (*this).s;
}
bool S::operator < (S &i1)const
{
	return (i<i1.i)
}
 ostream operator << (ostream &y, const S &z)
 {
 	y << (z).s;
 	return y;
	 
}
