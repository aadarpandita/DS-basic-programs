#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Island
{

public:

	bool check(vector<vector<int > > &grid, vector<vector<int > > &visited, int i, int j, int row, int col)
	{
		return(i>=0 && j>=0 && i<row && j<col && visited[i][j]==0 && grid[i][j]=='1');
	}

	void bfs(vector<vector<int > > &grid, vector<vector<int > > &visited, int i, int j, int row, int col)
	{
		queue<int > q;
		q.push(i);
		q.push(j);

		visited[i][j]=1;

		while(!q.empty())
		{	
			int i = q.front();
			q.pop();
			int j = q.front();
			q.pop();
			if(check(grid,visited, i-1, j, row,col))
			{
				q.push(i-1);
				q.push(j);
				visited[i-1][j]=1;
			}
			if(check(grid,visited, i+1, j, row,col))
			{
				q.push(i+1);
				q.push(j);
				visited[i+1][j]=1;
			}

			if(check(grid,visited, i, j-1, row,col))
			{
				q.push(i);
				q.push(j-1);
				visited[i][j-1]=1;
			}
			if(check(grid,visited, i, j+1, row,col))
			{
				q.push(i);
				q.push(j+1);
				visited[i][j+1]=1;
			}
		}
	}

	int num_Islands(vector<vector<int > > &grid)
	{
		int row=grid.size();
		int col=grid[0].size();

		if(row==0)
			return 0;
		if(col==0)
			return 0;

		int count=0;
		int i=0;
		int j=0;

		vector<vector<int > > visited(row,vector<int>(col,0));

		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				if(visited[i][j]==0 && grid[i][j]=='1')
				{
					bfs(grid,visited,i,j,row,col);
					count++;
				}
			}
		}
		return count;
	}

};

int main()
{
	Island obj;

	vector<vector<int > > grid { { '1', '0', '1', '0' }, 
                                 { '0', '1', '0', '1' }, 
                                 { '1', '0', '1', '0' },
                                 { '1', '0', '0', '1' }  };
 
	int count=obj.num_Islands(grid);
	cout<<count<<endl;

	return 0;
}