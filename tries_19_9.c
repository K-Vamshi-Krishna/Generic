#include<stdio.h>
#include<stdlib.h>
// implemented the trie data structure .. can be used for spell checker or search words
// implementation is working correctly with the examples
struct tries
{
 struct tries *edges[26];
};

typedef struct tries * Trie;
Trie initializeTrie(Trie temp)
{
 int i;
 temp = (Trie)malloc(sizeof(struct tries));
 for ( i =0 ; i < 26; i++)
   temp ->edges[i]=NULL;
 return temp;
}
Trie addwords(Trie Root ,char *words)
{
   int t;
	if(words[0]=='\0')
	{
	}
	else
	{
	  t = words[0]-'a';
	  if(Root->edges[t]==NULL)
	        Root->edges[t] =initializeTrie(Root->edges[t]);
	  else	 
	   Root->edges[t] =addwords(Root->edges[t],++words);        	  
	}
	return Root;
}

int  searchWords(Trie Root, char* words)
{ int t;
   if(words[0]=='\0')
   return 1;
   else
   {
	t = words[0]-'a';
	if(Root->edges[t]==NULL)
	 return 0;
	else
	return searchWords(Root->edges[t],++words) ;
   }
}

int main()
{
  Trie Root;
  Root =initializeTrie(Root);
  Root= addwords(Root ,"sairam");
  Root =addwords(Root,"surfeit");
  Root =addwords(Root,"hello");
  if(!searchWords(Root,"sairam"))
    printf("does not exist\n");
  else
    printf("it does\n");  
return 0;
}