#include<stdio.h>
#include<stdlib.h>
struct node;
typedef struct node * Tree;

struct node
{
	int value;
	Tree left;
	Tree right;
};


Tree createNode( int val)
{
	Tree temp;
	temp=(Tree)malloc(sizeof(struct node));
	temp->val=value;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}


Tree deleteAllLeafNodes(Tree root)
{
	Tree temp;	
		if(root->left ==NULL && root->right==NULL)
		{
			temp=root;
			free(temp);
			return NULL;
		}
		
	Tree->left=deleteAllLeafNodes(root->left);
    Tree->right=deleteAllNodes(root->right);		
}


int main()
{
	return 0;
}