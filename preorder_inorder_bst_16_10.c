/*
 Input- Given an array of preorder values
 Output - Construct a BST


*/

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



Tree construct(int *preOrder, int *inOrder, int end1,int end2)
{
	
	int pos,i;
	Tree root;
	if(end1<=1)
	{
	 root=(Tree)malloc(sizeof(struct node));
	 root->value=preOrder[0];
	 root->left=NULL;
	 root->right=NULL;
	printf("....%d\n",preOrder[0]);
	}
	else
	{
	for(i=0; i<end2; i++)
	{
		if(inOrder[i]==preOrder[0])
		break;
	}
	root=(Tree)malloc(sizeof(struct node)); 
	root->value=preOrder[0];
	printf("%d\n",preOrder[0]);
	root->left=construct(preOrder+1,inOrder,i-1,i-1);
	root->right=construct(preOrder+i+1,inOrder+i+1,end1-i-1,end2-i-1);
	}
	return root;
}
void qsort(int *postOrder, int beg, int end)
{
	int ran,mid;
	mid=(beg+end)/2;
	ran=postOrder[mid];
	
	

}

void sort(int* postOrder, int n)
{
   qsort(postOrder,0,n);
}


int main()
{
	Tree root;
	int preOrder[7]={10,7,4,8,15,12,18};
	 int n=7;
	int postOrder[7]={4,7,8,10,12,15,18}; 
	
	//sort(postOrder,n);
	root=construct(preOrder,postOrder,7,7);
	return 0;
}