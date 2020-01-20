class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() < 2)
            return false;
        int sum = 0;
        for(int num: nums) {
            sum += num;
        }
        //奇数和不可能平分
        if(sum & 1) 
            return false;
        //平分后的数为sum
        sum = sum / 2; 
        
        sort(nums.begin(), nums.end());
        if(nums[nums.size() - 1] > sum)
            return false;
        return Dfs(nums.size() - 2, sum - nums[nums.size() - 1], nums); //利用i及之前的数字相加得到sum
    }
    
    bool Dfs(int i, int sum, vector<int>& nums) {
        if(sum == 0 && i >= 0) 
            return true;
        if(sum < nums[0]) //最小值都大于sum，已经不可能找到求和为sum的值
            return false;
        for(int j = i; j >= 0; j--) {
            if(j == 0) {
                if(sum != nums[0])
                    return false;
                else
                    return true;
            }
            if(sum < nums[j]) 
                continue;
            else {
                if(Dfs(j - 1, sum - nums[j], nums))
                    return true;
                else
                    continue;
            }
        }
        return false;
    }
};
