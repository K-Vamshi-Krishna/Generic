#include<cstdlib>
#include<cassert>
#include<string>
#include<iostream>
using namespace std;

bool isPallindrome(string s)
{
	int i,j;
	for ( i =0 , j= s.size()-1; s[i] ==s[j] && i<=j;i++,j--);
	if( i>j)
	return true;
	else
	return false;
}

void dynamicLongestPallindrome (string s)
{
	int low,high;
	
	
	
}
void longestPallindrome(string s)
{
	int i,j;
	int longest =0,start;
	for ( i=0 ; i< s.size() ; i++)
	 {
		for ( j = i+1 ; j< s.size() ; j++)
		{
			if (isPallindrome(s.substr(i,j-i)))
			{
				if (j-i > longest)
				 {
					longest = j-i;
					start = i;
				 }
			}
		}
	 }
	 cout << s.substr(start,longest)<<endl;
}

int main()
{
	string s("forgeeksskeegfor");
	longestPallindrome(s);
	}