#include<iostream>
#include<cstdio>
#define N 5
bool findPattern(char a[][N],char* pattern)
{
	char m;
	bool isThere[26];
	int i,j;
	for( i=0; i<25; i++)
	  isThere[i]=false;
	for( i=0; i< N ; i++)
	for( j=0; j< N ;j++)
	{
		m=a[i][j];
		isThere[m-'a']=true;
	}
	
	for( i=0 ; pattern[i]!='\0'; i++)
	 {
	    m=pattern[i];
	   if( !isThere[m-'a'])
	    return false;
      }
   return true;	  
}


int main()
{
	char a[][N] ={{'a','b','c','r','d'},
                 {'e','f','o','g','h'},
                 {'i','o','j','k','i'},
                 {'w','g','f','m','n'},
                 {'z','a','s','i','t'}};				 
	
char pattern[]="micrzsyft";	
	
if(findPattern(a,pattern))	
 printf("Found Pattern\n");
 else
  printf("No Pattern\n");
 
 return 0;

 }