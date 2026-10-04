class WordDictionary {
public:
    class TrieNode{
        public:
        bool isEnd;
        vector<TrieNode*> child;
        TrieNode():isEnd(false),child(26,nullptr){}
    };
    TrieNode* head;
    WordDictionary() {
        head = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = head;
        for(char c:word){
            int idx = c-'a';
            if(curr->child[idx] == nullptr){
                curr->child[idx] = new TrieNode();
            }
            curr = curr->child[idx];
        }  
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word,0,head);
    }
    private:
    bool dfs(string&word,int j,TrieNode* curr){
        if(curr == nullptr) return false;
        if(j == word.length()) return curr->isEnd;

        char c= word[j];
        bool ans = false;
        if(c!='.'){
            curr = curr->child[c-'a'];
            ans = ans|| dfs(word,j+1,curr);
        }else{
            for(int i=0;i<26;i++){
                ans = ans|| dfs(word,j+1,curr->child[i]);
            }
        }
        return ans;
    }
};
