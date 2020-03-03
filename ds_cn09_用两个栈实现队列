class CQueue {
public:
    stack<int> st1, st2;
    CQueue() {
    }
    
    void appendTail(int value) {
        st1.push(value);
    }
    
    int deleteHead() {
        if(st1.empty() && st2.empty()) return -1;
        if(st2.empty()) {
            while(!st1.empty()) {
                int tmp = st1.top();
                st1.pop();
                st2.push(tmp);
            }
        }
        int tmp = st2.top();
        st2.pop();
        return tmp;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
