/*
longest substring without repeating characters.

string abcdefgh 

array of characters which has the location.
position of the starting of the string 



*/

#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

string longestString(string s)
{
   char character[26];
   int i,m;
   size_t start=0,largeSize=0,size=0;
	for( i=0; i<26; i++)
	character[i]=0;
   for( i=0 ; i< s.length(); i++)
     {
	   m = s[i]-'a';
	   
	   if(character[m] ==0 || i-size > character[m])
        size++;
	   else
	  {	   
        if(size >largeSize)
		  {
		   largeSize=size;
		    cout<<largeSize<<"\t size"<<endl;
		    start = i- largeSize; 
		  }
		 
        size =  i - character[m];      		
	    cout<<size<<"\t size"<<endl;
	   }
       character[m]=i;	   
	 }  
    cout<< s.substr(start,largeSize)<<endl;
   return s;
}


int main()
{
 string s = "geekforgeeks";
 cout<<  longestString(s)<<endl;
}

