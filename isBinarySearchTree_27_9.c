#include<stdio.h>
#include<stdlib.h>
typedef struct node * Tree;
struct node
{
 int val;
 Tree left;
 Tree right;  
};
Tree createNode( int val, Tree temp)
{
 temp =(Tree)malloc(sizeof(struct node));
 if(temp ==NULL)
 return NULL;
 
 temp->left=NULL;
 temp->right=NULL;
 temp->val=val;
 return temp;
}
void inOrder(Tree root,int * trial);

int isBST(Tree root, int n)
{
 int i;
 int *trial =(int*)malloc(sizeof(int)*n);
 inOrder(root,trial);
 for ( i =1 ; i< n ; i++)
 {
 if(trial[i -1]<=trial[i])
 printf("%d  %d\n",trial[i],trial[i-1]);
 else
  break;
  }
  if( i < n)
  return -1;
  else
  return 0;


 }

void inOrder(Tree root,int * trial)
{
 static int i =0;
 if(root==NULL)
 return;
 else
 {
 inOrder(root->left,trial);
 trial[i++]=root->val;
 //printf("%d %d\n",trial[i],i);
 inOrder(root->right,trial);
 }
}

int main()
{
	Tree root;
	root=createNode(4,root);
	root->left=createNode(5,root->left);
	root->right=createNode(3,root->right);
	if(isBST(root,3)==-1)
	printf("No\n");
	else
	printf( "yes\n");
}