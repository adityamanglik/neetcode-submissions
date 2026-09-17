class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<pair<int, int>> arr;
        for(int i = 0; i < cost.size(); ++i){
            pair<int, int> a(cost[i], 0);
            arr.push_back(a);
        }
        pair<int, int> a(0, 0);
        arr.push_back(a);
        for(int i = 2; i < cost.size() + 1; ++i){
            arr[i].second = min(arr[i-1].first + arr[i-1].second, arr[i-2].first + arr[i-2].second);
        }
        return arr[arr.size() - 1].second;
    }
};
