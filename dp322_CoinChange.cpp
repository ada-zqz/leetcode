struct Part{
    int step; //第几步
    int amount; //还需要补足的amount
    Part(int s, int na): step(s), amount(na) {}
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty())
            return -1;
        if(amount == 0)
            return 0;
        
        queue<Part> q;
        for(int i = 0; i < coins.size(); i++) {
            if(amount == coins[i]) {
                return 1;
            }
            if(amount > coins[i]) {
                q.push(Part(1, amount - coins[i]));
            }
        }
        while(!q.empty()) {
            Part p = q.front();
            if(p.amount == 0) {
                return p.step;
            }
            else {
                for(int i = 0; i < coins.size(); i++) {
                    if(coins[i] <= p.amount) {
                        q.push(Part(p.step + 1, p.amount - coins[i]));
                    }
                }
            }
            q.pop();
        }
        return -1;
    }
};
