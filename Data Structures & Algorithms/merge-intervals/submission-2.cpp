class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [&](vector<int>&a,vector<int>&b)->bool{
            return a[0]<b[0];
        };
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> nonOverlappingIntervals;
        for(auto&interval:intervals){
            if(nonOverlappingIntervals.size()!=0){
                vector<int> &last = nonOverlappingIntervals.back();
                if(last[1]>=interval[0]){
                    last[1] = max(last[1],interval[1]);
                }else{
                    nonOverlappingIntervals.push_back(interval);
                }
            }else{
                nonOverlappingIntervals.push_back(interval);
            }
        }
        return nonOverlappingIntervals;
    }
};
