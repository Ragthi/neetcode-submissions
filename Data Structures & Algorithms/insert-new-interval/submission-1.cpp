class Solution {
public:
    void append(vector<vector<int>>&ans , vector<int>&append){
        if(ans.size() == 0){
            ans.push_back(append);
        }
        if(ans[ans.size()-1][1]>=append[0]){
            ans[ans.size()-1][1] = max(ans[ans.size()-1][1],append[1]);
        }else{
            ans.push_back(append);
        }
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        vector<int> toAppend;
        for(int i=0;i<intervals.size();i++){
            auto interval = intervals[i];
            if(newInterval[0] == -1){
                toAppend = interval;
            }else{
                if(interval[0]<newInterval[0]){
                    toAppend = interval;
                }else{
                    toAppend = newInterval;
                    i--;
                    newInterval[0] = -1;
                }
            }
            // cout<<toAppend[0]<<" "<<toAppend[1]<<endl;
            append(ans,toAppend);
        }
        if(newInterval[0] != -1)
            append(ans,newInterval);
        return ans;
    }
};
