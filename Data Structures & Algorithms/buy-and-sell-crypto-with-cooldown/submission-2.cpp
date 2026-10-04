class Solution {
public:
    int getProfit(int indi,vector<int>&prices,bool boughtIndex,vector<vector<int>>&dp){

        if(indi>=prices.size()) return 0;
        if(dp[indi][boughtIndex] !=-1) return dp[indi][boughtIndex];
        int maxi = getProfit(indi+1,prices,boughtIndex,dp); //skip
        if(!boughtIndex){
            maxi = max(getProfit(indi+1,prices,1,dp)-prices[indi],maxi); //buy
        }else{

            maxi = max(getProfit(indi+2,prices,0,dp)+prices[indi],maxi); //sell
            
        }
        return dp[indi][boughtIndex] = maxi;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2 , -1));
        return getProfit(0,prices,0,dp);
    }
};
