class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int negs = 0, zeros = 0;
        for(auto val:nums)
        {   if (val != 0) 
                product *= abs(val);
            else
                ++zeros;
            if (val < 0)
                ++negs;
        }
        negs %= 2;
        if (zeros > 1)
            return vector<int>(nums.size(), 0);
        vector<int> ans;
        for(auto val:nums)
        {   if(zeros == 1){
                if (val != 0){
                    ans.push_back(0);
                }
                else{
                    int value = product; 
                    if (negs != 0)
                        value *= -1;
                    ans.push_back(value);
                }
                continue;
            }
            int value = product/abs(val); 
            if (negs != 0 and val > 0)
                value *= -1;
            if (negs == 0 and val < 0)
                value *= -1;
            ans.push_back(value);
        }
        return ans;
    }
};
