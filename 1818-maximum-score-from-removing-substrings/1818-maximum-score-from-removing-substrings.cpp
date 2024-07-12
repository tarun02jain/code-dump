class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string temp1, temp2;
        if (x > y) {
            temp1 = "ab";
            temp2 = "ba";
        } else {
            temp1 = "ba";
            temp2 = "ab";
        }
        
        int score = 0;
        stack<char> st1, st2;

        // First pass to remove pairs with higher score
        for (char ch : s) {
            if (!st1.empty() && st1.top() == temp1[0] && ch == temp1[1]) {
                score += max(x, y);
                st1.pop();
            } else {
                st1.push(ch);
            }
        }

        // Remaining characters in stack1 are moved to stack2 for the second pass
        while (!st1.empty()) {
            char ch = st1.top();
            st1.pop();
            if (!st2.empty() && st2.top() == temp2[1] && ch == temp2[0]) {
                score += min(x, y);
                st2.pop();
            } else {
                st2.push(ch);
            }
        }

        return score;
    }
};
