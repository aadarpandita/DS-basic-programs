#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Island
{
	public:
		
	
	void dfs(vector<vector<char> > &grid, vector<vector<int> > &visited, int i, int j, int row, int col)
	{
		if(i<0 || j<0 || i>=row || j>=col)
			return;

		if(visited[i][j]==1 || grid[i][j]=='0')
			return;

		visited[i][j]=1;

		dfs(grid,visited, i-1, j, row,col);
		dfs(grid,visited, i+1, j, row,col);
		dfs(grid,visited, i, j-1, row,col);
		dfs(grid,visited, i, j+1, row,col);

		// dfs(grid,visited, i-1, j-1, row,col);
		// dfs(grid,visited, i+1, j+1, row,col);
		// dfs(grid,visited, i+1, j-1, row,col);
		// dfs(grid,visited, i-1, j+1, row,col);
	}

	int num_Island(vector<vector<char>> &grid)
	{
		int row = grid.size();

		int col = grid[0].size();

		if(row == 0)
			return 0;

		if(col == 0)
			return 0;

		vector<vector<int>> visited(row, vector<int>(col));

		int count = 0;

		int i = 0;
		int j = 0;

		for(i = 0; i < row; i++)
		{
			for(j = 0; j < col; j++)
			{
				if((visited[i][j]==0) && (grid[i][j]=='1'))
				{
					count++;
					dfs(grid,visited,i,j,row,col);
				}
			}
		}	
		return count;
	}
};

//  void DFS(vector<vector<char>>& grid, int i, int j)
//  {
// 	    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
// 	    if('0' == grid[i][j]) return;
// 	    grid[i][j] = '0';
// 	    DFS(grid, i-1, j);
// 	    DFS(grid, i+1, j);
// 	    DFS(grid, i, j - 1);
// 	    DFS(grid, i, j + 1);
// }

// int numIslands(vector<vector<char>>& grid)
// {
// 		int counter = 0;
// 		for (int i = 0; i < grid.size(); ++i)
// 			for (int j = 0; j < grid[i].size(); ++j)
// 				if ('1' == grid[i][j])
// 				{
// 					++counter;
// 					DFS(grid, i, j);
// 				}
// 		return counter;
// }


int main()
{
	vector<vector<char> > grid{ { '1', '0', '1', '0' }, 
                                { '0', '1', '0', '1' }, 
                                { '1', '0', '1', '0' },
                                { '1', '0', '1', '1' } };

    Island obj;
   	int count = obj.num_Island(grid);
	cout<<count<<endl;

	return 0;
}