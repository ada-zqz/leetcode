class Solution {
public:
    string getHappyString(int n, int k) {
        int msk = 1;
        for(int i = 0; i < n; i++) msk *= 3;
        vector<string> possible;
        for(int i = 0; i < msk; i++){
            string cur;
            int v = i;
            for(int j = 0; j < n; j++){
                cur.push_back((v % 3) + 'a');
                v /= 3;
            }
            bool bad = false;
            for(int j = 0; j + 1 < n; j++)
                if(cur[j] == cur[j + 1])
                    bad = true;
            if(!bad)
                possible.push_back(cur);
        }
        sort(possible.begin(), possible.end());
        if(possible.size() < k) return "";
        return possible[k - 1];
    }
};
