class Solution {
public:
    using T = tuple<int,int,int>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // vector<int> prices(n,INT_MAX);
        // prices[src] = 0;
        // for(int i=0;i<=k;i++){
        //     vector<int> temp = prices;
        //     for(auto& flight:flights){
        //         int u = flight[0],v = flight[1],w = flight[2];
        //         if(prices[u] == INT_MAX) continue;
        //         if(prices[u] + w<temp[v]){
        //             temp[v] = prices[u]+w;
        //         }
        //     }
        //     prices = temp;
        // }
        // return prices[dst] == INT_MAX?-1:prices[dst];

        vector<vector<int>> dist(n,vector<int>(k+2,1e9));
        vector<vector<pair<int,int>>> adj(n);
        for(auto &flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        dist[src][0] = 0;
        priority_queue<T,vector<T>,greater<>> minHeap;
        minHeap.push({0,src,-1});
        while(!minHeap.empty()){
            auto [cost,node,stops] = minHeap.top();
            minHeap.pop();
            if(node == dst) return cost;
            if(stops == k || dist[node][stops+1]<cost) continue;
            for(auto&[nextNode,wt]:adj[node]){
                if(cost+wt<dist[nextNode][stops+2]){
                    dist[nextNode][stops+2] = cost+wt;
                    minHeap.emplace(cost+wt,nextNode,stops+1);
                }
            }
        }
        return -1;
    }
};
