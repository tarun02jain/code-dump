class Solution {
public:
    // int helper(int i, int j, vector<vector<int>>& mat,
    //            vector<vector<int>>& dp) {
    //     if (mat[i][j] == 1)
    //         return 0;
    //     if (i == 0 && j == 0)
    //         return 1;
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     int mod = 2*1e9;
    //     int lefti = 0;
    //     int up = 0;
    //     if (j > 0) {
    //         lefti = helper(i, j - 1, mat, dp);
    //         lefti = lefti % mod;
    //     }
    //     if (i > 0) {
    //         up = helper(i - 1, j, mat, dp);
    //         up = up % mod;
    //     }
    //     return dp[i][j] = (lefti + up) % mod;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        // vector<vector<int>> dp(n, vector<int>(m, 0));

        vector<int> prev(m, 0);

        for (int i = 0; i < n; i++) {
            vector<int> temp(m, 0);
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j] == 1) {
                    temp[j] = 0;
                    continue;
                }
                if (i == 0 && j == 0) {
                    temp[j] = 1;
                    continue;
                }
                int top = 0;
                int lefti = 0;
                if (i > 0) {
                    top = prev[j];
                }
                if (j > 0) {
                    lefti = temp[j - 1];
                }

                temp[j] = top + lefti;
            }
            prev = temp;
        }

        return prev[m-1];
    }
};