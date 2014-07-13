/*
Given a rod with length , cut the rod into as many peices so that the revenue is maximun
Let pi be the price and rn be the max revenu rn for length n.

Proof: A rod of lenght n can have n-1 possible cut positions 0<=k<=n-1. We 
can chosse k cuts so that for each such k the number of choies is P(n-1,k).

Cut the rod of length n into 0<-k+n picies of length i1,i1,...ik
with revenu
rn = pi1
rn = max(pn,r1+rn-1,r2+rn-2,....)
rn = max[1<=i<=n](pi+rn-i)


cut-rod (p,n)
if(n==0)
  return 0
  q=-infinity
  for i=1 to n
     q = max(q,p[i]+cut-rod(p,n-i))
  
return q
*/


#include<cstdio>
#include<cstdlib>
#define INT_MIN -10000
int max(int a , int b) { return (a>b)?a:b;}

int cutRodAux(int *p, int n)
{
  int *r,i,j,q;
  r =(int *)malloc(sizeof(int)*(n+1));
  r[0]=0;
  for ( j=1 ; j<= n ;j ++)
   {
	 q =INT_MIN;
	 for( i=0; i<j; i++)
	  q= max(q,p[i]+r[j-i-1]);
	 r[j]=q;
  }
  return r[n];
}
int cutRod( int *p , int  n)
{
	int q,i;
	if (n<=0)
	return 0;
	q= INT_MIN;
	for( i=0 ; i< n ; i++ )
	 {
	    //printf(".. %d\n",p[i]);
		q = max(q,p[i]+cutRod(p,n-i-1));
		//printf("--%d\n",q);
	 }
	return q; 
}


int main()
{

	int arr[]={1,5,8,9,10,17,17,20};
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("size %d\n",size);
	printf(" Max Value Otain %d\n",cutRodAux(arr,size));
	return 0;
}