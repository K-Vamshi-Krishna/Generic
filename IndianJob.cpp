#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//#define max(a,b) if(a >b) return a 

bool knapsack(unsigned G, unsigned *A,unsigned n)
{
	int i;
	unsigned w;
	unsigned K[n+1][G+1];
	vector<unsigned> validSet,invalidSet;
	for ( i=0; i<=n;i++)
	{
		for (w =0 ; w<=G; w++)
		{
			if( i==0 || w==0)
			 K[i][w]=0;
			else if( A[i-1] <= w)	
				K[i][w] = max( 1 + K[i-1][w-A[i-1]],K[i-1][w]);
			else
				K[i][w]=K[i-1][w];
			//cout<<"i "<<i<<" "<<w<<" K[i][w] " <<K[i][w]<<endl;
		}
	}
	w--;
	//cout<<n<<" "<<w<<" "<<K[n][w]<<endl;
	for( i=n; i>=1 &&w>=0; i--)
	{
		if(K[i][w] !=K[i-1][w])
		{
			validSet.push_back(A[i-1]);
			w=w-A[i-1];
		}
		else
		 invalidSet.push_back(A[i-1]);
	}
	for ( int i=0 ; i<validSet.size();i++)
	cout<<"\t"<<validSet[i];
	cout<<endl;
	unsigned invalidSum=0;
	for( int i=0 ; i< invalidSet.size();i++)
	 {
	 invalidSum +=invalidSet[i];
	 }
	if( invalidSum <=G)
		return true;
	else
		return false;
	//return K[n][w];
}

/*void subsets( unsigned *sum, unsigned long *A,int depth, unsigned long G)
{
	if(*sum ==G)
		*combination =true;
	if( depth >=N)
		return;
	else
	{
		for (int j=depth, j<N;j++)
		
	}
}
*/
bool summation(unsigned *A,unsigned N, unsigned G)
{
	vector<unsigned> vectorA (A,A+N);
	vector<unsigned>::iterator it;
	sort(vectorA.begin(),vectorA.end());
	unsigned sum=0;
	for(it=vectorA.begin();it!=vectorA.end();it++)
	{
		if(sum>=G)
			break;
		sum += *it;
				
	}
	unsigned sum1=0;
	for( ;it!=vectorA.end();it++)
	{
		sum1 +=*it;
	}
	if(sum1 <G)
	return true;
	else
	return false;
}
/*
bool summation(unsigned* A, unsigned N, unsigned G)
{
	unsigned sum=0;
	for (int i=0; i<N;i++)
	 sum+=A[i];
	if(sum > (2*G))
		return false;
	for( int i=0 ; i<N; i++)
		{
			sum =A[i]
			subsets(&sum,A,i+1,G);
		}

}*/
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	unsigned T;
	unsigned N;
	unsigned A[100];
	bool Output[20];
	unsigned G;
	cin >>T;
	for ( int i=0 ; i<T ;i++)
	{
		cin >>N;
		cin >>G;
		for (int m=0 ; m<N; m++)
			cin >> A[m];
			//cout<<knapsack(G,A,N);
		//if(summation(A,N,G))
		if(knapsack(G,A,N))
			Output[i]=true;
		else
			Output[i]=false;
	}
	for( int i=0 ; i< T; i++)
		if(Output[i])
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
    return 0;
}
