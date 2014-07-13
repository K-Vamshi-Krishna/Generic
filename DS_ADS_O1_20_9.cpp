//design a ds to store n ot tem, insert if it does not exist , remove the 1st one.
#include<map>
#include<cstdio>
#include<deque>
#include<iostream>
using namespace std;
class streamN
{
  deque<int> myqueue;
  map<int,bool> mypresent;
  int N;
  int count;
  public:
    streamN(int val):N(val),count(0){}
    bool search(int k)
	{
	  return  mypresent.find(k)->second; 
	}
	void insert(int k)
	{
	 int m;
	 std::map<int,bool>::iterator it;
	 if(count < N)
      {
	   if(!(mypresent.find(k)->second))
	     {
		   myqueue.push_back(k);
	       mypresent.insert(std::pair<int,bool>(k,true)); 
	       count++;
		   }
	  }
	  else
	   {
		it=mypresent.find(k);
	    if(it ==mypresent.end())//it is the first time
         {
		  cout<<"insert "<<k<<endl;
		  mypresent.insert(std::pair<int,bool>(k,true));
		  myqueue.push_back(k);
		  m=myqueue.front();
		  myqueue.pop_front();
		  //mypresent.erase(m); 
         }
        else
         {
			/*if(!(mypresent.find(k)->second))
			{
			  mypresent.find(k)->second = true;
              myqueue.push_back(k);
              m=myqueue.access_front();
			  myqueue.pop_front();			                			  
            } */ 			
         }
         cout<<myqueue.size()<<endl;;		 
	   }
	}
	void print()
	{
	 unsigned it;
	 for ( it=0;it<myqueue.size();it++)
	  cout<<myqueue.at(it)<<"\t";
	}
}; 


int main()
{
	streamN stream(4);
	stream.insert(3);
	stream.insert(2);
	stream.insert(2);
	stream.insert(5);
	stream.print();
	if(stream.search(3))
	{
	 cout<<"present"<<endl;
	}
	stream.insert(7);
	stream.insert(9);
	stream.print();
}