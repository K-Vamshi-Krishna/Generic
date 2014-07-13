#include<stdio.h>
#include<stdlib.h>

struct node;
typedef struct node * Tree;
struct node
{
 int val;
 Tree left;
 Tree right;
};
 
 Tree createNode(int val)
 {
	Tree temp;
	temp =malloc(sizeof(struct node));
	if(temp==NULL)
	 return NULL;
	 temp->left=NULL;
	 temp->right=NULL;
	 temp->val=val;
    return temp;	 
 }
 
  void dfs(Tree root,int value)
 {
	int temp;
	if(root->left==NULL &&root->right==NULL)
     {
	 printf("%d\n",value+root->val);	
	 }
	temp=root->val+value;
	//printf("%d\n",temp);
    if(root->left)
	 dfs(root->left,temp); 
	if(root->right)
     dfs(root->right,temp);	
 }   	
	 
	Tree dfsUtil(Tree root, int k , int *sum)
	{
		Tree temp;
		 int lsum,rsum;
		 if( root ==NULL) return NULL;
		 lsum = *sum+root->value;
		 rsum=lsum;
		
         if(root->left!=NULL)
           root->left=dfsUtil(root->left,k,&lsum);
         if(root->right!=NULL)
            root->right=dfsUtil(root->right,k,&rsum);
        if(*sum<k)
          {
		   free(root);		
		    root=NULL
			}
		   
         return root;
	}
 
 
 int main()
 {
	int K;
	Tree root;
	
	/*
	  10
	 8  2
	3 5 7 4
	*/
	root = createNode(10);
    root->left=createNode(8);
	root->right=createNode(2);
	root->left->left=createNode(3);
	root->left->right=createNode(5);
	root->right->left=createNode(7);
	root->right->right=createNode(4);
	dfs(root,0);
 }