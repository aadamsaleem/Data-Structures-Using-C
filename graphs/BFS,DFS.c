#include<stdio.h>
#define MAX 20
typedef enum boolean{false,true} bool;
int adj[MAX][MAX];
bool visited[MAX];
int n;

void read()
{
	int i,j,max_edges,origin,destin;
	int am[20][20];
	FILE *f;
	f=fopen("bfsdfd.txt","r+");
	fscanf(f,"%d",&n);
	while(!feof(f))
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				fscanf(f,"%d",&am[i][j]);
	}
	max_edges=n*(n-1);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(am[i][j]==1)
				adj[i+1][j+1]=1;
}
display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d\t",adj[i][j]);
		printf("\n");
	}
}
dfs(int v,int node)
{
	int i,stack[MAX],top=-1,pop_v,j,t;
	int ch;
	top++;
	stack[top]=v;
	while (top>=0)
	{
		pop_v=stack[top];
		top--;
		if( visited[pop_v]==false)
		{
			printf("%d ",pop_v);
			if(pop_v==node)
				return(1);
			visited[pop_v]=true;
		}
		else
			continue;
		for(i=n;i>=1;i--)
		{
			if( adj[pop_v][i]==1 && visited[i]==false)
			{
				top++;
				stack[top]=i;
			}
		}
	}
	return(0);
}
bfs(int v,int node)
{
	int i,front,rear;
	int que[20];
	front=rear= -1;
	visited[v]=true;
	rear++;
	front++;
	que[rear]=v;
	printf("%d",v);
	while(front<=rear)
	{
		v=que[front];
		front++;
		for(i=1;i<=n;i++)
		{
			if( adj[v][i]==1 && visited[i]==false)
			{
				printf("%d ",i);
				if(i==node)
					return(1);
				visited[i]=true;
				rear++;
				que[rear]=i;
			}
		}
	}
	return(0);
}
main()
{
	int i,v,choice,search,node;
	read();
	while(1)
	{
		printf("\n\t\t\t1.Depth First Search\n");
		printf("\t\t\t2.Breadth First Search\n");
		printf("\t\t\t3.Exit\n");
		printf("\t\t\tEnter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1: display();
		printf("\n\tEnter starting node : ");
		scanf("%d",&v);
		printf("\n\tEnter Node to be Searched : ");
		scanf("%d", &node);
		for(i=1;i<=n;i++)
			visited[i]=false;
		search=dfs(v,node);
		if(search==1)
			printf("\nNODE FOUND...\n");
		else
			printf("\nNODE NOT FOUND...\n");
		break;
		case 2: display();
		printf("\n\n\t\tEnter starting node : ");
		scanf("%d", &v);
		printf("\n\n\t\tEnter Node to be Searched : ");
		scanf("%d", &node);
		for(i=1;i<=n;i++)
			visited[i]=false;
		search=bfs(v,node);
		if(search==1)
			printf("\nNODE FOUND...\n");
		else
			printf("\nNODE NOT FOUND...\n");
		break;
		case 3:
			exit(0);
		default:
			printf("\n\tWrong choice\n");
			break;
		}
		getch();
	}
}
