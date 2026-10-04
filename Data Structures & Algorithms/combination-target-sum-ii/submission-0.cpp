class Solution {
public:
    void findAll(vector<vector<int>>&ans,vector<int>&curr,int currSum,int target,int indi,vector<int>&candidates){
        if(currSum == target){
            ans.push_back(curr);return;
        }
        if(indi>=candidates.size() || currSum>target) return;
        if(currSum+candidates[indi]<=target){
            curr.push_back(candidates[indi]);
            currSum+=candidates[indi];
            findAll(ans,curr,currSum,target,indi+1,candidates);
            currSum-=candidates[indi];
            curr.pop_back();
        }
        while(indi+1<candidates.size() && candidates[indi] == candidates[indi+1]) indi++;
        findAll(ans,curr,currSum,target,indi+1,candidates);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        int currSum =0;
        findAll(ans,curr,currSum,target,0,candidates);
        return ans;
    }
};
