class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(),m = text2.size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(text1[0] == text2[j]) dp[0][j] = 1;
            if (j > 0) dp[0][j] = max(dp[0][j], dp[0][j-1]);
        }
        for(int j=0;j<n;j++){
            if(text1[j] == text2[0]) dp[j][0] = 1;
            if (j > 0) dp[j][0] = max(dp[j][0], dp[j-1][0]);

        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                if(text1[i] == text2[j]) dp[i][j] = max(dp[i][j],1+dp[i-1][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};
