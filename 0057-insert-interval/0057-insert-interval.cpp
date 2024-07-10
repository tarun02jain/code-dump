class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start_new = newInterval[0];
        int end_new = newInterval[1];

        vector<vector<int>>ans;

        for(int i = 0; i<intervals.size(); i++){
            int a = intervals[i][0];
            int b = intervals[i][1];

            if(a>end_new){
                ans.push_back({start_new, end_new});
                start_new = a;
                end_new = b;
            }
            else if(b<start_new){
                ans.push_back({a,b});
            }
            else{
                int temp1 = min(a,start_new);
                int temp2 = max(b,end_new);
                start_new = temp1;
                end_new = temp2;
            }
            
        }
        ans.push_back({start_new,end_new});

        return ans;
    }
};