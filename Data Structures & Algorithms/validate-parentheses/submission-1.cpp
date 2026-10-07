class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0)
            return true;
        stack<char> st;
        for(auto c:s){
            if (c == '[' or c == '(' or c == '{')
                st.push(c);
            else if (c == ']'){
                if(st.size() == 0)
                    return false;
                if(st.top() != '[')
                    return false;
                st.pop();
            }
            else if (c == '}'){
                if(st.size() == 0)
                    return false;
                if(st.top() != '{')
                    return false;
                st.pop();
            }
            else if (c == ')'){
                if(st.size() == 0)
                    return false;
                if(st.top() != '(')
                    return false;
                st.pop();
            }
        }
        if(st.size() != 0)
            return false;
        return true;
    }
};
