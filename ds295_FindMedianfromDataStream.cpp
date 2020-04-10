class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> nm;
    int n;
    MedianFinder() {
        nm = vector<int>();
        n = 0;
    }
    
    void addNum(int num) {
        nm.push_back(num);
        n++;
    }
    
    double findMedian() {
        sort(nm.begin(), nm.end());
        if(n % 2 == 1) return nm[n / 2];
        return 0.5 * (nm[n / 2 -1] + nm[n / 2]);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
