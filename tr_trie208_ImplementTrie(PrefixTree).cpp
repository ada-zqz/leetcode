class TrieNode {
public:
    bool isword;
    TrieNode* next[26];
    TrieNode(bool iw = false) {
        isword = iw;
        memset(next, 0, sizeof(next));  
    }
};

class Trie {
private:
    TrieNode* root;
    TrieNode* findstring(string s) {
        TrieNode* tmp = root;
        for(int i = 0; i < s.size(); i++) {
            if(tmp->next[s[i] - 'a'] != nullptr) {
                tmp = tmp->next[s[i] - 'a'];
            }
            else {
                tmp = nullptr;
                break;
            }
        }
        return tmp;
    }
    void clear(TrieNode* root) {
        for(int i = 0; i < 26; i++) {
            if(root->next[i] != nullptr) clear(root->next[i]);
        }
        delete root;
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    ~Trie() {
        clear(root);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* tmp = root;
        for(int i = 0; i < word.size(); i++) {
            if(tmp->next[word[i] - 'a'] == nullptr) {
                tmp->next[word[i] - 'a'] = new TrieNode;
            }
            tmp = tmp->next[word[i] - 'a'];
        }
        tmp->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto tmp = findstring(word);
        if(tmp != nullptr && tmp->isword) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto tmp = findstring(prefix);
        if(tmp != nullptr) return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
