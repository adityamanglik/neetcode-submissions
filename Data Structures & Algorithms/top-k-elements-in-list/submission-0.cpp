class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for(auto val:nums)
            if(counter.find(val) == counter.end())
                counter[val] = 1;
            else
                counter[val] += 1;
        
        // make vector of pairs
        vector<pair<int, int>> arr;
        for(auto iter:counter)
            arr.push_back(make_pair(iter.first, iter.second));
        // print arr
        // for(auto val:arr)
        //     cout<<val.first<<" "<<val.second<<endl;
        // sort vector by freq
        sort(arr.begin(), arr.end(), [](auto &left, auto &right)
        {
            return left.second > right.second;
        }
        );
        // print arr
        // for(auto val:arr)
        //     cout<<val.first<<" "<<val.second<<endl;
        vector<int> ans;
        for(int i = 0; i < k; ++i)
            ans.push_back(arr[i].first);
        return ans;
    }
};
