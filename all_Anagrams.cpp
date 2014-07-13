#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;
/*



*/
template<class type>
void swap(type *a , type *b)
{
	char c;
	
	c= *a ;
	*a = *b;
	*b = c;
	
}

void permutation(char * input, int i, int n )
{
	int j;
	
	if(i==n)
	 printf("%s\n",input);
	else
	{
		for( j =i; j <= n ; j++)
		 {
			swap<char>(input+i,input+j);
			permutation(input,i+1,n);
			swap<char>(input+i,input+j);
		 }
	}
	
}


int main()
{
  char input[]= "abc";
  permutation(input,0,2);
  return 0;
}