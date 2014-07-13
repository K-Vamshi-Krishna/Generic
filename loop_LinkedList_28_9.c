#include<stdio.h>
#include<stdlib.h>
struct node;
typedef struct node * List;
struct node
{
	int val;
	List next;
};

void insert(List start,int val)
{
  	List temp;
	if(start==NULL)
	 {
	  start =(List)malloc(sizeof(struct node));
	  start->val=val;
      start->next=NULL;	  
	 }
	
	for(temp=start;temp->next!=NULL;temp=temp->next);
	temp->next=(List)malloc(sizeof(struct node));
    temp->next->next=NULL;
}

int detectLoop(List start)
{
	List slow,fast;
	slow =start->next;
	fast =start->next->next;
	while( slow && fast && fast->next)
	{
		slow =slow->next;
		fast =fast->next->next;
		if(slow ==fast)
		return 1;
	}
	return 0;
	
}
int main()
{
	List start;
	insert(start,5);
	insert(start,4);
	for( 
	printf("%d\n",detectLoop(start));
	
}

