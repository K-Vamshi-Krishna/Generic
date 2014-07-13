#include<stdio.h>
//find the number which rempeats more than n/2 times
int main()
{
 int array[20]; 
 int N;
 int i;
 scanf("%d",&N);
 for(  i=0 ; i < N ; i++)
  scanf("%d",(array+i));
 int k,freq=1;
 k=array[0];
 for ( i=1 ; i< N -1; i++)
  {
   if(k==array[i])
   freq++;
   else
   {
    //printf("%d\t",array[i]);    
    freq--;
    i++;
    k=array[i];
	freq=1;
	}
   }
   if(freq>0)
   printf("%d\n",k);
   else
   printf("No Number");
   
 
}