class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n);
        unordered_map<int, int> mp; //lake, index
        deque<int> zero; //用来排空的位置
        if(rains[0] > 0) {
            //下雨
            res[0] = -1;
            mp[rains[0]] = 0;
        }
        else {
            //随便排空
            res[0] = 1;
        }
        for(int i = 1; i < n; i++) {
            if(rains[i] > 0) {
                //下雨
                if(mp.find(rains[i]) == mp.end()) {
                    mp[rains[i]] = i;
                    
                }
                else {
                    //需要排空
                    for(int j = 0; j < zero.size(); j++) {
                        if(zero[j] > mp[rains[i]]) {
                            res[zero[j]] = rains[i];
                            zero.erase(zero.begin() + j);
                            mp[rains[i]] = i;
                            break;
                        }
                    }
                    if(mp[rains[i]] != i) {
                        // flood
                        res.clear();
                        return res;
                    }
                }
                res[i] = -1;
            }
            else {
                //rains[i] = 0;
                zero.push_back(i);
            }
        }
        for(auto i: zero) res[i] = 1;
        return res;
    }
};
