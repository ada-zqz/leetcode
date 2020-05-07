class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int sm = 0;      // 所有能满足的客人
        int gp = 0;      // 最多的不满意的客人
        int smx = 0;
        int n = customers.size();
        deque<int> unsx; // x时刻内不满意变成满意的客人
        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0) sm += customers[i];
            else {
                // grumpy[i] == 1
                if(unsx.empty() || i - unsx.front() < X) {
                    // X >= 1
                    // X内可以一直累加
                    unsx.push_back(i);
                    smx += customers[i];
                    gp = max(gp, smx);
                }
                else {
                    while(!unsx.empty() && i - unsx.front() >= X) {
                        smx -= customers[unsx.front()];
                        unsx.pop_front();
                    }
                    unsx.push_back(i);
                    smx += customers[i];
                    gp = max(gp, smx);
                }
            }            
        }
        return sm + gp;
    }
};
