//LongestIncreasing Subsequence
/*

Given a sequence of numbers 
  Input: 5,2,6,3,4,1,9,9,8,9,5
  Output:2,3,4,8,9
  
  
  
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


int lis(int *arr, int n , int *max)
{
	
	if( n==1)
	return 1;
	
	int res, max_ending=1;
	for(i=1; i< n; i++)
	{
		res=lis(arr,i,max);
		if( arr[i-1]<arr[n-1] && res +1 > max_ending)
		  max_ending = res +1
	}
	
	 if(*max < max_ending )
	  *max = max_ending;
	  
	  return max_ending;
}


int longestIncreasingSub(int *input,int n)
{
	int max=1;
	lis(input,n,&max);
	return max;
}
/*int recurseLIS(int *input,int n)
{
	if(n==1)
	 return 1;
	int res, max_ending =1;
	
	for( i =1 ; i<n ; i++)
	{
		res =
	}
     
}




int recursiveLIS(int *input, int n)
{
	int i=0;
	 int count =1,val=input[0];
	 for(i=1 ; i< n ; i++)
	 {	
	     if(input[i]>val)
		 {
			count++;
			val=input[i];
		 }
	 }
	 return count;
}
*/
/*void longestIncSub(int *input, int* output,int n)
{
	int *temp,max,i,j,k;
	temp=(int*)malloc(sizeof(int)*n);
	for( i =0 ;i < n ; i++)
	{
		temp[i]=recursiveLIS(input+i,n-i);
		printf("--t  %d\n",temp[i]);
	}
	max=temp[0];
	j=0;
	for( i=1; i<n ; i++)
	{ 
	   if(temp[i]>max)
	     {
		 max=temp[i];
		  j=i;
		 }
	}
	//printf ("")
	max= input[j];
	 output[0]=input[j];
	for(i =j,k=1 ; i<n; i++)
	{
		if(input[i]>max)
		{
			max=input[i];
			output[k++]=input[i];
		}
	}
	output[k]=-1;
}*/
int main()
{
	int input[]={5,2,6,3,4,1,9,9,8,9,5};
	int output[11],i;
	longestIncSub(input,output,11);
	for( i=0 ; i < 11; i++)
	 {
	  if(output[i]==-1)
	   break;
	  cout<<output[i]<<endl;
	  }
	  return 0;
} 