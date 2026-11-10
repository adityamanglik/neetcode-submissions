class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxEnding = nums[0];
        int maxSoFar = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(maxEnding + nums[i] > nums[i])
                maxEnding = maxEnding + nums[i];
            else
                maxEnding = nums[i];
            maxSoFar = max(maxEnding, maxSoFar);
        }
        return maxSoFar;
    }
};
