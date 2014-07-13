#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void computeLsArray(char *pat, int m , int *ls)
{
	int i=0,len=0;//length of the previous longest prefix suffix
	ls[i]=0;
	i=1;
	while(i<m)
	{
	  printf("%c %d %d \n",pat[i],i,len);
		if(pat[i]==pat[len])
		 {
			len++;
			ls[i]=len;
			i++;
		 }
		 else
		 {
			if(len!=0)
			 {
				len=ls[len-1];
			 }
			 else
			  {
				ls[i]=0;
				i++;
			  }
		 }
	}
}


void kmpsearch(char *pat,char*text)
{
	int m =strlen(pat);
	int n = strlen(text);
	int *ls;
	//preprocessed array
	ls =(int*)malloc(sizeof(int)*m);
	computeLsArray(pat,m,ls);
	int i=0,j=0;
	while( i < n)
	{
		if(text[i]==pat[j])
		 {
			i++;
			j++;
		 }
		 if(j==m)
		 {
			printf("pattern found %d\n",i-j);
			j=ls[j-1];
		 } 
		 else if(pat[j]!=text[i])
		 {
		    if(j!=0)
				j=ls[j-1];
			else
			 i++;
		 }
	}
	free(ls);
}

int main()
{
  char *pattern="ABABCABAB";
  char *text="ABABDABACDABABCABAB";
  kmpsearch(pattern,text);
}