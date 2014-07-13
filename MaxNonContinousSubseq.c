#include<stdio.h>

/*
 8th oct
 
 find the subsequence which is not continous and maximum subsequence
 Input an array : 3 2 5 10 7

Output : 15 = 3+5+7

1. pick and element 
   leave the next element and add so that it is 

     3  2  5 10  7
    13 12 12 13 12
    	  15
		  
excl	0 incl= 2
excl   	    3,8
inc

proof by induction
 if n=1, then it is number itself
 if n==2 then which ever is greater is the element;
 
 let us suppose that it is fine for n-1,
 so there are 2 sums which includes n-1 element i.e incl
                           excludes n-1st element i.e excl;
						assume that excl >incl;
						new incl= excl +arr[n];
						    excl = excl;
					    else
						   excl =incl // include till the previous element
						   incl=excl+arr[n];
						   
        
*/

int findMax(int *arr,int n)
{
	int i;
	int incl,excl,excl_new;
	excl=0;
	incl=arr[0];
	
	for(i=1; i<n;i++)
	{
		if(excl>incl)
		excl_new=excl;
		else
		excl_new=incl;
		incl = excl +arr[i];
		excl=excl_new;
	}
	
	return ((incl>excl) ?incl:excl);
}
int main()
{
	int arr[] ={3,2,5,10,7};
	
	printf("%d\n",findMax(arr,5));
}