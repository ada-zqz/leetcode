class LRUCache {
private:
    struct im {
        int key, val;
        im(int k, int v): key(k), val(v){}
    };
    list<im> lst;  //在最后放最新使用过的item
    typedef unordered_map<int, list<im>::iterator> umap;  //查找迅速
    umap mp;
    int vol;
    
public:
    LRUCache(int capacity): vol(capacity){
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if(it == mp.end()) return -1;
        mp[key] = update(it->second);  //it 是迭代器的指针
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it != mp.end()) {
            mp[key] = update(it->second);
            mp[key]->val = value;
        }
        else {
            if(mp.size() < vol) {
                mp[key] = lst.insert(lst.end(), im(key, value));
            }
            else {
                mp.erase(lst.front().key);
                lst.pop_front();
                mp[key] = lst.insert(lst.end(), im(key, value));
            }
        }
    }
    
    list<im>::iterator update(list<im>::iterator it) {
        list<im>::iterator newit = lst.insert(lst.end(), *it);
        lst.erase(it);
        return newit;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
