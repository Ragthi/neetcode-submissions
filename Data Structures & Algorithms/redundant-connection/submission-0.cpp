class Solution {
public:
    struct DSU{
        vector<int> p,r;
        DSU(int n):p(n),r(n){
            iota(p.begin(),p.end(),0);
        }
        int find(int n){
            if(p[n] == n) return n;
            return p[n] = find(p[n]);
        }
        bool unite(int a,int b){
            a = find(a), b = find(b);
            if(a == b) return false;
            if(r[a]<r[b]) swap(a,b);
            p[b] = a;
            if(r[a] == r[b]) r[a]++;
            return true;
        }

    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n+1);
        for(auto& edge:edges){
            int a = edge[0],b = edge[1];
            if(!dsu.unite(a,b)) return edge;
        }
        return {};
    }
};
