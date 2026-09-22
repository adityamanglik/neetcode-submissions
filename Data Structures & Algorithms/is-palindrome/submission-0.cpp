class Solution {
public:
    bool isPalindrome(string s) {
        // clean up to only alphanumeric
        stringstream ss;
        for(auto c:s){
            if(isalnum(c))
                ss<<(char)tolower(c);
        }
        string convert = ss.str();
        // parse from both ends using 2 pointer
        int i = 0, j = convert.length() - 1;
        while(i < convert.length() and j >= 0 and i != j)
        {
            if(convert[i] != convert[j])
                return false;
            ++i; --j;
        }
        return true;
    }
};
