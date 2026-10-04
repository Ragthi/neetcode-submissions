class Solution {
public:
    int getProfit(int indi,vector<int>&prices,vector<int>&dp){
        if(indi>=prices.size()) return 0;
        if(dp[indi] != -1) return dp[indi];
        int maxi = getProfit(indi+1,prices,dp); //skip
        
        for(int i = indi+1;i<prices.size();i++){
            if(prices[i]>prices[indi]){
                maxi = max(maxi,getProfit(i+2,prices,dp) + prices[i]-prices[indi]);
            }
        }
        return dp[indi] = maxi;
    }
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(),-1);
        return getProfit(0,prices,dp);
    }
};
