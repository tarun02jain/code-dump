class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        int i = 0;
        while (i < res.size() && res[i] == '0') i++;
        
        string temp = "";
        for (int j = i; j < res.size(); j++) {
            temp += res[j];
        }
        
        return temp.empty() ? "0" : temp;
    }
};
