/*

 - Find the number of paths from 0,0 to i,j.
 
 Proof: if(i==0 & j==0 )
    then 0.
else if i==0 or j==0 	
 
*/

#include<stdio.h>


int numOfPaths( int a[4][4],int n)
{
	int b[4][4];
	if( a[0][0]==0)
	   return 0;
	  int i,j;
	  for( i=0 ; i< n; i++)
	  b[0][i]=1 & a[n-1][i];
	  for ( i=1 ; i< n ; i++)
	    b[i][0] = 1 & a[i][n-1];
}


int countNumber(int *mat,int begX, int begY,int x,int y)
{
	
	if(x == begX && y ==begY)
	  return 1;
	
	return  countNumber(mat, begX+1,begY,x,y) + countNumber(mat, begX,begY+1,x,y);
}