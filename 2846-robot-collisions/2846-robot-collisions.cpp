class Solution {
public:
    
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& health, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), 
         [&](int a, int b){return positions[a] < positions[b] ;});

        for (int ind : indices) {
            if (directions[ind] == 'R')
                st.push(ind);

            else {
                while (!st.empty() && health[ind] > 0) {
                    int top = st.top();
                    st.pop();
                    if (health[top] > health[ind]) {
                        health[ind] = 0;
                        health[top] -= 1;
                        st.push(top);
                    } else if (health[ind] > health[top]) {
                        health[top] = 0;
                        health[ind] -= 1;
                       
                    } else {
                        health[top] = 0;
                        health[ind] = 0;
                    }
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (health[i] > 0)
                ans.push_back(health[i]);
        }
        return ans;
    }
};