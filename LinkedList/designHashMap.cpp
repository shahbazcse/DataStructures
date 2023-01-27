// Link: https://leetcode.com/problems/design-hashmap/

// Approach 1: For vector size upto 10^6 [TC: O(N)]

class MyHashMap {
public:
    vector<int> m;
    int siz;
    MyHashMap() {
        siz=1e6+1; // vector size <= 10^6
        m.resize(siz);
        fill(m.begin(),m.end(),-1); // Initialize vector with -1 value
    }
    
    void put(int key, int value) {
        m[key]=value;
    }
    
    int get(int key) {
        if(m[key]!=-1) return m[key];
        else return -1;
    }
    
    void remove(int key) {
        if(m[key]!=-1) m[key]=-1;
        else return;
    }
};

// Approach 2: For vector size beyond 10^6 [TC: O(N)]

class MyHashMap {
public:
    vector<list<pair<int,int>>> m; // Vector of Doubly LL of Pair (for key,value)
    int siz;
    MyHashMap() {
        siz=1e6+1;
        m.resize(siz);
    }

    int hash(int key){
        return key%siz; // chaining technique
    }

    /* 
        1. Chaining Technique uses modulo opertaor to store larger key value at 
        relatively smaller index.
        3. It uses doubly linked list to store multiple keys at the same index.
        4. It can perform add, remove, delete, search operations easily.
        5. It also avoids collisions when two keys are stored at the same index.
        6. The larger the vector size, the less collision will happen.
    */

    list<pair<int,int>> :: iterator search(int key){
        int i=hash(key);
        list<pair<int,int>> :: iterator it = m[i].begin();
        while(it!=m[i].end()){
            if(it->first==key) return it;
            it++;
        }
        return m[i].end();
    }
    
    void put(int key, int value) {
        int i=hash(key);
        if(search(key)!=m[i].end()) remove(key); // if key already exists
        m[i].push_back({key,value});
    }
    
    int get(int key) {
        int i=hash(key);
        if(search(key)!=m[i].end()){
            list<pair<int,int>> :: iterator it=search(key);
            return it->second;
        }
        else return -1;
    }
    
    void remove(int key) {
        int i=hash(key);
        if(search(key)!=m[i].end()){
            m[i].erase(search(key));
        }
        else return;
    }
};