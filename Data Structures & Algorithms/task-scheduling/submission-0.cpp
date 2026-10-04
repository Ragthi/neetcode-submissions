class Solution {
public:
    // A : 4  A (n) A (n) A (n) A :  cnt(A) + (cnt(A)-1)*n
    // B : 4
    // C : 3
    int leastInterval(vector<char>& tasks, int n) {
        int ans = tasks.size();
        vector<int> freq(26,0);
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        sort(freq.begin(),freq.end(),greater<>());
        int maxi = freq[0];
        int same =0;
        for(int i=0;i<26;i++){
            if(freq[i] == maxi) same++;
            else break;
        }
        if(same>n){
            ans = max(ans,same*maxi);
        }else{
            ans = max(ans,maxi + (maxi-1)*n + same-1);
        }
        return ans;
    }
};
