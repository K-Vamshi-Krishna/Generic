#include<stdio.h>
#include<stdlib.h>

int findPair(int * a, int k,int num)//assuming that array A is sorted
{
	unsigned i,j;
	j=num-1;
	while( a[j]>=k)
	 j--;
	for( i=0; i<j &&a[i]+a[j]!=k; )
	  {
		if(a[i]+a[j] >k)
		j--;
		else
		i++;
	  }
	  if( i>=j)
	  return -1;
	  else
	  return 0;
}

int main()
{
	int *A,i, num,k;
	scanf("%d",&num);
    scanf("%d",&k); 
    A =	(int*) malloc(sizeof(int)*num);
	
	for( i=0 ;i< num ; i++)
	 scanf("%d",A+i);
	 
	
    if(findPair(A,k,num)==-1)
    printf("Not found\n");
    else
    printf("found\n");		
}

