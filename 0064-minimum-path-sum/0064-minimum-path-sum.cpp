class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,0));
        // dp[0][0] = grid[0][0];

        vector<int>prev(m,0);
        prev[0] = grid[0][0];

        for(int i = 0; i<n; i++){
            vector<int>temp(m,0);
            for(int j = 0; j<m; j++){

                if(i == 0 && j == 0){
                    temp[0] = grid[0][0];
                    continue;
                }
                int top = INT_MAX;
                if(i>0){
                    top = prev[j];
                }
                int left = INT_MAX;
                if(j>0){
                    left = temp[j-1];
                }

                temp[j]  = grid[i][j] + min(top , left);
            }
            prev= temp;
        }
        return prev[m-1];
    }
};