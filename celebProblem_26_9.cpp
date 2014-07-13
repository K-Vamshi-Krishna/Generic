//find the mayor in the party
// 2d array of bool which indicate i,j = i knows j
#include<cstdio>
#include<list>
#define N 4
bool mat[N][N]={{0,0,1,0},{0,0,1,0},{1,0,0,0},{0,0,1,0}};
using namespace std;

int celebrity()
{
	list<int> stack;
	list<int>::iterator it,jt;
    int i,j;	
	for(i=0 ; i< N ; i++)
	stack.push_back(i);
	
	   
		while( stack.size()>1)
		{
		   it=stack.begin();
  		//printf("stack size= %d\n",stack.size());
		 for( jt=stack.begin();jt!=stack.end();jt++)
		  if(mat[*it][*jt])
		   {
       		   //printf("%d\n",*jt);
			   stack.remove(*it);
			   break;
			} 
            if(jt==stack.end())
             break; 			
		 }
	i =*stack.begin();
	printf("%d\n",i);
	for(j=0;j<N;j++)
	{
		if(mat[i][j])
		break;
	}
	if(j!=N)
	return -1;
	else
	 return i;
}
int main()
{
printf("%d\n",celebrity());
}
