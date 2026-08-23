class Solution {
public:
    inline void set_dist(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dist)
    {
        pair<int, int> curr;
        curr.first = i;
        curr.second = j;
        // check every edge for min value
        if(curr.first - 1 >= 0){
            // check valid
            if(grid[curr.first - 1][curr.second] != 0)
            // set dist
                dist[curr.first][curr.second] = min(dist[curr.first][curr.second], dist[curr.first - 1][curr.second]);
        }
        if(curr.first + 1 < grid.size()){
            // check valid
            if(grid[curr.first + 1][curr.second] != 0)
                dist[curr.first][curr.second] = min(dist[curr.first][curr.second], dist[curr.first + 1][curr.second]);
        }
        if(curr.second - 1 >= 0){
            // check valid
            if(grid[curr.first][curr.second - 1] != 0)
                dist[curr.first][curr.second] = min(dist[curr.first][curr.second], dist[curr.first][curr.second - 1]);
        }
        if(curr.second + 1 < grid[0].size()){
            // check valid
            if(grid[curr.first][curr.second + 1] != 0)
                dist[curr.first][curr.second] = min(dist[curr.first][curr.second], dist[curr.first][curr.second + 1]);
        }
        dist[curr.first][curr.second] += 1;
    }
    void traverse(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dist)
    {
        // traverse path to fresh fruit
        vector<pair<int, int>> bfs;
        set<pair<int, int>> visited;
        bfs.push_back(make_pair(i, j));
        while(bfs.size() > 0)
        {
            pair<int, int> curr = bfs.back();
            bfs.pop_back();
            if(visited.find(curr) != visited.end())
                continue;
            visited.insert(curr);
            // check every edge
            if(curr.first - 1 >= 0){
                // check valid
                if(grid[curr.first - 1][curr.second] == 1)
                {// set dist
                    set_dist(curr.first - 1, curr.second, grid, dist);
                // append to bfs
                    bfs.push_back(make_pair(curr.first - 1, curr.second));
                }
            }
            if(curr.first + 1 < grid.size()){
                // check valid
                if(grid[curr.first + 1][curr.second] == 1)
                {// set dist
                    set_dist(curr.first + 1, curr.second, grid, dist);
                // append to bfs
                    bfs.push_back(make_pair(curr.first + 1, curr.second));
                }
            }
            if(curr.second - 1 >= 0){
                // check valid
                if(grid[curr.first][curr.second - 1] == 1)
                {// set dist
                    set_dist(curr.first, curr.second - 1, grid, dist);
                // append to bfs
                    bfs.push_back(make_pair(curr.first, curr.second - 1));
                }
            }
            if(curr.second + 1 < grid[0].size()){
                // check valid
                if(grid[curr.first][curr.second + 1] == 1)
                {// set dist
                    set_dist(curr.first, curr.second + 1, grid, dist);
                // append to bfs
                    bfs.push_back(make_pair(curr.first, curr.second + 1));
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        int rottenfruits = 0;
        // start from rotten fruit
        for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 2)
                    dist[i][j] = 0;
                if(grid[i][j] == 2)
                    {traverse(i, j, grid, dist);
                    rottenfruits += 1;}
            }
        // no fruits
        if(rottenfruits == 0)
        {
            // if fruit, return -1
            for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j)
                if(grid[i][j] == 1)
                    return -1;
            // no fruit, return 0
            return 0;
        }
        // traverse dist to find longest path
        int longest = -1;
        for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] != 0 and dist[i][j] > longest)
                    longest = dist[i][j];
            }
        // for(int i = 0; i < grid.size(); ++i)
        //     {for(int j = 0; j < grid[0].size(); ++j)
            
        //         cout<<dist[i][j]<<"\t";
        //         cout<<"\n";
        //     }
            
        // if any fresh fruit is INT_MAX, return -1
        if (longest == INT_MAX)
            return -1;
        return longest;
    }
};
