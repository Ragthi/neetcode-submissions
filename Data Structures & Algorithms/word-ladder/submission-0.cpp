class Solution {
public:
    int dist(const string&a,string&b){
        int cnt =0;
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i]) cnt++;
        }
        return cnt;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> words(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        words.erase(beginWord);
        int rounds =0;
        while(!q.empty()){
            int size = q.size();
            rounds++;
            while(size-->0){
                string curr = q.front();
                q.pop();
                if(curr == endWord) return rounds;
                set<string> temp = words;
                for(const string& word:temp){
                    if(dist(word,curr)==1){
                        q.push(word);
                        words.erase(word);
                    }
                }
            }
        }
        return 0;
    }
};
