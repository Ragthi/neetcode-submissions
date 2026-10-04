class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n);
        for(auto&time:times){
            adj[time[0]-1].push_back({time[1]-1,time[2]});
        }
        k--;
        dist[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        set<int> visited;
        
        while(visited.size()!=n && !pq.empty()){
            auto [wt,node] = pq.top();
            pq.pop();
            if(wt>dist[node]) continue;
            visited.insert(node);
            if(visited.size() == n) return wt;
            for(auto [nextNode,nextWt]:adj[node]){
                if(nextWt+dist[node]<dist[nextNode] && visited.find(nextNode) == visited.end()){
                    dist[nextNode] = dist[node]+nextWt;
                    pq.push({dist[nextNode],nextNode});
                }
            }
        }
        // cout<<"size "<<visited.size()<<endl;
        // for(int i=0;i<n;i++) cout<<dist[i]<<" ";
        return -1;
        // int farthest = *max_element(dist.begin(),dist.end());
        // if(farthest == INT_MAX) return -1;
        // return farthest;
    }
};
