class Solution {
public:
    int findCnt(int i,int j,string&s){
        int cnt =0;
        while(i>=0 && j< s.length() && s[i] == s[j]){
            cnt++;i--,j++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int n =s.length();
        int cnt =0;
        for(int i=0;i<n;i++){
            cnt+=findCnt(i-1,i+1,s)+1; //odd len case
            cnt+=findCnt(i,i+1,s); //even len case
        }
        return cnt;
    }
};
