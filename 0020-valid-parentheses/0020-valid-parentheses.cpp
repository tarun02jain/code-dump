class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i = 0; i<s.length(); i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if (s[i] == ')' && ( !st.size()||st.top() != '(' )) return false;
                if (s[i] == '}' &&  (!st.size()||st.top() != '{' )) return false;
                if (s[i] == ']' && (!st.size()||st.top() != '[' )) return false;
                st.pop(); 
            }
        }
        if (st.size() == 0) return true;
        return false;
    }
};