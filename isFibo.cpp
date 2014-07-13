#include<iostream>
#include<vector>
std::vector<unsigned long long> Fibonacci;
#define M 10000000000
using namespace std;
void initialize()
{
	unsigned long long fib1 =0, fib2 =1,temp;
	unsigned i =0 ;
	Fibonacci.push_back(fib1);
	Fibonacci.push_back(fib2);
	 while(fib1 <=M )
	{
		temp = fib1 + fib2;
		fib1 =fib2;
		fib2 = temp;
		Fibonacci.push_back(fib1);
	}
}

bool isFibo(unsigned long long N)
{
  unsigned i ;
  for ( i=0 ; i< Fibonacci.size(); i++)
  {
	if (Fibonacci[i]==N)
	 return true;
  }
  return false;
  
}
int main()
{
	unsigned long long T,m;
	unsigned i;
	vector<unsigned long long> tCases;
	initialize();
	cin >>T;
	for( i=0 ; i<T; i++)
		{
		cin >>m;
		tCases.push_back(m);
		//cout << tCases[i]<<endl;
		}
	for (i =0 ; i<tCases.size() ; i++)
	{
	  m =tCases[i];
	if(isFibo(m))
	cout<<"isFibo\n";
	else
	cout<<"isNotFibo\n";
	}
	
}
