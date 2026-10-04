class SlidingWindow{
    private:
    int maxf;
    unordered_map<int,int> cnt;
    int currentSize;
    public:
    SlidingWindow():maxf(0),currentSize(0) {}

    void add(char c){
        currentSize++;
        cnt[c]++;
        maxf = max(maxf,cnt[c]);
    }
    void remove(char c){
        currentSize--;
        cnt[c]--;
    }
    int reqExceptions(){
        return currentSize-maxf;
    }

};
class Solution {
public:
    int characterReplacement(string s, int k) {
        SlidingWindow sw;
        int ans =0;
        for(int r=0,l=0;r<s.length();r++){
            sw.add(s[r]);

            if(sw.reqExceptions()>k){
                sw.remove(s[l]);
                l++;
            }
            ans = max(ans,r-l+1);


        }
        return ans;
    }
};
