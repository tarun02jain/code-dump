class Solution {
public:
    int area(vector<int>&heights){
        int maxA = 0;
        int n = heights.size();
        stack<int>st;

        for(int i = 0; i<=n; i++){
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i] )){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width = i;
                }
                else{
                    width = (i-st.top() - 1);
                }
                maxA = max(maxA , height*width);
            }
            st.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int>heights(col,0);
        int ans = 0;

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(matrix[i][j] == '1')heights[j]++;
                else heights[j] = 0;
            }
            ans = max(ans , area(heights));
        }
        return ans;
    }
};