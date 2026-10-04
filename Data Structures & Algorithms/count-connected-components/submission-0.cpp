class Solution {
public:
    void dfs(int node,int par,vector<vector<int>>& g,vector<bool>&visited){
        visited[node] = true;
        for(auto &nei:g[node]){
            if(!visited[nei] && par!=nei){
                dfs(nei,node,g,visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,0);
        int cnt =0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                // cout<<i<<endl;
                dfs(i,-1,g,visited);
                cnt++;
            }
        }
        return cnt;
    }
};
