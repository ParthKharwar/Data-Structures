#include <stdio.h>
int adj[10][10] = {0}, visited[10] = {0}, n;

void dfs(int node)
{
	int i;
	visited[node] = 1;
	printf("%d ", node + 1);
	for(i = 0; i < n; i++)
		if(adj[node][i] == 1 && visited[i] == 0)
			dfs(i);
}

void bfs(int node)
{
	int q[10], f = -1, r = -1, i, nd;
	visited[node] = 1;
	q[++r] = node;
	while(f != r)
	{
		nd = q[++f];
		printf("%d ", nd + 1);
		for(i = 0; i < n; i++)
			if(adj[nd][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				q[++r] = i;
			}
	}
}

void main()
{
	int e, v1, v2, i, node, ch;
	printf("Enter No. of Nodes: ");
	scanf("%d",&n);
	printf("Enter No. of Edges: ");
	scanf("%d", &e);
	printf("Enter Edges:\n");
	for(i = 0; i < e; i++)
	{
		scanf("%d %d", &v1, &v2);
		adj[v1 - 1][v2 - 1] = adj[v2 - 1][v1 - 1] = 1;
	}
	printf("1. DFS    2. BFS\n");
	printf("Enter Choice: ");
	scanf("%d", &ch);
	printf("Enter Starting Node: ");
	scanf("%d",&node);
	if(ch == 1)
		dfs(node - 1);
	else if(ch == 2)
		bfs(node - 1);
}
