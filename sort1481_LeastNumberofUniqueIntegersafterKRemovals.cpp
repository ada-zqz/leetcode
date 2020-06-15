class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // int n = arr.size();
        unordered_map<int, int> mp; //nums, times
        for(auto a: arr) {
            mp[a]++;
        }
        vector<int> tmp; //每个数出现的次数
        for (auto& m : mp) tmp.push_back(m.second);
        
        int res = tmp.size(); //不同的数的个数
        sort(tmp.begin(), tmp.end());
        for(int i = 0; i < tmp.size(); i++) {
            if(k == 0 || tmp[i] > k) {
                // 到第i个数就能搞定
                return res;
            }
            k -= tmp[i];
            res--;
        }
        return res;
    }
};
