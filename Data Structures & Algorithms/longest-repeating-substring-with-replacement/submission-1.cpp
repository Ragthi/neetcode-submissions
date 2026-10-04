class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> cnt;

        int maxf = 0;
        int ans =0;
        for(int r=0,l=0;r<s.length();r++){
            cnt[s[r]]++;
            maxf = max(maxf,cnt[s[r]]);

            if((r-l+1)-maxf>k){
                cnt[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);


        }
        return ans;
    }
};
