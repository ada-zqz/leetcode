class TrieNode {
public:
    bool iswd;
    TrieNode* next[26];
    TrieNode() {
        iswd = false;
        memset(next, NULL, sizeof(next));
    }
};

class WordDictionary {
private:
    TrieNode* root;
    void clear(TrieNode* root) {
        for(int i = 0; i < 26; i++) {
            if(root->next[i] != NULL) clear(root->next[i]);
        }
        delete root;
    }
    bool subsearch(string word, TrieNode* root) {
        int n = word.size();
        if(n == 0 && root) return root->iswd;
        for(int i = 0; i < n; i++) {
            if(word[i] != '.') {
                if(root->next[word[i] - 'a'] == NULL) return false;
                else root = root->next[word[i] - 'a'];
            }
            else {
                for(int j = 0; j < 26; j++) {
                    if(root->next[j] != NULL) 
                        if(subsearch(word.substr(i + 1, n - i - 1), root->next[j]))
                            return true;
                }
                return false;
            }
        }
        return root->iswd;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode;
    }
    ~WordDictionary() {
        clear(root);
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* tmp = root;
        for(int i = 0; i < word.size(); i++) {
            if(tmp->next[word[i] - 'a'] == NULL) 
                tmp->next[word[i] - 'a'] = new TrieNode;
            tmp = tmp->next[word[i] - 'a'];
        }
        tmp->iswd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return subsearch(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
