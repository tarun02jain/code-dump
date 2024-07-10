class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for(int i = 0; i<logs.size(); i++){
            string temp = logs[i];
            if(temp == "../"){
                if(cnt>0)cnt--;
                else continue;
            }
            else if(temp == "./")continue;
            else cnt++;
        }
        return cnt;
    }
};