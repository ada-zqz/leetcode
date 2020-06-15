class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // int n = arr.size();
        unordered_map<int, int> mp0; //nums, times
        for(auto a: arr) {
            mp0[a]++;
        }
        unordered_map<int, vector<int>> mp;
        for(auto m: mp0) {
            mp[m.second].push_back(m.first);  //times, nums
        }
        vector<pair<int, vector<int>>> tmp;
        for (auto& i : mp) tmp.push_back(i);
        
        int res = 0;
        sort(tmp.begin(), tmp.end(), [](pair<int, vector<int>>& a, pair<int, vector<int>>& b) {return a.first < b.first;});
        for(int i = 0; i < tmp.size(); i++) {
            int n = tmp[i].second.size();
            int t = tmp[i].first;
            // cout << tmp[i].first << "  --  " <<n << " " << k << endl;
            if(k > 0) {
                if(n * t >= k) {
                    n -= k / t;
                    k = 0;
                }
                else {
                    //n * t < k
                    k = k - n * t;
                    n = 0;
                }
            }
            res += n;
            // cout << n << " " << k << endl;
        }
        return res;
    }
};
