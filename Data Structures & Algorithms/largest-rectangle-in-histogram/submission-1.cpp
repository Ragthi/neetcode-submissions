class Solution {
public:
    // [1,2,3,4,5,3,2,1]
    int largestRectangleArea(vector<int>& heights) {
        // int ans = 0;
        // for(int len=1;len<=heights.size();len++){
        //     multiset<int> ms;
        //     int l=0,r = 0;
        //     while(r<heights.size()){
        //         while(r-l<len){
        //             ms.insert(heights[r++]);
        //         }
        //         ans = max(ans,(*ms.begin()) * len);
        //         int left = heights[l++];
        //         auto it = ms.find(left);
        //         ms.erase(it);
        //     }
        // }
        // return ans;
        int n = heights.size();
        vector<int> leftMost(n,-1),rightMost(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty()){
                leftMost[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty()){
                rightMost[i] = st.top();
            }
            st.push(i);
        }
        int ans =0;
        for(int i=0;i<n;i++){
            ans = max(ans,(rightMost[i]-leftMost[i]-1)*heights[i]);
        }
        return ans;
    }
};
