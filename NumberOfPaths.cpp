#include<cstdio>
#include<cstdlib>

struct AdjListNode
{
	int parent;
	int color;
	int weight;
	int dest;
	struct AdjListNode * next;
};
struct AdjList
{
	struct AdjListNode *head;
	int visited;
};

struct Graph
{
	int V;
	struct AdjList* array;
};

struct Graph* createGraph(int V)
{
	int i;
	struct Graph* graph;
	graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;
	graph->array=(struct AdjList*)malloc(V*sizeof(struct AdjList)); 
	for( i =0 ; i<V ;i++)
	{
		graph->array[i].head=NULL;
		graph->array[i].visited=0;
	}
	return graph;
}

struct AdjListNode* newAdjListNode(int dest,int weight)
{
	struct AdjListNode* temp;
	temp=(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	temp->dest=dest;
	temp->weight=weight;
	temp->next=NULL;
	return temp;
	
}

void addEdge(struct Graph* graph,int src,int dest, int weight)
{
	struct AdjListNode* newNode =newAdjListNode(dest,weight);
	newNode->next=graph->array[src].head;
	graph->array[src].head= newNode;
	
	newNode =newAdjListNode(src,weight);
	newNode->next =graph->array[dest].head;
	graph->array[dest].head=newNode;
	
}


int dfs(struct Graph* g, int src,int dest)
{
    struct AdjListNode* ind;
	int count=0;
	g->array[src].visited=1;	
 	if(src==dest)
	  return 1;
	for( ind = g->array[src].head; ind!=NULL; ind=ind->next )
	{ 
	   if(g->array[ind->dest].visited==0)
       {
      	   count+=dfs(g,ind->dest,dest);	 
		   g->array[ind->dest].visited=0; 
	   }
	}
			 
	return count;		 
}


int main()
{
 
 struct Graph* graph =createGraph(6);
	addEdge(graph,0,1,4);
	addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 5, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    
    
    
    printf("----%d\n",dfs(graph,0,5));
return 0;
}