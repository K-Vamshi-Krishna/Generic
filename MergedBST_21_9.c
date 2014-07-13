//MergeBST.c ....without extra space and  O(nlogn)
#include<stdio.h>
#include<stdlib.h>
// convert the left sub tree to dll and then the root
//convert the right sub tree to dll
typedef struct node * Node;
struct node
{
 Node left;
 Node right;
 int value;
};
typedef Node Tree;
Tree bstTodll(Tree Root)
{
Tree temp;
 if(Root==NULL)
   return NULL;
 if(Root->left!=NULL)
   {
 	temp =bstTodll(Root->left);
    for(; temp ->right !=NULL;temp = temp->right);
	temp->right=Root;
	Root->left=temp;  
   }
   if(Root->right!=NULL)
   {
	 temp = bstTodll(Root->right);
for(;temp->left!=NULL;temp=temp->left)
    temp->left=Root;
    Root->right=temp;	
   }
   return Root;
}   

Tree mergeLinkedList(Tree root, Tree root1)
{
  Tree temp,temp1,temp2,mergedRoot;
  
  if( root ==NULL)
  return root1;
  else if(root1==NULL )
    return root;
  else// both are not null
  {
    if(root->value <root1->value)
  mergedRoot=root;
  else
  mergedRoot=root1;
    if(root->right==NULL && root1->right==NULL)//single elements merge
     {
	   if(root ->value <root1->value)
	    {
			root->right=root1;
			root1->left=root;		
		}
		else
		 {
			root1->right=root;
			root->left=root1;
		 }
	 }
  else 	  
   {
     printf("%d  %d\n",root->value,root1->value);
  for(temp=root,temp1=root1;temp->right!=NULL &&temp1 ->right!=NULL;)
  {
	if(temp->value<temp1->value)
	{
	 while(temp->value<temp1->value &&temp->right!=NULL)
	  temp=temp->right;
	if(temp->right !=NULL)
	{
	  temp->left->right=temp1;
	  temp1->left=temp->left->right;
	}
	else
	 {
	   temp->right=temp1;
	   temp1->left=temp->right;
	   temp=temp->right; 
     }	
	}
	else
	{
		while(temp1->value<temp->value &&temp1->right!=NULL)
		 temp1=temp1->right;
		if(temp1->right!=NULL)
		 {
		  temp1->left->right=temp;
		  temp->left=temp1->left->right;
		  }
		  else
		  {
		   temp1->right=temp;
		   temp->left=temp1->right;
		   temp1=temp1->right;
		  }
	}
  }
  if(temp->right!=NULL &&temp1->right==NULL)
	 {
		for(temp2 =temp; temp2->right!=NULL;)
		 {
		  if(temp2->value<temp1->value)
		   temp2=temp2->right;
		   else
		    break;
		 }
		 if(temp2->value<temp1->value)
		  {
			temp2->right=temp1;
			temp1->left=temp2;
		  }
		  else
		  {
		    temp1->right=temp2;
			temp2->left->right=temp1;
			temp2->left=temp1;
		  }
	 }
	else if( temp1->right !=NULL &&temp->right==NULL) 
	{
	for(temp2 =temp1; temp2->right!=NULL;)
		 {
		  if(temp2->value<temp->value)
		   temp2=temp2->right;
		   else
		    break;
		 }
		 if(temp2->value<temp->value)
		  {
			temp2->right=temp1;
			temp->left=temp2;
		  }
		  else
		  {
		    temp->right=temp2;
			temp2->left->right=temp;
			temp2->left=temp;
		  }

    }
	else
	{ 
	  if(temp->value <temp1->value)
	  {
	   temp->right=temp1;
	   temp1->left=temp;
	  }
	  else
	  {
	   temp1->right=temp;
	   temp->left=temp1;
	  }
	}
	}
  return mergedRoot;
   
  }
}  
  


Tree createNode(int value)
{
 Tree temp;
 temp=(Tree)malloc(sizeof(struct node));
 if(temp ==NULL)
  return  NULL;
 else
  {
   temp->value =value;
   temp->left=NULL;
   temp->right=NULL;
   return temp;
  }  
}
Tree mergeBST(Tree root, Tree root1)
{
}

int main()
{
 Tree root,root1,mergedRoot;
 Tree temp,temp1,temp2,temp3,temp4,temp5;

 root=createNode(1);
 root1=createNode(3);
 temp1=createNode(4);
 temp4=createNode(2);
 temp2=createNode(5);
 temp3=createNode(6);
 root=mergeLinkedList(root,root1);
   
 for( temp = root;temp!=NULL;temp=temp->right)
    printf("%d -> \t",temp->value);
 mergedRoot=mergeLinkedList(root,temp1);
   
 for( temp = mergedRoot;temp!=NULL;temp=temp->right)
    printf("%d -> \t",temp->value);
 //temp4=mergeLinkedList(temp4,temp2);
 //temp4=mergeLinkedList(temp4,temp3);
 mergedRoot=mergeLinkedList(root,temp4);
  
 for( temp = mergedRoot;temp!=NULL;temp=temp->right)
    printf("%d -> \t",temp->value);
 
 
 //root =bstTodll(root);
 //root1=(bstTodll(root1);
 //for (temp=root;temp->left!=NULL;temp->)
}