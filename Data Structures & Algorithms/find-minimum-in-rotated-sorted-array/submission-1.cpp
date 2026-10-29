class Solution {
public:
    int findMin(vector<int> &nums) {
        // find min by traversing all elements
        int min_val = INT_MAX;
        for(auto var:nums)
            if(var < min_val){
                min_val = var;
                if(var < nums[nums.size() - 1])
                    break;
            }
        return min_val;
    }
};
