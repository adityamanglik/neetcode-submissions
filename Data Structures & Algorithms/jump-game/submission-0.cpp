class Solution {
public:
    bool canJump(vector<int>& nums) {
        // look back, restrict based on last possible jump
        int end = nums.size() - 1;
        if(end == 0)
            return true;
        int curr = nums.size() - 2;
        bool reached = false;
        while(curr > -1){
            if(nums[curr] + curr < end){
                curr--;
            } // unreachable
            else{
                reached = true;
                end = curr;
                curr--;
            }
        }
        if(reached == false)
            return false;
        if(end == 0)
            return true;
        return false;
    }
};
