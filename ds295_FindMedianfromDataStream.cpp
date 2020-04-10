class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> small; //max-heap
    priority_queue<int, vector<int>, greater<int>> large; //min-heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(small.empty() || num < small.top()) {
            small.push(num);
        }
        else large.push(num);
        
        if(small.size() < large.size()) {
            small.push(large.top());
            large.pop();
        }
        else if(small.size() - large.size() == 2) {
            large.push(small.top());
            small.pop();
        }
    }
    
    double findMedian() {
        if(small.size() > large.size()) return small.top();
        else return 0.5 * (small.top() + large.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
