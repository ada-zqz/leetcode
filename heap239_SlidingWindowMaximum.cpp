class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Monotonic Queue
        deque<int> dq;  //可以存储数值，也可以存储index
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            // 最大值在window外
            if(!dq.empty() && dq.front() == i - k) dq.pop_front();
            // 比新出现的值小的值没有用处
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            // 最大的放在front
            if(i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
