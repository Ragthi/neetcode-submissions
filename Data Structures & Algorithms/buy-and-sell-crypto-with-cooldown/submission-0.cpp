class Solution {
public:
    int getProfit(int indi,vector<int>&prices,int boughtIndex){
        if(indi>=prices.size()) return 0;
        int maxi = getProfit(indi+1,prices,boughtIndex); //skip
        if(boughtIndex == -1){
            maxi = max(getProfit(indi+1,prices,indi),maxi); //buy
        }else{
            if(prices[boughtIndex]<prices[indi]){
                maxi = max(getProfit(indi+2,prices,-1)+prices[indi]-prices[boughtIndex],maxi); //sell
            }
        }
        return maxi;
    }
    int maxProfit(vector<int>& prices) {
        return getProfit(0,prices,-1);
    }
};
