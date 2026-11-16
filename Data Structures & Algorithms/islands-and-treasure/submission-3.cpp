class Solution {
public:
    void update(int i, int j, vector<vector<int>>& grid)
    {
        if(i < 0 or i >= grid.size())
            return;
        if(j < 0 or j >= grid[0].size())
            return;
        if(grid[i][j] == 0 or grid[i][j] == -1)
            return;
        // check all neighbors and update values as 1 + min
        int min_val = INT_MAX;
        if((i-1) >= 0){
            if(grid[i-1][j] != -1)
                if(grid[i-1][j] < min_val)
                    min_val = grid[i-1][j];
        }
        if((i+1) < grid.size()){
            if(grid[i+1][j] != -1)
                if(grid[i+1][j] < min_val)
                    min_val = grid[i+1][j];
        }
        if((j-1) >= 0){
            if(grid[i][j-1] != -1)
                if(grid[i][j-1] < min_val)
                    min_val = grid[i][j-1];
        }
        if((j+1) < grid[0].size()){
            if(grid[i][j+1] != -1)
                if(grid[i][j+1] < min_val)
                    min_val = grid[i][j+1];
        }
        if(grid[i][j] <= min_val + 1)
            return;
        if(min_val == INT_MAX)
            return;
        grid[i][j] = min_val + 1;
        // update neighbors
        update(i-1, j, grid);
        update(i+1, j, grid);
        update(i, j-1, grid);
        update(i, j+1, grid);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i = 0 ; i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j){   
                if (grid[i][j] == 0){   
                    update(i-1, j, grid);
                    update(i+1, j, grid);
                    update(i, j-1, grid);
                    update(i, j+1, grid);
                    }
                    // print grid
                    // cout<<"Grid --> "<<i<<" "<<j<<endl;
                    // for(int i = 0 ; i < grid.size(); ++i){
                    //     for(int j = 0; j < grid[0].size(); ++j)
                    //         cout<<grid[i][j]<<"\t";
                    //     cout<<"\n";
                    // }
            }
    }
};
