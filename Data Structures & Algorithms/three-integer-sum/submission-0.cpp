class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort the array
        sort(nums.begin(), nums.end());
        // create unordered_map for fast lookup
        unordered_map<int, int> tracer;
        for(int i = 0; i < nums.size(); ++i)
            tracer[nums[i]] = i;
        vector<vector<int>> ans;
        set<vector<int>> dup;
        // check all two pairs
        for(int i = 0; i < nums.size(); ++i)
            for(int j = i + 1; j < nums.size(); ++j){
                int val = nums[i] + nums[j];
                if(tracer.find(-1 * val) != tracer.end()){
                    int loc = tracer.find(-1 * val)->second;
                    if (loc == i or loc == j)
                        continue;
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(-1 * val);
                    // search temp for uniqueness
                    vector<int> temp2(temp);
                    sort(temp2.begin(), temp2.end());
                    if(dup.find(temp2) == dup.end()){
                        dup.insert(temp2);
                        ans.push_back(temp);
                    }
                }
            }
        return ans;
    }
};
