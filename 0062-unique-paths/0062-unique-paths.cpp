class Solution {
public:
    int uniquePaths(int m, int n) {

   int totalSteps = m+n-2;
	int k = m-1;
	long long ans = 1;

	for(int i = 1; i<=k; i++){
		ans *= (totalSteps - k + i);

		ans /= i;
	}
     if (ans > INT_MAX)
            return INT_MAX;
        return static_cast<int>(ans);
    }
};