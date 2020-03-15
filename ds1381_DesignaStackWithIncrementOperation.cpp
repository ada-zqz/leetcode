class CustomStack {
public:
    vector<int> v;
    int maxs = 0;
    int nows = 0;
    CustomStack(int maxSize) {
        maxs = maxSize;
        nows = 0;
        v = vector<int>();   // v = {};
    }
    
    void push(int x) {
        if(nows < maxs) {
            v.push_back(x);
            nows++;
        }
    }
    
    int pop() {
        if(nows > 0) {
            int res = v.back();
            v.pop_back();
            nows--;
            return res;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int m = min(k, nows);
        for(int i = 0; i < m; i++) {
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
