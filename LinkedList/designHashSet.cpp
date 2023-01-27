// Link: https://leetcode.com/problems/design-hashset/

// Approach 1: For vector size upto 10^6 [TC: O(N)]

class MyHashSet {
public:
    vector<int> m;
    int siz;
    MyHashSet() {
        siz=1e6+1; // vector size <= 10^6
        m.resize(siz);
    }
    
    void add(int key) {
        if(contains(key)) return;
        m[key] = 1;
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        m[key] = 0;
    }
    
    bool contains(int key) {
        if(m[key]==1) return true;
        else return false;
    }
};

// Approach 2: For vector size beyond 10^6 [TC: O(N)]

class MyHashSet {
public:
    vector<list<int>> m;
    int siz;
    MyHashSet() {
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

    list<int> :: iterator search(int key){
        int i=hash(key);
        return find(m[i].begin(),m[i].end(),key);
    }

    void add(int key) {
        if(contains(key)) return;
        int i=hash(key);
        m[i].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int i=hash(key);
        m[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i=hash(key);
        if(search(key)!=m[i].end()) return true;
        else return false;
    }
};

