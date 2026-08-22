class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited)
    {
        if(visited[i][j] == true)
            return;
        visited[i][j] = true;
        if(grid[i][j] == '0')
            return;
        // recurse on edges
        if((i - 1) >= 0)
            dfs(i - 1, j, grid, visited);
        if((i + 1) < visited.size())
            dfs(i + 1, j, grid, visited);
        if((j - 1) >= 0)
            dfs(i, j - 1, grid, visited);
        if((j + 1) < visited[0].size())
            dfs(i, j + 1, grid, visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        // scan the matrix, jump and increment for every restart
        vector<vector<bool>> visited;
        for(int i = 0; i < grid.size(); ++i)
        {
            vector<bool> arr(grid[0].size(), false);
            visited.push_back(arr);
        }
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if (visited[i][j] == true)
                    continue;
                if (grid[i][j] == '0')
                    visited[i][j] = true;
                else // unexplored land
                {
                    dfs(i, j, grid, visited);
                    ++numIslands;
                }
            }
        }
        return numIslands;
    }
};
