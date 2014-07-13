#include<stdio.h>
#include<stdlib.h>
struct node
{
 int val;
 struct node * next;
 struct node * random;
};
typedef struct node Node;
Node* createNode(int data)
{
  Node* temp;
  
  temp =(struct node*)malloc(sizeof(Node));
  temp->next = NULL;
  temp->random = NULL;
  return temp;
}
void copy(struct node * head, struct node *newhead)
{
	Node *temp,*temp2;
	
	for ( temp = head ;temp !=NULL ; temp = temp ->next,temp2->next=temp)
	{
	  temp2 =createNode(temp->data);
      temp ->next=temp2;	
	}
   
     newhead = head ->next;

    for( temp =head,temp2 = head->next; temp !=NULL ; temp = temp->next->next)
    {
	  temp2->random = temp->random->next;
      if(temp2->next!=NULL)
	     temp2=temp2->next->next;
	}
   for(temp = newhead->next,temp2= newhead; temp !=NULL; ) 	
	{
		temp2->next= temp->next;
		if(temp->next !=NULL)
		 temp=temp->next->next;
		if(temp2->next !=NULL)
           temp2=temp2->next->next;		
	}	   
	temp->next=NULL;
}


int main()
{
  struct node *head;
  struct node *newhead;
    createNode(head);
	createNode(newhead
  insert(head
  copy(head,newhead);
}