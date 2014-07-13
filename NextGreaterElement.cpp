#include<stack>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
 stack<int> nextElem;
 
 int * arr, *out,n;
 cin>>n;
 arr =new int[n];
 out =new int[n];
 for (int i=0 ; i<n ; i++)
 cin>>arr[i];
 
 nextElem.push(arr[0]);
 for( int i=1,j=0 ; i<n;i++)
 {
	j=1;
	while(!nextElem.empty() && nextElem.top()<arr[i])
	 {
		
		out[i-j]=arr[i];
		j++;
		nextElem.pop();
	}
	
	nextElem.push(arr[i]);
 }
  int i=n-1;
  while(!nextElem.empty())
  {
    out[i--]=-1;
	nextElem.pop();
  }
  
  for( int i=0 ; i<n ; i++)
   cout<<out[i]<<"\t";
  
}