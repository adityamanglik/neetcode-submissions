class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // implement Bellman Ford for SSSP
        if(n == 1)
            return -1;
        vector<int> dist(n, 99999);
        dist[k - 1] = 0;
        // for every vertex, for every edge, relax
        for(int i = 1; i <= n; ++i){
            // // print dist
            // for(auto val:dist)
            //     cout<<val<<"\t";
            // cout<<endl;
            for(auto edge: times){
                int source = edge[0] - 1;
                int sink = edge[1] - 1;
                int weight = edge[2];
                if(dist[sink] > dist[source] + weight)
                    dist[sink] = dist[source] + weight;
                    // print dist
            // for(auto val:dist)
            //     cout<<val<<"\t";
            // cout<<endl;
            }
        }
        // find max
        int ans = INT_MIN;
        for(auto val:dist)
            if(val > ans)
                ans = val;
        if(ans == INT_MIN or ans == 99999)
            return -1;
        return ans;
    }
};
