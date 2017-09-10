#include<stdio.h>
typedef struct listNode ln;
typedef struct list l;
typedef struct graph g;
struct listNode
{
	int dest;
	int wt;
	ln *next;
}*tmpln;
struct list
{
	ln *head;
}*tmpl;
struct graph
{
	int V;
	l *array;
}*tmpg;
ln* make(int dest,int wt)
{
	tmpln=(ln*)malloc(sizeof(ln));
	tmpln->dest=dest;
	tmpln->wt=wt;
	tmpln->next=NULL;
	return tmpln;
}
g *createGraph(int V)
{
	tmpg=(g*)malloc(sizeof(g));
	tmpg->V=V;
	tmpg->array=(l*)malloc(V*sizeof(l));
	int i;
	for(i=0;i<V;i++)
	{
		tmpg->array[i].head=NULL;
	}
	return tmpg;
}
void addEdge(g* graph,int src,int des,int wt)
{
	ln *newNode=make(des,wt);
	newNode->next=graph->array[src].head;
	graph->array[src].head=newNode;
	
	newNode=make(src,wt);
	newNode->next=graph->array[des].head;
	graph->array[des].head=newNode;
}
void printGraph(g* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        ln* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
int main()
{
    // create the graph given in above fugure
    int V = 5;
    g* graph = createGraph(V);
    addEdge(graph, 0, 1,1);
    addEdge(graph, 0, 4,1);
    addEdge(graph, 1, 2,1);
    addEdge(graph, 1, 3,1);
    addEdge(graph, 1, 4,1);
    addEdge(graph, 2, 3,1);
    addEdge(graph, 3, 4,1);
 
    // print the adjacency list representation of the above graph
    printGraph(graph);
 
    return 0;
}