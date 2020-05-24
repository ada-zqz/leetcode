class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int res = -1, id = 1;
        string wd;
        for(int i = 0; i < sentence.size(); i++) {
            if(sentence[i] == ' ') {
                wd = "";
                id++;
            }
            else {
                wd = wd + sentence[i];
                if(wd == searchWord) {
                    res = id;
                    break;
                }
            }            
        }
        return res;
    }
};
