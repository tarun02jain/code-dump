class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>prev(n,0);
        vector<int>curr(n,0);

        for(int i = 0; i<n; i++){
            prev[i] = matrix[n-1][i];
        }

        for(int i = n-2; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                int bottom = prev[j];
                int leftD = INT_MAX;
                if(j>0){
                    leftD = prev[j-1];
                }
                int rightD = INT_MAX;
                if(j<n-1){
                    rightD = prev[j+1];
                }

                curr[j] = matrix[i][j] + min(bottom , min(leftD, rightD));

            }
            prev = curr;
        }
        int mini = INT_MAX;
        for(int i = 0; i<n; i++){
            mini = min(mini , prev[i]);
        }
        return mini;
    }
};