class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int fresh =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0;
        vector<pair<int,int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
        int time =0;
        while(!q.empty() && fresh>0){
            time++;
            int siz = q.size();
            while(siz-->0){
                auto [i,j] = q.front();q.pop();

                for(auto d:dir){
                    int nexti = i+d.first,nextj = j+d.second;
                    if(nexti>=0 && nexti<n && nextj>=0 && nextj<m && grid[nexti][nextj] ==1){
                        fresh--;
                        q.push({nexti,nextj});
                        grid[nexti][nextj] = 2; //rotten
                    }
                }
            }
        }
        if(fresh>0) return -1;
        else return time;
    }
};
