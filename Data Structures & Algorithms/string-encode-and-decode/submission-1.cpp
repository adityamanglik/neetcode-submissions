class Solution {
public:

    string encode(vector<string>& strs) {
        stringstream ss;
        for(auto s:strs)
            ss<<s<<"~"<<s.length()<<"~";
        return ss.str();
    }

    int stonum(string& s, int i, int j){
        // read number
        int number = 0;
        for(int k = i; k <= j and k < s.length(); ++k){
            number = (number*10) + int(s[k] - '0');
        }
        return number;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        if (s == "")
            return ans;
        // traverse the string for #length
        for (int i = 0; i < s.length(); ++i){
            if(s[i] == '~' and (i + 1) < s.length()){
                // possible delimiter
                cout<<s[i]<<"\t";
                int j = i + 1;
                while(j < s.length() and s[j] != '~')
                    ++j;
                if(j == s.length() and s[j-1] != '~')
                    continue; // TODO
                // number is between [i + 1 and j - 1]
                j--;
                int len = stonum(s, i+1, j);
                // read len characters and append
                stringstream ss;
                for(int k = i - len; k < s.length() and k < i; ++k)
                {
                    ss << s[k];
                }
                ans.push_back(ss.str());
                i = j + 1;
            }
        }
        return ans;
    }
};
