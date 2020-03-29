class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) {
            if(arr[0] == 1) return 1;
            else return -1;
        }
        sort(arr.begin(), arr.end());
        
        int lk = -1;
        unordered_map<int, int> mp;
        mp[arr[0]] = 1;
        for(int i = 1; i < n; i++) {
            if(mp.find(arr[i]) == mp.end()) mp[arr[i]] = 1;
            else mp[arr[i]] += 1;
            if(arr[i] > arr[i - 1]) {
                if(mp[arr[i - 1]] == arr[i - 1]) lk = arr[i - 1]; 
            }
        }
        if(mp[arr[n - 1]] == arr[n - 1]) lk = arr[n - 1];
        return lk;
    }
};
