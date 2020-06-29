class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jb(n);
        for(int i = 0; i < n; i++) {
            jb[i] = vector<int>{endTime[i], startTime[i], profit[i]};
        }
        // 根据endtime从小到大排序
        sort(jb.begin(), jb.end());
        
        // dp + binary search
        map<int, int> dp = {{0, 0}}; //endtime, total profit
        for(auto& j: jb) { //应用速度和存储变好
            
            // // int cur = dp.lower_bound(j[1])->second + j[2]; 计算错误，找到的位置不对
            // // [1,2,3,4,6]
            // // [3,5,10,6,9]
            // // [20,20,100,70,60]
            // for(auto d: dp) cout << d.first << ":" << d.second << " ";
            // cout << endl;
            // cout << j[0] << " start: " << j[1] << " find: " << dp.lower_bound(j[1])->first << endl;
            // cout << j[0] << " start: " << j[1] << " find: " << prev(dp.upper_bound(j[1]))->first << endl;
            
            // starttime>j[1]往前走一个的profit + 此时的profit:j[2]
            int cur = prev(dp.upper_bound(j[1]))->second + j[2];
            if(cur > dp.rbegin()->second) dp[j[0]] = cur;
        }
        return dp.rbegin()->second;
    }
};
