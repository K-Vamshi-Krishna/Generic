/*

Merge 2 sorted linked lists.

Compare each of the nodes and which ever is greater and not null push it forward
assume that each of the 

*/




#include<iostream>

#include<cstdlib>
#include<cstdio>


struct node
{
	int val;
	struct node * next;
};
typedef struct node* list;


list merge( list head1, list head2)
{
	list temp1,temp2,temp3=NULL,head3;
	if(head1==NULL && head2==NULL)
	 return NULL;
	if(head1==NULL)
	 return head2;
	if(head2==NULL)
        return head1;	
 	//invariance is tell one of the values is null
	//if(head1->val < head2->val)
	 // head3=head1;
//	else
  //     head3=head2;	
	
	for(temp1=head1, temp2=head2; temp1!=NULL && temp2!=NULL ;)
	  {
		  
		  if(temp1->val <= temp2->val)
		    {
			
			 if(temp3==NULL)
			   {
			     temp3=temp1;
				 head3=head1;
			    }
			 else  
				{
				 temp3->next=temp1;
				 temp3=temp3->next;
				 }
			 temp1=temp1->next;
			  printf("%d  %d \n",temp3->val,temp2->val);
			}
		  else
		    {
			 printf("--%d  %d \n",temp1->val,temp2->val);
				if(temp3==NULL)
				 {
				   temp3=temp2;
				   head3=head2;
				  } 
				else
				  {
				   temp3->next=temp2;
				   temp3=temp3->next;
				   }
				temp2=temp2->next;
			}
	  }
	
	 if(temp2==NULL)
	  temp3->next=temp1;
	 else
	   temp3->next=temp2;
	  for(temp3=head3; temp3!=NULL;temp3=temp3->next)
            printf("%d ---",temp3->val);	  
	return head3;
}

list createNode(list end,int val)
{
  list temp;
  temp=(list)malloc(sizeof(struct node));
  temp->val=val;
  temp->next=NULL;
	if(end!=NULL)
	  {
	   end->next=temp;
	   }
	  return temp;
}

int main()
{
	list head1, head2,end1,end2,head3;
	head1=createNode(NULL,3);
	head2=createNode(NULL,4);
	end1=head1;
	end2=head2;
	end1=createNode(end1,5);
	end2=createNode(end2,6);
	end1=createNode(end1,7);
	end2=createNode(end2,9);
	
	head3=merge(head1,head2);
	for(list temp =head3; temp!=NULL;temp=temp->next)
	{
	 printf("%d-->",temp->val);
	}
}
