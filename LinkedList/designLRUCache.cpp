// Link: https://leetcode.com/problems/lru-cache/

// Approach: Using Doubly LL and Map [TC: O(1) / SC: O(capacity)]

class LRUCache {
public:
    unordered_map<int,int> m;
    unordered_map<int,list<int>::iterator> address;
    list<int> cacheList;
    int cap;
    int siz;
    LRUCache(int capacity) {
        cap=capacity;
        siz=0;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1; // if key is not found

        list<int>::iterator it=address[key];
        cacheList.erase(it);
        address.erase(key);

        cacheList.push_front(key);
        address[key]=cacheList.begin();
        
        return m[key];
    }
    
    void put(int key, int value) {
        // if key is found in list, then delete it before updating its value
        if(m.find(key)!=m.end()){
            cacheList.erase(address[key]);
            address.erase(key);
            m.erase(key);
            siz--;
        }

        // if max capacity reached, then remove the least used key from end of list
        if(siz==cap){
            int k=cacheList.back();
            cacheList.pop_back();
            address.erase(k);
            m.erase(k);
            siz--;
        }

        // inserting a new value at 'key' or updating the old value at 'key' with new value 
        siz++;
        cacheList.push_front(key);
        address[key]=cacheList.begin();
        m[key]=value;
    }
};