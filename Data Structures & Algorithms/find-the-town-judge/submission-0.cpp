class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inEdges(n, 0);
        vector<int> outEdges(n, 0);
        for(auto edge: trust){
            inEdges[edge[1] - 1]++;
            outEdges[edge[0] - 1]++;
        }
        int judge = -1;
        for(int i = 0; i < n; ++i){
            if((inEdges[i] == n-1) and (outEdges[i] == 0))
                judge = i + 1;
        }
        return judge;
    }
};