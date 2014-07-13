//Given a number k, find the smallest Fibonacci number f that shares a common factor d( other than 1 ) with it. A number is said to be a common factor of two numbers if it exactly divides both of them. 
//Input: T test cases where each contains integer k in [2,1000000]
//Output: two separate numbers, f and d, where f is the smallest fibonacci number and d is the smallest number other than 1 which divides both k and f.

#include<cstdio>
#include<iostream>

typedef long long int big;

big scf(big a, big b)
{
	big i;
	if(a%2==0 && b%2==0) return 2;
	for( i =3 ; i <= a; i+=2)
	 if( a%i==0 && b %i ==0) return i;
	 
	 return 1;
}

int main()
{
 int T,k,i=0;
 
 
 scanf("%d",&T); // T cases
 while(T-- )
 {
  scanf("%d",&k);
  big f=2,prev=1,temp,d=1;
  while(f<=k)
  {
   d=scf(f,k);
   printf("   %d\n",d);
   if(d>1) break;
   temp=prev;
   prev=f;
   f+=temp;
 }
  printf(" ----  %d\n",d);
 if (d >1)
 std::cout<<d<<" "<<f<<std::endl;
 else
 {
	while (f%k!=0)
	 {temp=prev;
	 prev=f;
	 f+=temp;}
	 printf ("%ld %ld\n", f,k);
 }
 }
return 0;
}