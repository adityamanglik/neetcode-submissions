class Solution {
public:
    bool isAnagram(string s, string t) {
        // create character maps
        unordered_map<char, int> map1, map2;
        for(char c:s)
            if(map1.find(c) == map1.end())
                map1[c] = 1;
            else
                map1[c] += 1;
        for(char c:t)
            if(map2.find(c) == map2.end())
                map2[c] = 1;
            else
                map2[c] += 1;
        // compare
        for(char i = 'a'; i <= 'z'; ++i)
        {
            if(map1[i] != map2[i])
                return false;
        }
        return true;
    }
};
