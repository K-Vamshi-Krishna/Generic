// diameter in a tree
#include<stdio.h>
#include<stdlib.h>

//#define max(a,b) (a>=b)? a: b;
typedef struct node * Tree;
struct node
{
	int data;
	Tree left;
	Tree right;
};

Tree createNode( int data)
{
	Tree temp;
	temp =(Tree)malloc(sizeof(struct node));
	
	temp->left=NULL;
	temp->right=NULL;
	temp->data=data;
	return temp;
}
int max(int a, int b)
{
	if(a>=b)
	return a;
	else
	return b;
}

int height(Tree root)
{
	if(root ==NULL)
	return 0;
	else
	{
	printf("~~~~ %d\n",(1+ max(height(root->left),height(root->right))));
	return 1+ max(height(root->left),height(root->right));
    }
}

int diameterOpt(Tree root, int* h)
{
  
	
}


int diameter(Tree root)
{
	int ldiam,rdiam,rhit,lhit,k;
	if(root ==NULL)
	return 0;
		
	 ldiam = diameter(root->left);
	 rdiam =diameter(root->right);
	
	 rhit = height(root->right);
	 lhit = height(root->left);
	 
	 printf("-- %d %d %d %d data  %d\n",ldiam,rdiam,lhit,rhit,root->data);
	 k =max(rdiam,ldiam);
	
	return max(k,(rhit+lhit+1));
}

int main()
{
  /* 
       1 
	  / \
	 2	 3
    / \
   4   5
  
  */
  
 Tree root =createNode(1);
 root->left = createNode(2);
 root->right = createNode(3);
 root->left->right = createNode(5);
 root->left->left = createNode(4);
  
	printf("Diameter of the tree  %d\n",diameter(root));
}