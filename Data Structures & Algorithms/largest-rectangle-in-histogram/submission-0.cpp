class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        for(int len=1;len<=heights.size();len++){
            multiset<int> ms;
            int l=0,r = 0;
            while(r<heights.size()){
                while(r-l<len){
                    ms.insert(heights[r++]);
                }
                ans = max(ans,(*ms.begin()) * len);
                int left = heights[l++];
                auto it = ms.find(left);
                ms.erase(it);
            }
        }
        return ans;
    }
};
