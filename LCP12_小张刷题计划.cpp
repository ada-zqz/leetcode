class Solution {
public:
    int minTime(vector<int>& time, int m) {
        int sum = 0;
        for(auto t: time) sum += t; // 总任务量
        // 一天完成的任务量最大为t（不帮助时），现在要每天任务量的最大值最小
        // 每天任务量不大于t满足m天完成的条件，每天任务量t+1更满足条件
        int l = 0, r = sum;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(check(time, mid, m)) r = mid; // 每天最大完成mid的任务量没问题, result <= mid
            else l = mid + 1;                // 每天的任务量要提升，result > mid
        }
        return r;
    }
    bool check(vector<int>& time, int S, int m) {
        // 是否可以分成m份，每份帮忙后不大于S
        // 贪心
        int n = time.size();
        int day = 1;
        int sum = 0, sm = 0;  //sum: 一天内的任务量；sm: 耗时最长的任务时间
        bool help = true;
        for(int i = 0; i < n; i++) {
            sum += time[i];
            sm = max(sm, time[i]);
            if(sum > S) {
                if(help) {
                    sum -= sm;
                    help = false;
                }
                else {
                    if(day >= m) return false;
                    day++;
                    i--;
                    sum = 0;
                    sm = 0;
                    help = true;
                }
            }
        }
        return true;
    }
};
