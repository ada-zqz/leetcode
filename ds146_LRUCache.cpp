class LRUCache {
private:
    list<int> lst;  //在最后放最新使用过的key
    typedef unordered_map<int, pair<int, list<int>::iterator>> umap;  
    //查找迅速; key, <value, pointkey>
    umap mp;
    int vol;
    
public:
    LRUCache(int capacity): vol(capacity){
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if(it == mp.end()) return -1;
        update(it);  //it 是迭代器的指针
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it != mp.end()) {
            update(it);
            it->second.first = value;
        }
        else {
            if(mp.size() == vol) {
                mp.erase(lst.back());  //参数为key
                lst.pop_back();
            }
            lst.push_front(key);
            mp[key] = pair<int, list<int>::iterator>(value, lst.begin());
        }
    }
    
    void update(umap::iterator it) {
        lst.erase(it->second.second);  //参数为list的迭代器
        lst.push_front(it->first);
        it->second.second = lst.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
