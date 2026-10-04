class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,deque<string>> adj;
        for(auto &ticket:tickets){
            adj[ticket[0]].push_back(ticket[1]);
        }
        for(auto& [src,dests]:adj){
            sort(dests.begin(),dests.end());
        }
        vector<string> ans;
        dfs("JFK",ans,adj);
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void dfs(string src,vector<string>&ans,unordered_map<string,deque<string>>&adj){
        while(!adj[src].empty()){
            string dst = adj[src].front();
            adj[src].pop_front();
            dfs(dst,ans,adj);
        }
        ans.push_back(src);
    }
};
