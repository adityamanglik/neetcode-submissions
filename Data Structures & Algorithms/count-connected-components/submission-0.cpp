class Solution {
public:
    void dfs(int i, vector<vector<int>>& graph, vector<bool>& visited)
    {
        // cout<<"Explore "<<i<<endl;
        if(visited[i] == true)
            return;
        visited[i] = true;
        for(auto child:graph[i])
            dfs(child, graph, visited);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        // create bidirectional graph
        vector<vector<int>> graph(n, vector<int>());
        for(auto edge:edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        // 1 node edge case
        if(n == 1)
            return 1;
        int components = 0;
        vector<bool> visited(n, false);
        // run dfs on every unexplored vertex
        for(int i = 0; i < n; ++i)
            if(visited[i] == false)
                {
                    dfs(i, graph, visited);
                    components++;
                }
        // return number of unexplored vertices
        for(int i = 0; i < n; ++i)
            if(visited[i] == false)
                components++;
        return components;
    }
};
