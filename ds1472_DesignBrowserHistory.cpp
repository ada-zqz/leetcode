class BrowserHistory {
public:
    int sz;  //大小
    int pre; //所在位置
    vector<string> bh;
    BrowserHistory(string homepage) {
        bh = vector<string>(5005,"");
        sz = 1;
        pre = 0;
        bh[pre]= homepage;
    }
    
    void visit(string url) {
        bh[++pre] = url;
        sz = pre + 1;
    }
    
    string back(int steps) {
        pre = max(0, pre - steps);
        return bh[pre];
    }
    
    string forward(int steps) {
        pre = min(sz - 1, pre + steps);
        return bh[pre];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
