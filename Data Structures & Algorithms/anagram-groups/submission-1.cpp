class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // run length encoding equivalent
        unordered_map<string, vector<string>> runlength;
        unordered_map<string, int> duplicates;
        set<string> uniques;
        int empty_string_count = 0;
        for(string s:strs)
        {   if (s.length() == 0)
            {   empty_string_count++;
                continue;
            }
            stringstream ss;
            vector<int> counter(26, 0);
            // count characters
            for(char c:s)
                counter[c - 'a']++;
            // convert into RLE representation
            for(char i = 'a'; i <= 'z'; ++i)
                ss<<i<<counter[i - 'a'];
            string rle = ss.str();
            //store in map and set
            if(runlength.find(rle) == runlength.end())
                runlength[rle] = vector<string>();
            runlength[rle].push_back(s);
            // cout<<rle<<endl;
        }
        // how to compare? --> N2 iterate over map to find keys with same value
        vector<vector<string>> ans;
        for(auto unique:runlength)
        {   
            ans.push_back(unique.second);
        }
        if(empty_string_count != 0)
        {
            vector<string> temp;
            for(int i = 0; i < empty_string_count; ++i)
                temp.push_back("");
            ans.push_back(temp);
        }
        return ans;
    }
};
