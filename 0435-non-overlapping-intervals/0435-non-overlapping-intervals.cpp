class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int end= intervals[0][1];
        int ans = 0;
        for(int i = 1; i<intervals.size(); i++){
            if(end > intervals[i][0]){
                ans++;
                end = min(end,intervals[i][1]);
            }
            else{
                end = intervals[i][1];
            }
        }
        return ans;
    }
};