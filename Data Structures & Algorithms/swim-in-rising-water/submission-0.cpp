class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxi = grid[0][0];
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({grid[0][0],0,0});
        visited[0][0] = true;
        vector<pair<int,int>> dir{{0,-1},{0,1},{-1,0},{1,0}};
        while(!pq.empty()){
            auto [wt,x,y] = pq.top();
            pq.pop();
            maxi = max(maxi,grid[x][y]);
            if(x == n-1 && y == n-1) return maxi;

            for(auto d:dir){
                int nextx = x+d.first,nexty = y+d.second;
                if(nextx>=0 && nextx<n && nexty>=0 && nexty<n && !visited[nextx][nexty]){
                    visited[nextx][nexty] = true;
                    pq.push({grid[nextx][nexty],nextx,nexty});
                }
            }
        }
        return -1;
    }
};
