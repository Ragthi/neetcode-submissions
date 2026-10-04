class Solution {
public:

    // queries sorted [1,2,3,6,7,8]
    // [6,6]
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        vector<int> ans(n,-1);
        set<pair<int,int>> sortedQueries;
        for(int i=0;i<n;i++){
            sortedQueries.insert({queries[i],i});
        }
        sort(intervals.begin(),intervals.end(),[&](vector<int>&a,vector<int>&b){return (a[1]-a[0])<b[1]-b[0];});

        for(auto &interval:intervals){
            auto l = sortedQueries.lower_bound({interval[0],INT_MIN}),r = sortedQueries.upper_bound({interval[1],INT_MAX});
            while(l!=r){
                auto [num,indi] = *l;
                ans[indi] = interval[1]-interval[0]+1;
                l = sortedQueries.erase(l);
            }
        }
        return ans;
    }
};
