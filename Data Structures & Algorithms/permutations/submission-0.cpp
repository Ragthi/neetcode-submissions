class Solution {
public:
    void findAll(vector<vector<int>>&ans, vector<int>&curr,vector<int>&visited,vector<int>&nums){
        if(curr.size() == visited.size()){
            ans.push_back(curr);return;
        }
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                curr.push_back(nums[i]);
                visited[i] = 1;
                findAll(ans,curr,visited,nums);
                visited[i] = 0;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr,visited(n,0);
        findAll(ans,curr,visited,nums);
        return ans;
    }
};
