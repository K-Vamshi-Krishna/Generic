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

Tree createNode(int val)
{
	Tree temp;
	temp=(Tree)malloc(sizeof(struct node));
	if(temp==NULL)
	return NULL;
	temp->value=val;
    temp->left=NULL;
    temp->right=NULL; 
	return temp;	
}
Tree mirrorBinaryTree(Tree root)
{
	 Tree temp;
	if(root ==NULL)
	return NULL;
	else
	{
	 temp=mirrorBinaryTree(root->left);
	 root->left=mirrorBinaryTree(root->right);
	 root->right=temp;
	 return root;
	}
}
void inOrder(Tree root)
{
	if(root ==NULL)
	return ;
	else
	{
		inOrder(root->left);
		printf("%d\t",root->value);
		inOrder(root->right);
	}
}

int main()
{
	Tree root,temp,temp1,temp2,temp3;
	root = createNode(5);
	root->left=createNode(3);
	root->right=createNode(7);
	temp=root->left;
	temp1=root->right;
	temp->left=createNode(2);
	temp->right=createNode(4);
	temp1->right=createNode(8);
	inOrder(root);
	printf("\n");
	root=mirrorBinaryTree(root);
	inOrder(root);
}