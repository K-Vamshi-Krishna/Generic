//implement push pop and min in order of 1
#include<stdio.h>
#include<stdlib.h>
struct node;
typedef struct node *stack;
struct node
{
	int val;
	stack next;
};

stack createRoot()
{
	stack temp;
	temp=(stack)malloc(sizeof(struct node));
	temp->next=NULL;
	return temp;
}

void push(stack base, int val)
{
	stack temp;
	temp=(stack)malloc(sizeof(struct node));
	temp->val=val;
	temp->next=base->next;
	base->next=temp;
}

void pop(stack base)
{ 
	stack temp;
	temp=base->next;
	base->next=temp->next;
	free(temp);
}

 void pushMin(int val,stack base, stack minStack)
 {
	push(base,val);
	if(minStack->next==NULL)
	 push(minStack,val);
	if(val<minStack->next->val)
       push(minStack,val);
     else
       push(minStack,minStack->next->val);	 
 }

int main()
{
	/* 10..4..7 basement
          4  4 10 */	
	stack base,minStack;
	stack temp;
	base=createRoot();
	minStack=createRoot();
	pushMin(10,base,minStack);
    pushMin(4,base,minStack);
	pushMin(7,base,minStack);
	pushMin(3,base,minStack);
	for(temp=minStack->next;temp->next!=NULL;temp=temp->next)
	 printf("%d\n",temp->val);
	//popMin(base,minStack);
	
}