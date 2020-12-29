#include<iostream>
#include<climits>
#include<vector>

using namespace std;

#define size 9

int min_dist(int dist[],bool visited[])
{
	int min = INT_MAX;
	int min_index;

	for(int i=0; i<size; i++)
	{
		if(dist[i]<=min && visited[i]==false)
			{
				min=dist[i];
				min_index=i;
			}
	}
	return min_index;
}

void print(int dist[])
{
	for(int i=0;i<size;i++)
		cout<<i<<'\t'<<dist[i]<<endl;
}

void dijkstra(int graph[size][size] ,int src)
{
	int dist[size];
	bool visited[size];


	for(int i=0; i<size; i++)
	{
		visited[i]=false;

		dist[i]=INT_MAX;
	}
	dist[src]=0;

	for(int j=0; j<size; j++)
	{
		int x = min_dist(dist,visited);
		visited[x]=true;

		for(int k=0; k<size; k++)
		{
			if(graph[x][k] && !visited[k] && dist[x]!=INT_MAX && (dist[x] + graph[x][k] < dist[k]))
			 	dist[k] = dist[x] + graph[x][k];
		}
	}

	print(dist);
}

int main()
{
	int graph[size][size]= {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                        {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                        {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                        {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                        {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                        {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                        {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                        {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                        {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                       }; 
    dijkstra(graph, 0); 

	return 0;
}