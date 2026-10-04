class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> possible(n+1,0);
        possible[0] = true;
        for(int i=1;i<=n;i++){
            if(!possible[i-1]) continue;
            for(auto &str:wordDict){
                if(str.length()+i-1<=n){
                    if(str == s.substr(i-1,str.length())){
                        possible[i+str.length()-1] = true;
                    }
                }
            }
        }
        return possible[n];
    }
};
