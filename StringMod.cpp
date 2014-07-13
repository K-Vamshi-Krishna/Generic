/*
In this problem, the string is given as the input and int r which should represent the string column wise
string abcdefgh

a d g 
b e h
c f

Output: adgbehcf

Algorithm 
1. Consider the string as  circular string
keep incrementing i by 3 and if it is greater than the string length 

a b c d e f g h 
i =0, 3,6,1,


*/



#include<iostream>
#include<string>
using namespace std;
string  convert(string s, int r)
{
	string m;
	 int i,j,len,k;
	 len = s.length();
	 for( i=0,j=0; i< s.length(); i++,j+=3)
	  {
	      k=j%len;
		  //cout<<j<<k<<len<<"\t";
		  m[i]=s[j%len]; 
     	  cout<<m[i];
	  }	 
	  
	  //cout<< m.length();
	 return m;
}

int main()
{
	string s="abcdefgh";
	int r=3;
	convert(s,r);
}