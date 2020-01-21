class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty())
            return -1;
        if(amount == 0)
            return 0;
        sort(coins.begin(), coins.end());
        if(amount < coins[0])
            return -1;
        
        int fn = 0; //fewest number
        for(int i = coins.size() - 1; i >= 0; i--) {
            if(coins[i] > amount)
                continue;
            int mc = int(amount / coins[i]);
            int rs = amount % coins[i];
            if(rs == 0)
                return mc;
            while(mc > 0) {
                fn += mc;
                if(Dfs(i, amount - mc * coins[i], fn, coins))
                    return fn;
                fn -= mc;    
                mc--;
            }
        }
        return -1;
    }
    
    bool Dfs(int i, int amount, int& fn, vector<int>& coins) {
        if(amount == 0)       //拼成功
            return true;
        if(amount < coins[0]) //不可能拼成功了
            return false;
        if(i == 0)            //已经判断过amount不是coins[0]的整数倍
            return false;
        
        for(int j = i - 1; j >= 0; j--) {
            if(coins[j] > amount)
                continue;
            int mc = int(amount / coins[j]);
            int rs = amount % coins[j];
            if(rs == 0) {
                fn += mc;
                return true;
            }
            while(mc > 0) {
                fn += mc;
                if(Dfs(j, amount - mc * coins[j], fn, coins))
                    return true;
                fn -= mc;    
                mc--;
            }
        }
        return false;
    }
};
