#include<stdio.h>
#include<stdlib.h>

int findRec( int *a, int min, int max)
{
	int mid = (min +max)/2;
	
	//if(mid < high && a[mid+1] < a[mid])
	 if(min ==max)
	 return a[min];
	 
	 if(min < mid && a[mid]<a[mid-1])
		return a[mid];
  
	if( a[min] < a[mid])
	{
		return findRec(a,mid,max);
	}
	 else
	 return findRec(a,min,mid);
	 
}

int findMin(int * a, int n)
{
	int temp;
	temp =findRec(a,0,n-1);
	return temp;
}

int main()
{

int* A;
int n,i;
scanf("%d",&n);
A = (int*)malloc(sizeof(int)*n);
for ( i=0 ; i<n; i++)
{
 scanf("%d",A+i);
}
printf("Min =%d\n",findMin(A,n));
return 0;
}