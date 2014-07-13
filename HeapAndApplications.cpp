#include<iostream>
#include<cstdlib>


using namespace std;

void heapify(int *arr, int N)
{
for( i=n/2;i>=0;i--)
 heapifyMax(arr,0,i);
}
void heapifyMax(int *a,int n)
{
  int i;
  int child;
  
  for( i=n/2;i>=0 ; i=child)
  {
    child =i;
	if(a[child] > a[child+1] )
  }
	
}
void insert ( int val,int *arr)
{

}

int main()
{
  int *arr;
  int N;
  
  scanf("%d",&N);
  arr=(int*)malloc(sizeof(int*N));
  for(int i=0; i<N;i++)
  scanf("%d",arr+i);
  
  heapify(arr,N);
  
 
return 0;
}
/*class Heap
{
	int *array;
	int size;
	
	Heap():{
	Arr()}
	minHeapify();
	maxHeapify();
	heapSort();
}
*/