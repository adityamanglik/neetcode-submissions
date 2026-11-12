class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // store number and index
        unordered_map<int, int> idx;
        vector<int> ans;
        idx[nums[0]] = 0;
        for(int i = 1; i < nums.size(); ++i){
            int val = target - nums[i];
            if(idx.find(val) != idx.end()){
                ans.push_back(idx[val]);
                ans.push_back(i);
                return ans;
            }
            idx[nums[i]] = i;
        }
        return ans;
    }
};
