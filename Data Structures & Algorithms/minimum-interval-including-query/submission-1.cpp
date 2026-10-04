class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end(),[&](vector<int>&interval,vector<int>&intervalb){
            return interval[0]<intervalb[0];
        });

        vector<pair<int,int>> sortedQueries;
        for(int i=0;i<queries.size();i++){
            sortedQueries.push_back({queries[i],i});
        }
        sort(sortedQueries.begin(),sortedQueries.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> result(queries.size(),-1);
        int i=0;
        for(auto &query:sortedQueries){
            int q = query.first;
            int posi = query.second;
            while(i<intervals.size() && intervals[i][0]<=q){
                pq.push({intervals[i][1]-intervals[i][0]+1,intervals[i][1]});i++;
            }
            while(!pq.empty() && pq.top().second<q) pq.pop();
            result[posi] = pq.empty()?-1:pq.top().first;
        }
        return result;
    }
};
