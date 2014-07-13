/*Given a list of coins with various values (unlimited coins). Find how many ways 
you can make a given value. Have to return -1 if it is not possible
Proof: Let X ={xi} be the set of numbers available with us.

By describing it as tree structure, Let K the value to be got be at the root

								K
							K- xi	
							
Count(K) = Sum(for all x belongs X)(Count(K-x))
            
			
			Count = { 1 { x belongs to Xi}
			          for all other values it is -1
					  -1  if any of the value returned is -1
					  sum(for a
						ll x belong to Xi(Count(K-xi)) +1
			         }
					 
Strong Induction should be converted to some kind of ordering problem
1. create a table of m * n +1 where m is the number of values and n is the value requested for.
2. we perform a ordering from the smallest variable to largest variable. So For each value the ordering is from the smallest value to largest value
3. Initialize all the base value for n==0 to 1
					 */
					 
#include<iostream>
#include<vector>
#include<cmath>
//Coin Change Problem
using namespace std;
#define INT_MAX 1000000
int count(int s[], int m, int n)
{
	if (n==0)
	return 1;
	if (n<0)
	 return 0;
	if( m<=0 && n>=1)
	  return 0;
	return count(s,m-1,n)+count(s,m,n-s[m-1]);  
}


int dynamicCount( int s[],int m, int n)
{
	int i,j,x,y;
int table[n+1][m];
for (j =0 ; j<m ; j++)
{
	table[0][j]=1;
}	
for ( i =1 ; i< n+1 ; i++)
	for ( j=0; j<m ; j++)
		{
			x= (i - s[j]<0)?0:table[i-s[j]][j]; // all the possible values with the lowest m value
			
			y = (j >=1)?table[i][j-1]:0;
			table[i][j]= x+y;
		}
	for (i =0 ; i<=n ; i++)
	{
		for ( j =0 ; j<m;j++)
			std::cout<<table[i][j]<<"\t";
		std::cout<<std::endl;
	}		
	return table[n][m-1];
}


void makingCount(int coins[], int amt, int n )
{
	
	//int amount[amt 1] ={0};
	int * amount;
	amount = new int[amt +1];
	for ( int i=1 ; i<=amt ; i++)
	{
		amount[i] =INT_MAX;
		int temp = INT_MAX;
		for (int  j=0 ; j< n ; j++)
		 {
				if( coins[j] <= amt)
				{
					int temp_amt = amount[i-coins[j]] +1;
				
					if( temp_amt < temp)
					{
						temp = temp_amt;
						amount[i] =temp;
					}
				
				}	
				
		 }
	}
	
	
		cout<< " "<< amount[amt]<<endl;
}





int main()
{
	int i,j;
	int arr[] ={1,2,3};
	int m =sizeof(arr)/sizeof(arr[0]);
	makingCount(arr,4,m);
	//std::cout<<dynamicCount(arr,m,4)<<"\t"<<count(arr,m,4)<<std::endl;
}

