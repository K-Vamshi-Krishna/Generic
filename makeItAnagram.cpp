#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string a,b;
    int s[26];
	int t[26];
	int k;
	int total=0;
    for ( int i=0 ; i< 26 ; i++)
        {
		s[i]=0;
		t[i]=0;
		}
    cin>>a>>b;
    for (int i =0 ;i < a.length(); i++)
        {
		k = a[i]-'a';
		s[k]++;
		}
    for( int i=0; i< b.length(); i++)
       {
	    k = b[i]-'a';
 	     if(s[k]!=0)
		   {
		   s[k]--;
		   t[k]++;
		   }
		} 
	for( int i=0 ; i< 26 ; i++)
       	total+=t[i];
		
		cout<<a.length()+b.length() -(2*total)<<endl;
    return 0;
}