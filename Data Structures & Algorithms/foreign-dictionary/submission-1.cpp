class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,unordered_set<char>> adj;
        unordered_map<char,int> indegree;
        for (string w : words) {
            for (char c : w) {
                indegree[c] = 0;
            }
        }
        for(int i=0;i<words.size()-1;i++){
            string first = words[i];
            int j= i+1;
                string second = words[j];
                int f =0,s=0;
                while(f<first.size() && s<second.size() && first[f] == second[s]){
                    f++,s++;
                }
                if(second.size() == s && first.size()>second.size()) return "";
                if(f == first.size() || second.size() == s) continue;
                if(adj[first[f]].count(second[s])){

                }else{
                    adj[first[f]].insert(second[s]);
                    indegree[second[s]]++;
                }
            
        }
        queue<char> q;
        for(auto &id:indegree){
            // cout<<id.first<<" "<<id.second<<endl;
            if(id.second == 0) q.push(id.first);
        }
        string ans;
        while(!q.empty()){
            char c = q.front();
            q.pop();
            ans+=c;
            for(char nei:adj[c]){
                // cout<<nei<<" "<<c<<endl;
                indegree[nei]--;
                if(indegree[nei] == 0) q.push(nei);
            }
        }
        cout<<ans<<endl;
        return ans.size() == indegree.size()?ans:"";
    }
};
