class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 字典变为hash table方便查找
        unordered_set<string> wl(wordList.begin(), wordList.end());
        if(!wl.count(endWord)) return 0;
        
        int step = 0;
        int l = endWord.size();
        unordered_set<string> q1;
        unordered_set<string> q2;  //方便查询是否重合
        q1.insert(beginWord);
        q2.insert(endWord);
        while(!q1.empty() && !q2.empty()) {
            step++;
            if(q1.size() > q2.size()) swap(q1, q2); //两端尽可能平衡
            unordered_set<string> q;
            //对少的一端变化
            for(auto w: q1) {
                for(int i = 0; i < l; i++) {
                    char tmp = w[i];  //改变之前的字符
                    for(int j = 'a'; j <= 'z'; j++) {
                        w[i] = j;  //左边是char，右边是int!
                        if(q2.count(w)) return step + 1;
                        if(!wl.count(w)) continue; //不在字典里
                        q.insert(w); //在字典里，根据erase也保证不会再重复
                        wl.erase(w); //保证不会重复加入，单词只用一次，重复使用路径一定加长
                    }
                    w[i] = tmp; //变回去，之后改变i++
                }
            }
            swap(q1, q);
        }
        return 0;
    }
};
