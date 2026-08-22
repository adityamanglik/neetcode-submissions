class Solution {
public:
    int dfs_wrapper(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited)
    {
        int area = 0;
        // start from i, j
        vector<pair<int, int>> dfs;
        dfs.push_back(make_pair(i, j));
        // traverse matrix using a stack until exhaustion
        while(dfs.size() != 0)
        {
            pair<int, int> curr = dfs.back();
            dfs.pop_back();
            if((visited[curr.first][curr.second] == true) or (grid[curr.first][curr.second] == 0))
                continue;
            visited[curr.first][curr.second] = true;
            area++;
            // cout<<area<<" "<<curr.first<<" "<<curr.second<<"\n";
            // find all valid neighbours and add to dfs
            if (curr.first - 1 >= 0)
                dfs.push_back(make_pair(curr.first - 1, curr.second));
            if (curr.first + 1 < grid.size())
                dfs.push_back(make_pair(curr.first + 1, curr.second));
            if (curr.second - 1 >= 0)
                dfs.push_back(make_pair(curr.first, curr.second - 1));
            if (curr.second + 1 < grid[0].size())
                dfs.push_back(make_pair(curr.first, curr.second + 1));            
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = -1;
        // create visited matrix
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        // traverse matrix to explore each island and find max area
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if (visited[i][j] == true)
                    continue;
                if (grid[i][j] == 0)
                    continue;
                int area = dfs_wrapper(i, j, grid, visited);
                if (area > maxArea)
                    maxArea = area;
            }
        }
        // use dfs to traverse
        if (maxArea == -1)
            return 0;
        return maxArea;
    }
};
